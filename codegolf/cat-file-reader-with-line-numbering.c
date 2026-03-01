/*

You must do a program that reads a file given in first argument and print it's content to STDOUT and number the lines on the file, the numbers should be followed by a space.
For instance, assuming that your program is named cat, we could write ./cat "myfile.txt" (or execute it with its interpreter)

With myfile.txt:

Hello, world, this
is a file with
multiple characters..0
And the program should output to STDOUT :

1  Hello, world, this
2  is a file with
3  multiple characters..0
The shortest program in bytes win.

For example :

Perl

$r++&print"$r ".$_ while<>

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

void
cat(FILE *ifp, FILE *ofp)
{
	unsigned long n, m;
	int c;

	m = 0;
	n = 1;
	while ((c = fgetc(ifp)) != EOF) {
		if (n != m) {
			fprintf(ofp, "%lu  ", n);
			m = n;
		}

		if (c == '\n')
			n++;

		fputc(c, ofp);
	}
}

int
main(int argc, char *argv[])
{
	FILE *fp;
	int i;

	if (argc < 2)
		cat(stdin, stdout);
	else {
		for (i = 1; i < argc; i++) {
			fp = fopen(argv[i], "rb");
			if (!fp) {
				printf("cat: %s: %s\n", argv[i], strerror(errno));
				continue;
			}
			cat(fp, stdout);
			fclose(fp);
		}
	}
	return 0;
}
