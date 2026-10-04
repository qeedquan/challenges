/*

An n×n Latin Square is a grid containing exactly n distinct values where the values in each row and column are distinct. For example,

ACBBACCBA

is a Latin square as no row or column contains a repeated value.

You are to take a positive integer n as input and output an n×n Latin Square. The values can be any n distinct values, and do not have to be consistent for different n.
Your program should be consistent and deterministic, so running it with the same input should always produce the same output.

You may output in any reasonable manner, including a flat array consisting of n^2 values, or as a list of n lists, each containing n values. You may input and output in any convenient method

This is code-golf, so the shortest code in bytes wins.

Test cases
These are just some possible outputs, your program may differ so long as the output is correct

1 [[1]]
2 [[1, 2], [2, 1]]
3 [[1, 2, 3], [2, 3, 1], [3, 1, 2]]
4 [[1, 2, 3, 4], [2, 1, 4, 3], [3, 4, 1, 2], [4, 3, 2, 1]]
5 [[1, 2, 3, 4, 5], [2, 3, 5, 1, 4], [3, 5, 4, 2, 1], [4, 1, 2, 5, 3], [5, 4, 1, 3, 2]]

*/

#include <stdio.h>

void
dump(size_t n, int m[n][n])
{
	size_t i, j;

	printf("n=%zu\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

/*

@xnor

Since the challenge allows a flat list of n*n outputs, we make do mapping k=0, 1, ... n*n-1 to the corresponding entry with (k+k/n)%n.
We can get this by adding the row index k/n and column k%n and reducing modulo n, and removing the redundant inner %n. We could also do k*-~n/n%n.

*/

void
latinsquare(size_t n, int m[n][n])
{
	size_t i, j, k;

	for (i = k = 0; i < n; i++) {
		for (j = 0; j < n; j++, k++)
			m[i][j] = (k + (k / n)) % n;
	}
}

void
test(size_t n)
{
	int m[n][n];

	latinsquare(n, m);
	dump(n, m);
}

int
main()
{
	size_t i;

	for (i = 0; i <= 8; i++)
		test(i);

	return 0;
}
