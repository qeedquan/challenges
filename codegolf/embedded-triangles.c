/*

Your task: given an integer n, output an embedded triangle to the nth depth.

Standard methods of input and output, input in any convenient format, output should be as a string. Examples are 0-indexed, you can use 1-indexed if you want. Standard loopholes apply

The left and right sides of each figure is 2^n, when 0 indexed. The top is twice that.

Examples:

n=0
--
\/

n=1
----
\/ /
 \/

n=2
--------
\/ /   /
 \/   /
  \  /
   \/

This is code-golf, so shortest code wins!

This is NOT a duplicate of the Embedded Hexagons! challenge. I don't think any answers from that question could be trivially copied over to this one.

*/

#include <stdio.h>

int
ispow2(int n)
{
	return n > 0 && !(n & (n - 1));
}

void
embtri(int n)
{
	int x, y, w, h;

	w = 1 << (n + 1);
	h = 1 << n;

	printf("n=%d\n", n);
	for (x = 0; x < w; x++)
		printf("-");
	printf("\n");

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			if (x == y)
				printf("\\");
			else if (x > y && ispow2(x + y + 1))
				printf("/");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 0; i <= 5; i++)
		embtri(i);

	return 0;
}
