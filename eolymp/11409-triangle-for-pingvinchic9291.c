/*

https://static.eolymp.com/content/u3/u31mq1hs256m78r76ars7meo2c.jpg

Given a positive integer n, print an image that has 2⋅n−1 rows and n columns, formed by the space character and the character *, as shown in the example.

Input
A positive integer n (n>1).

Output
Print the image (2⋅n−1)×n.

Examples

Input #1
5

Answer #1
*
**
* *
*  *
*   *
*  *
* *
**
*

*/

#include <stdio.h>

int
at(int h, int x, int y)
{
	if (x == 0 || x == y)
		return '*';
	if (y > h / 2 && x == h - y - 1)
		return '*';
	return ' ';
}

void
solve(int n)
{
	int x, y, w, h;

	printf("n=%d\n", n);
	w = n;
	h = (2 * n) - 1;
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("%c", at(h, x, y));
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 0; i <= 10; i++)
		solve(i);

	return 0;
}
