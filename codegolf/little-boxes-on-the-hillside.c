/*

There's a satirical song called Little Boxes, originally by Malvina Reynolds, about suburban sprawl that has lyrics as follows:

Little boxes on the hillside,
Little boxes made of ticky-tacky,
Little boxes on the hillside,
Little boxes all the same.
There's a green one and a pink one
And a blue one and a yellow one,
And they're all made out of ticky-tacky
And they all look just the same.

Your job here is, given an integer input n>1 that represents the size of the house, output the four "little boxes" using the following colors (in 0xRRGGBB notation):

Green -- 0x00FF00
Pink --- 0xFF00FF (technically magenta)
Blue --- 0x0000FF
Yellow - 0xFFFF00
If your particular console doesn't have these exact colors, you may use the closest available (e.g., ANSI escape codes).

The houses are constructed with n _ representing the floor and roofline. They are surrounded by n/2 (round-up) | characters representing the walls. The roofs are always 2 high and are two / on the left edge, two \ on the right edge, and n-2 - representing the roof peak. As the houses get larger, the comparative size of the roof gets smaller; this is intended.

Here's a house of size 2:

 /\
/__\
|__|
Here's size 3:

 /-\
/___\
|   |
|___|
Here's size 7:

 /-----\
/_______\
|       |
|       |
|       |
|_______|
Thus given an input of 7, output four houses of size 7 as described above, with the first one in green, the second in pink (magenta), the third in blue, and the fourth in yellow. Output of the colors in that order is important.

Example picture of size 3:

https://i.sstatic.net/tLaDB.png

Rules
The houses can be horizontal or vertical so long as there is a clear separation between them.
Leading/trailing newlines or other whitespace are optional, provided that the houses line up appropriately.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Output can be to the console, saved as an image, etc.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#include <stdio.h>
#include <stdarg.h>

void
linef(const char *fmt, ...)
{
	int c, i, n;
	va_list ap;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		switch (*fmt) {
		case '-':
		case '_':
		case 's':
			c = *fmt;
			if (c == 's')
				c = ' ';
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				printf("%c", c);
			break;

		default:
			putchar(*fmt);
			break;
		}
	}
	va_end(ap);
	printf("\n");
}

void
hillbox(int n)
{
	static const char *pal[] = {
		"\033[32m",
		"\033[35m",
		"\033[34m",
	};

	int x, y;

	printf("n=%d\n", n);
	if (n < 2)
		return;

	for (y = 0; y < 3; y++) {
		printf("%s", pal[y]);
		linef(" /-\\", n - 2);
		linef("/_\\", n);
		for (x = 0; x < (n >> 1) + (n & 1); x++)
			linef("|s|", n);
		linef("|_|", n);
		printf("\n");
	}
	printf("\033[0m");
}

int
main()
{
	hillbox(2);
	hillbox(3);
	hillbox(7);
	return 0;
}
