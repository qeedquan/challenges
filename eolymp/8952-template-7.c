/*

https://static.e-olymp.com/content/16/164dd52de01c4d92dcffe164dd13d3517d441759.jpg

Given positive odd integer n. Print the image of size n×n, formed by the asterisk and space characters as shown in the example.

Input
One positive odd integer n (n>1).

Output
Print the image n×n.

Examples

Input #1
5

Answer #1
  *
 ***
*****
 ***
  *

*/

#include <stdio.h>
#include <stdlib.h>

int
at(int n, int x, int y)
{
	int f;

	f = 0;
	if (x + y >= n / 2)
		f |= 0x1;
	if (x - y <= n / 2)
		f |= 0x2;
	if (y - x <= n / 2)
		f |= 0x4;
	if (y - (n - x - 1) <= n / 2)
		f |= 0x8;
	return (f == 0xf) ? '*' : ' ';
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
