/*

This is a slightly different code golf from the usual problems. I'm forced to work with Java at my workplace and I'm increasingly annoyed at what I must do to read a file into memory to a String so I can operate on it in a normal way.

The golf is this: What is the shortest possible function to dump a file into your language's smallest data structure of characters?

Java would be char[], C++ would be char*, Haskell would be a [Char], etc. I don't care about complete programs or main() functions, but you do have to open and close the file.

inb4 Unix's >

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>

void *
mmapfile(const char *name, size_t *size)
{
	struct stat st;
	void *data;
	int fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		goto error;

	if (fstat(fd, &st) < 0)
		goto error;

	data = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (data == MAP_FAILED)
		goto error;

	*size = st.st_size;

	if (0) {
	error:
		data = NULL;
	}

	if (fd >= 0)
		close(fd);

	return data;
}

void
hexdump(void *data, size_t size)
{
	unsigned char *ptr;
	size_t i;

	ptr = data;
	for (i = 0; i < size; i++) {
		printf("%02x ", ptr[i]);
		if ((i & 7) == 7)
			printf("\n");
	}
	printf("\n");
}

int
main(int argc, char *argv[])
{
	unsigned char *data;
	size_t size;

	if (argc < 2) {
		fprintf(stderr, "usage: <file>\n");
		return 1;
	}

	data = mmapfile(argv[1], &size);
	if (!data)
		err(1, "mmap");

	hexdump(data, size);
	munmap(data, size);

	return 0;
}
