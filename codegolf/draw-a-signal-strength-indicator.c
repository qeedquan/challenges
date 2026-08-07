/*

Given the signal level L in the range 0-4. Your program should draw the following ASCII art.

When L=0:

               ....
               ....
          .... ....
          .... ....
     .... .... ....
     .... .... ....
.... .... .... ....
.... .... .... ....
.... .... .... ....

When L=1:

               ....
               ....
          .... ....
          .... ....
     .... .... ....
     .... .... ....
oooo .... .... ....
oooo .... .... ....
oooo .... .... ....

When L=2:

               ....
               ....
          .... ....
          .... ....
     oooo .... ....
     oooo .... ....
oooo oooo .... ....
oooo oooo .... ....
oooo oooo .... ....

And etc. You can change the characters o and . to others, it's up to you. Trailing spaces are allowed.

This is a code-golf challenge so the shortest solution wins.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
indicator(unsigned n)
{
	static const char *sig[] = {
		"               ....",
		"               ....",
		"          .... ....",
		"          .... ....",
		"     .... .... ....",
		"     .... .... ....",
		".... .... .... ....",
		".... .... .... ....",
		".... .... .... ....",
	};

	unsigned x, y;
	int c;

	printf("n=%d\n", n);
	for (y = 0; y < nelem(sig); y++) {
		for (x = 0; sig[y][x]; x++) {
			c = sig[y][x];
			if (c == '.' && x / 5 < n)
				c = 'o';
			putchar(c);
		}
		putchar('\n');
	}
	putchar('\n');
}

int
main()
{
	unsigned i;

	for (i = 0; i <= 4; i++)
		indicator(i);

	return 0;
}
