/*

To celebrate the 2497th anniversary of the Greek victory at Salamis in 480 BC. Draw the lambda blazon.

The lambda blazon was the lambda painted on greek shields like so:

https://i.stack.imgur.com/13rw9.jpg

Puzzle: Given a positive odd integer n, produce an ascii art image of the above shield.

Specifications:

n=1:

( /\ )
n=3:

(   /\   )
|  /  \  |
( /    \ )
n=5

(     /\     )
|    /  \    |
|   /    \   |
|  /      \  |
( /        \ )
Graph: n=3

          2|   (   /\   )
y-axis    1|   |  /  \  |
          0|   ( /    \ )
               ___________
               0123456789

                 x-axis
Description:

There should be exactly n \ characters and n / characters. The /s and \s should not touch the edge of the shield. The bottom and top corners of the shield will be denoted with a ( or ) unless n=1 where there will be one ) and one (. There will always be one space between the bottom corners and the lambda, increasing by 1 with the y axis until y + 1 == n. Non corners of the shield side will be denoted with |. There is no shield top.

*/

#include <stdio.h>

int
at(int x, int y, int w, int h)
{
	if (x == 0)
		return (y == 0 || y == h - 1) ? '(' : '|';

	if (x == w - 1)
		return (y == 0 || y == h - 1) ? ')' : '|';

	if (x == h - y + 1)
		return '/';

	if (w - x == h - y + 2)
		return '\\';

	return ' ';
}

void
lambdablazon(int n)
{
	int x, y, w, h;

	w = 2 * (n + 2);
	h = n;
	printf("n=%d\n", n);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("%c", at(x, y, w, h));
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 1; i <= 5; i++)
		lambdablazon(i);

	return 0;
}
