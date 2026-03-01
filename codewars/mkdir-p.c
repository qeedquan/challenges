/*

Write a synchronous function that makes a directory and recursively makes all of its parent directories as necessary.

A directory is specified via a sequence of arguments which specify the path. For example:

mkdirp('/','tmp','made','some','dir')

...will make the directory /tmp/made/some/dir.

Like the shell command mkdir -p, the function you program should be idempotent if the directory already exists.

HINT:

In javascript/coffescript, you will want to require('fs') and use functions in that library.

Documentation on fs. ( http://nodejs.org/api/fs.html )

In python, you will want to use the os module and os.path

Documentation on os module ( https://docs.python.org/2/library/os.html )
Documentation on os.path module ( https://docs.python.org/2/library/os.path.html )

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int
trymkdir(const char *path, mode_t mode)
{
	struct stat st;

	errno = 0;
	if (mkdir(path, mode) == 0)
		return 0;

	if (errno != EEXIST)
		return -1;

	if (stat(path, &st) < 0)
		return -1;

	if (!S_ISDIR(st.st_mode)) {
		errno = ENOTDIR;
		return -1;
	}

	errno = 0;
	return 0;
}

int
mkdirp(const char *pathname)
{
	char *ptr, *path;
	int ret;
	mode_t mode;

	errno = 0;
	ret = 0;
	path = strdup(pathname);
	if (!path)
		goto error;

	mode = 0777;
	for (ptr = path + 1; *ptr; ptr++) {
		if (*ptr == '/') {
			*ptr = '\0';
			if (trymkdir(path, mode) != 0)
				goto error;
			*ptr = '/';
		}
	}

	if (trymkdir(path, mode) != 0)
		goto error;

	if (0) {
	error:
		ret = -1;
	}

	free(path);
	return ret;
}

void
usage()
{
	fprintf(stderr, "usage: <dir> ...\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
		usage();

	for (i = 1; i < argc; i++)
		mkdirp(argv[i]);

	return 0;
}
