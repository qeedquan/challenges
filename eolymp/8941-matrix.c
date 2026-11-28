/*

Two positive integers n and m are given.
Print the matrix that consists of n lines and m columns, filled with positive integers from 1 to n⋅m, as shown in the sample.

Input
Two positive integers n and m (1≤n,m≤100).

Output
Print the required matrix.

Examples
Input #1
2 3

Answer #1
1 2 3
4 5 6

*/

#include <stdio.h>

void
solve(int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", (i * m) + j + 1);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	solve(2, 3);

	return 0;
}
