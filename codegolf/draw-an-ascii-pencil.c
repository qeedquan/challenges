/*

Task is pretty simple. Your program should take a number N from 1 to 20 and draw the following ASCII art.

When N=1:

_____
| | |
| | |
| | |
| | |
| | |
| | |
| | |
|_|_|
\   /
 \-/
  v
When N=2:

_______
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|__|__|
\     /
 \---/
  \ /
   v
When N=3:

_________
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|___|___|
\       /
 \-----/
  \   /
   \ /
    v

And etc. Trailing spaces are allowed.

This is a code-golf challenge so the shortest solution wins.

*/

#include <stdio.h>

void
pencil(int n)
{
	int x, y, w, h;

	if (n < 1)
		return;

	w = (2 * n) + 3;
	h = 8 * n;

	printf("N=%d\n", n);
	for (x = 0; x < w; x++)
		putchar('_');
	puts("");

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			if (!(x % (n + 1)))
				putchar('|');
			else if (y == h - 1)
				putchar('_');
			else
				putchar(' ');
		}
		puts("");
	}

	for (y = 0; y < n + 2; y++) {
		for (x = 0; x < w; x++) {
			if (x == y && y == n + 1)
				putchar('v');
			else if (x == y)
				putchar('\\');
			else if (w - x - 1 == y)
				putchar('/');
			else if (x > y && x < w - 1 && y == 1)
				putchar('-');
			else
				putchar(' ');
		}
		puts("");
	}

	puts("\n");
}

int
main(void)
{
	int i;

	for (i = 1; i <= 20; i++)
		pencil(i);

	return 0;
}
