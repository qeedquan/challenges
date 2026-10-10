/*

Create a program that will take any string and write it out to a text file, reversed.

input: "hello!"

output: "!olleh"

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int
revout(const char *name, const char *str)
{
	FILE *fp;
	size_t len;

	fp = fopen(name, "w");
	if (!fp)
		return -errno;

	for (len = strlen(str); len > 0; len--)
		fputc(str[len - 1], fp);

	fclose(fp);
	return 0;
}

int
main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage: file string\n");
		exit(2);
	}

	if (revout(argv[1], argv[2]) < 0)
		printf("%s: %s\n", argv[1], strerror(errno));

	return 0;
}
