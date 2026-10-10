/*

Your task is to output a square sandbox of size n+2 with / characters in the corners and | for the sides, and - for the top, with n**2 layers of sand (.) overflowing out of the sandbox of width n+2

Testcases
1
->
/-/
|.|
/./
...

2
->
/--/
|..|
|..|
/../
....
....
....
....

3
->
/---/
|...|
|...|
|...|
/.../
.....
.....
.....
.....
.....
.....
.....
.....
.....

Trailing spaces and newlines are allowed

This is code-golf, so shortest code wins!

*/

#include <stdio.h>

void
sandbox(unsigned n)
{
	unsigned c, x, y, w, h;

	w = h = n + 2;
	printf("n=%d\n", n);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			c = '.';
			if (y == 0)
				c = (x == 0 || x == w - 1) ? '/' : '-';
			else if (y == h - 1 && (x == 0 || x == w - 1))
				c = '/';
			else if (x == 0 || x == w - 1)
				c = '|';

			putchar(c);
		}
		putchar('\n');
	}

	h = n * n;
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			putchar('.');
		putchar('\n');
	}
	putchar('\n');
}

int
main(void)
{
	int i;

	for (i = 1; i <= 5; i++)
		sandbox(i);

	return 0;
}
