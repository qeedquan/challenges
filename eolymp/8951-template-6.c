/*

Given positive odd integer n. Print the image of size n×n, formed by the asterisk and space characters as shown in the example.

https://static.e-olymp.com/content/8e/8ed26ca170ce84046d1f49fc718ad2a15338011e.jpg

Input
One positive odd integer n (n>1).

Output
Print the image n×n.

Examples

Input #1
5

Answer #1
  *
 * *
*   *
 * *
  *

*/

#include <stdio.h>
#include <stdlib.h>

int
at(int n, int x, int y)
{
	if (x + y == n / 2)
		return '*';
	if (x - y == n / 2)
		return '*';
	if (y - x == n / 2)
		return '*';
	if (y - (n - x - 1) == n / 2)
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

	for (i = 1; i <= 9; i += 2)
		solve(i);
	return 0;
}
