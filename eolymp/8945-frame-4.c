/*

For the given positive integers n and m print the rectangular frame of size n×m from stars, filled with spaces as shown in the sample.

Input
Two positive integers n and m (n,m≤100).

Output
Print the rectangular frame of size n×m.

Examples

Input #1
4 7

Answer #1
*******
*     *
*     *
*******

*/

#include <stdio.h>

int
at(int x, int y, int w, int h)
{
	if (x == 0 || y == 0 || x == w - 1 || y == h - 1)
		return '*';
	return ' ';
}

void
frame(int n, int m)
{
	int x, y;

	for (y = 0; y < n; y++) {
		for (x = 0; x < m; x++)
			printf("%c", at(x, y, m, n));
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	frame(4, 7);
	return 0;
}
