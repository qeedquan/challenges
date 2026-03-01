/*

Write a program that converts a "plain" .pgm file passed from stdin to an ASCII representation easily viewable in a terminal. If you're too lazy to read through the specification, the format should be simple enough to reverse-engineer from an example file:

P2
# feep.pgm
24 7
15
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
The top line, P2, is there to identify the file as a plain .pgm file.

Lines with a # in front of them are comments, and should be ignored.

The first two numbers in the file are the width and height.

The third number, 15 here, is the maximum grayscale value in the image: here, this means 15 is full white, and lower numbers are darker, 0 being pure black.

Thereafter, a (width x height) grid specifying the image itself follows.

Your program should use ASCII symbols to represent different grayscale values. Assuming the text is black on a white background, you could use a gradient like this one:

" .:;+=%$#"
Converted, the example image would look something like this:

 ....  ;;;;  ====  ####
 .     ;     =     #  #
 ...   ;;;   ===   ####
 .     ;     =     #
 .     ;;;;  ====  #

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
eatline(FILE *fp)
{
	while (fgetc(fp) != '\n')
		;
}

void
eatcom(FILE *fp)
{
	int c;

	c = fgetc(fp);
	if (c == '#')
		eatline(fp);
	else
		ungetc(c, fp);
}

void
pic(FILE *fp)
{
	int w, h, d;
	int x, y;
	int c;

	eatline(fp);
	eatcom(fp);
	if (fscanf(fp, "%d %d\n", &w, &h) != 2)
		return;
	eatcom(fp);
	if (fscanf(fp, "%d\n", &d) != 1)
		return;
	eatcom(fp);

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			if (fscanf(fp, "%d", &c) != 1)
				return;
			printf("\x1b[%d;%dm█\x1b[m", c / 8, (c % 8) + 30);
		}
		putchar('\n');
	}
}

void
usage(void)
{
	fprintf(stderr, "usage: <pgm>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		usage();

	fp = fopen(argv[1], "rb");
	if (!fp)
		fatal("Failed to open file: %s", strerror(errno));

	pic(fp);
	fclose(fp);

	return 0;
}
