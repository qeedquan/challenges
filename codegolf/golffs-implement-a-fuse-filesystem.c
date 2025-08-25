/*

Implement a FUSE filesystem in minimum bytes.

Your program must do three things:

Mounting the virtual filesystem to a directory
Handling requests to enumerate files in that directory (showing one file)
Handling requests to read the file in that directory
Rules:

ls (a system program, you don't need to implement it) must show hello.txt file (other unrelated files can also be visible, as well as errors may be printed). hello.txt must be exact, 68 65 6c 6c 6f 2e 74 78 74 in hex).
cat (a system program) pointed to the file should output Hello, world. (punctuation, case and end of lines may differ. A bunch of zero bytes can also slip unnoticed). It can also be cat m/hello.txt; echo if there is no trailing newline.
It must be actual FUSE filesystem, not just a regular file created by your program. For example, freezing your program should freeze the hello.txt file (cat and ls would hang). Creating a socket instead of mounting FUSE filesystem isn't an allowed workaround. Your mounted filesystem should be visible in /proc/mounts (or platform analogue).
For 200 bytes penalty, you may depend on libfuse or use it's header files (or depend on the appropriate FUSE binding in some other language)
Detaching is optional
You program may be platform-specific. Somebody else on that platform should check and write a comment that it works (or not)
Your program can't be a kernel module (fuse.ko is the involved kernel module on Linux and is considered a part of environtment, not your program)
Your program can access /dev/fuse (or platform analogue) directly. It may require root access (or changing permissions) for it if needed. It can also rely on fusermount for the mounting step (like the example below). Whether using fusermount for mounting carry penalty or not I have not decided yet (because of I don't know implementation details enough): if the rest feels like talking to kernel directly then it should not be a problem.
Additional compilation and invocation parameters are added to the score. A directory to be mounted may be specified as a free (non-penalty) parameter or may be just hardcoded (like m)
Example (directly based on official hello.c):

#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

static const char *hello_str = "Hello, world\n";
static const char *hello_path = "/hello.txt";

static int hello_getattr(const char *path, struct stat *stbuf)
{
    int res = 0;

    memset(stbuf, 0, sizeof(struct stat));
    if (strcmp(path, "/") == 0) {
        stbuf->st_mode = S_IFDIR | 0755;
        stbuf->st_nlink = 2;
    } else if (strcmp(path, hello_path) == 0) {
        stbuf->st_mode = S_IFREG | 0444;
        stbuf->st_nlink = 1;
        stbuf->st_size = strlen(hello_str);
    }
    return res;
}

static int hello_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
             off_t offset, struct fuse_file_info *fi)
{
    filler(buf, hello_path + 1, NULL, 0);
    return 0;
}

static int hello_open(const char *path, struct fuse_file_info *fi)
{
    return 0;
}

static int hello_read(const char *path, char *buf, size_t size, off_t offset,
              struct fuse_file_info *fi)
{
    size_t len;
    (void) fi;
    if(strcmp(path, hello_path) != 0)
        return -ENOENT;

    len = strlen(hello_str);
    if (offset < len) {
        if (offset + size > len)
            size = len - offset;
        memcpy(buf, hello_str + offset, size);
    } else
        size = 0;

    return size;
}

static struct fuse_operations hello_oper = {
    .getattr    = hello_getattr,
    .readdir    = hello_readdir,
    .open        = hello_open,
    .read        = hello_read,
};

int main(int argc, char *argv[])
{
    return fuse_main(argc, argv, &hello_oper, NULL);
}
$ gcc -D_FILE_OFFSET_BITS=64 golffs.c -lfuse -o golffs
$ ./golffs  m     # uses fusermount under the hood
$ ls m
hello.txt
$ cat m/hello.txt 
Hello, world
$ fusermount -u m
Score of the example: 1974 + 29 (compilation parameters) + 0 (invocation parameters) + 200 (penalty) = 2203

*/

#define FUSE_USE_VERSION 35

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <fuse.h>

static struct options {
	const char *filename;
	const char *contents;
	int show_help;
} options;

#define OPTION(t, p)                              \
	{                                         \
		t, offsetof(struct options, p), 1 \
	}

static const struct fuse_opt option_spec[] = {
    OPTION("--name=%s", filename),
    OPTION("--contents=%s", contents),
    OPTION("-h", show_help),
    OPTION("--help", show_help),
    FUSE_OPT_END};

static void *
hello_init(struct fuse_conn_info *, struct fuse_config *cfg)
{
	cfg->kernel_cache = 1;
	return NULL;
}

static int
hello_getattr(const char *path, struct stat *stbuf, struct fuse_file_info *)
{
	int res;

	res = 0;
	memset(stbuf, 0, sizeof(struct stat));
	if (strcmp(path, "/") == 0) {
		stbuf->st_mode = S_IFDIR | 0755;
		stbuf->st_nlink = 2;
	} else if (strcmp(path + 1, options.filename) == 0) {
		stbuf->st_mode = S_IFREG | 0444;
		stbuf->st_nlink = 1;
		stbuf->st_size = strlen(options.contents);
	} else
		res = -ENOENT;

	return res;
}

static int
hello_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t, struct fuse_file_info *, enum fuse_readdir_flags)
{
	if (strcmp(path, "/") != 0)
		return -ENOENT;

	filler(buf, ".", NULL, 0, 0);
	filler(buf, "..", NULL, 0, 0);
	filler(buf, options.filename, NULL, 0, 0);

	return 0;
}

static int
hello_open(const char *path, struct fuse_file_info *fi)
{
	if (strcmp(path + 1, options.filename) != 0)
		return -ENOENT;

	if ((fi->flags & O_ACCMODE) != O_RDONLY)
		return -EACCES;

	return 0;
}

static int
hello_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *)
{
	size_t len;

	if (strcmp(path + 1, options.filename) != 0)
		return -ENOENT;

	len = strlen(options.contents);
	if (offset < len) {
		if (offset + size > len)
			size = len - offset;
		memcpy(buf, options.contents + offset, size);
	} else
		size = 0;

	return size;
}

static const struct fuse_operations hello_oper = {
    .init = hello_init,
    .getattr = hello_getattr,
    .readdir = hello_readdir,
    .open = hello_open,
    .read = hello_read,
};

static void
show_help(const char *progname)
{
	printf("usage: %s [options] <mountpoint>\n\n", progname);
	printf("File-system specific options:\n"
	       "    --name=<s>          Name of the \"hello\" file\n"
	       "                        (default: \"hello\")\n"
	       "    --contents=<s>      Contents \"hello\" file\n"
	       "                        (default \"Hello, World!\\n\")\n"
	       "\n");
}

int
main(int argc, char *argv[])
{
	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);
	int ret;

	options.filename = strdup("hello");
	options.contents = strdup("Hello World!\n");

	if (fuse_opt_parse(&args, &options, option_spec, NULL) == -1)
		return 1;

	if (options.show_help) {
		show_help(argv[0]);
		assert(fuse_opt_add_arg(&args, "--help") == 0);
		args.argv[0][0] = '\0';
	}

	ret = fuse_main(args.argc, args.argv, &hello_oper, NULL);
	fuse_opt_free_args(&args);
	return ret;
}
