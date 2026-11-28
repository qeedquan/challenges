/*

Fill an n×n array in the following way: the secondary diagonal contains zeros, all cells above it contain twos, and all cells below it contain ones.

Input
One positive integer n (n≤20).

Output
Print the array filled as described above.

Examples

Input #1
3

Answer #1
220
201
011

*/

#include <stdio.h>

void
solve(int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (j == n - i - 1)
				printf("%d", 0);
			else if (j > n - i - 1)
				printf("%d", 1);
			else
				printf("%d", 2);
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	solve(3);

	return 0;
}
