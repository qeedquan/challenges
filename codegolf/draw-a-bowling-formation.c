/*

Your goal is to display ASCII art of a formation in ten-pin bowling where only some of the pins remain. Fewest bytes wins.

The tens pins are in a triangular formation:

O O O O
 O O O
  O O
   O
Pins are labelled from 1 to 10 as:

7 8 9 10
 4 5 6
  2 3
   1
Drawing pins as O and missing pins as ., the formation 1 3 5 6 9 10 is:

. . O O
 . O O
  . O
   O
Input:

A space-separated string that lists a nonempty subset of the numbers 1 though 10 in order.

Output:

Print the corresponding formation or output it as a string with linebreaks.

The formation should be flush with the left of the screen. Any whitespace is fine as long as the visible image is correct. Empty lines before and after are fine too.

Test cases:

>> 1 2 3 4 5 6 7 8 9 10

O O O O
 O O O
  O O
   O

>> 7 10

O . . O
 . . .
  . .
   .

>> 3 5 7 9 10

O . O O
 . O .
  . O
   .

>> 1

. . . .
 . . .
  . .
   O

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
parse(const char *s)
{
	const char *p;
	char *ep;
	unsigned b;
	long v;

	b = 0;
	for (p = s; *p; p = ep) {
		v = strtol(p, &ep, 10);
		if (!(1 <= v && v <= 10))
			break;

		b |= (1 << v);
	}
	return b;
}

void
draw(const char *s, unsigned b)
{
	static const char lut[4][8] = {
	    "7 8 9 X",
	    " 4 5 6 ",
	    "  2 3  ",
	    "   1   ",
	};

	unsigned x, y, v;
	int c;

	printf(">> %s\n", s);
	for (y = 0; y < nelem(lut); y++) {
		for (x = 0; lut[y][x]; x++) {
			v = 0;
			if (isdigit(lut[y][x]))
				v = lut[y][x] - '0';
			else if (lut[y][x] == 'X')
				v = 10;

			if (b & (1 << v))
				c = 'O';
			else if (!isspace(lut[y][x]))
				c = '.';
			else
				c = ' ';

			putchar(c);
		}
		puts("");
	}
	puts("");
}

void
bowls(const char *s)
{
	draw(s, parse(s));
}

int
main(void)
{
	bowls("1 2 3 4 5 6 7 8 9 10");
	bowls("7 10");
	bowls("3 5 7 9 10");
	bowls("1");

	return 0;
}
