/*

Description
We are going to encrypt and decrypt with a mirror field.

It works like this:

We align letters to a mirror field:

 ab
A \c
B\ d
 CD
Every letter has now a mirror image

For example A has as mirror image D

A-\
  |
  D
The / and \ act as a mirror that will turn the line 90 degrees like you would if you had a laserpointer pointed to a mirror.

The full letter grid will look like this (without the seperators):

 |a|b|c|d|e|f|g|h|i|j|k|l|m|
-----------------------------
A| | | | | | | | | | | | | |n
-----------------------------
B| | | | | | | | | | | | | |o
-----------------------------
C| | | | | | | | | | | | | |p
-----------------------------
D| | | | | | | | | | | | | |q
-----------------------------
E| | | | | | | | | | | | | |r
-----------------------------
F| | | | | | | | | | | | | |s
-----------------------------
G| | | | | | | | | | | | | |t
-----------------------------
H| | | | | | | | | | | | | |u
-----------------------------
I| | | | | | | | | | | | | |v
-----------------------------
J| | | | | | | | | | | | | |w
-----------------------------
K| | | | | | | | | | | | | |x
-----------------------------
L| | | | | | | | | | | | | |y
-----------------------------
M| | | | | | | | | | | | | |z
-----------------------------
 |N|O|P|Q|R|S|T|U|V|W|X|Y|Z|
Formal Inputs & Outputs
Input description
You'll get a grid of 13 by 13 with mirrors and a word.

   \\  /\
            \
   /
      \     \
    \
  /      /
\  /      \
     \
\/
/
          \
    \/
   /       /
TpnQSjdmZdpoohd
Output description
Return the encrypted word

DailyProgrammer
Bonus
Use the mirrors as a encryption key file and make you program encrypt in realtime (as you type)

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

Edit
Thanks to you all for pointing out the typo. Fixed it now.

Special thanks to u/skeeto to provide us with an animated version http://i.imgur.com/uML0tJK.gif

*/

// Ported from @skeeto solution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
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
char_to_border(char c, int *x, int *y, int *dx, int *dy)
{
	if (c >= 'A' && c <= 'M') {
		*x = 0;
		*y = c - 'A';
		*dx = 1;
		*dy = 0;
	} else if (c >= 'N' && c <= 'Z') {
		*x = c - 'N';
		*y = 12;
		*dx = 0;
		*dy = -1;
	} else if (c >= 'a' && c <= 'm') {
		*x = c - 'a';
		*y = 0;
		*dx = 0;
		*dy = 1;
	} else if (c >= 'n' && c <= 'z') {
		*x = 12;
		*y = c - 'n';
		*dx = -1;
		*dy = 0;
	}
}

char
border_to_char(int x, int y)
{
	if (x < 0)
		return 'A' + y;
	else if (y < 0)
		return 'a' + x;
	else if (x > 12)
		return 'n' + y;
	else if (y > 12)
		return 'N' + x;
	return 0;
}

void
reflect(char m, int *dx, int *dy)
{
	int tmp;

	if (m == '/') {
		tmp = *dx;
		*dx = -*dy;
		*dy = -tmp;
	} else if (m == '\\') {
		tmp = *dx;
		*dx = *dy;
		*dy = tmp;
	}
}

char
mirror(char grid[16][16], int c)
{
	int x, y;
	int dx, dy;

	char_to_border(c, &x, &y, &dx, &dy);
	while (x >= 0 && y >= 0 && x <= 12 && y <= 12) {
		reflect(grid[y][x], &dx, &dy);
		x += dx;
		y += dy;
	}
	return border_to_char(x, y);
}

int
load(const char *name, char grid[16][16], char *buf, size_t len)
{
	FILE *fp;
	int i;

	memset(grid, 0, 16 * 16);
	*buf = '\0';

	fp = fopen(name, "rb");
	if (!fp)
		return -errno;

	for (i = 0; i < 13; i++)
		fgets(grid[i], 16, fp);
	fgets(buf, len, fp);
	fclose(fp);

	return 0;
}

void
decrypt(char grid[16][16], const char *enc, char *dec)
{
	size_t i;

	for (i = 0; enc[i]; i++) {
		dec[i] = enc[i];
		if (isalpha(dec[i]))
			dec[i] = mirror(grid, dec[i]);
	}
	dec[i] = '\0';
}

int
main(int argc, char *argv[])
{
	char grid[16][16];
	char enc[256];
	char dec[256];

	if (argc < 2)
		fatal("usage: <input>");

	if (load(argv[1], grid, enc, sizeof(enc)) < 0)
		fatal("Failed to load file: %s", strerror(errno));

	decrypt(grid, enc, dec);
	printf("%s", dec);

	return 0;
}
