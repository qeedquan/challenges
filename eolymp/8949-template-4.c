/*

Given positive odd integer n. Print the image of size n×n, formed by the asterisk and space characters as shown in the example.

https://static.e-olymp.com/content/4a/4acb32d2503757552599b1a9224e6b4b7f502663.jpg

Input
One positive odd integer n (n>1).

Output
Print the image n×n.

Examples

Input #1
5

Answer #1
*****
 ***
  *
 ***
*****

*/

#include <stdio.h>

int
at(int n, int x, int y)
{
	if (x <= n / 2) {
		if (y <= x || y >= n - x - 1)
			return '*';
		return ' ';
	}
	if (y <= n - x - 1 || y >= x)
		return '*';
	return ' ';
}

void
solve(int n)
{
	int x, y;

	printf("n=%d\n", n);
	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++)
			printf("%c", at(n, x, y));
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 1; i <= 11; i += 2)
		solve(i);
	return 0;
}
