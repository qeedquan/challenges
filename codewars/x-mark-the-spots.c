/*

Write a function x(n) that takes in a number n and returns an nxn array with an X in the middle. The X will be represented by 1's and the rest will be 0's.
E.g.

x(5) === [[1, 0, 0, 0, 1],
          [0, 1, 0, 1, 0],
          [0, 0, 1, 0, 0],
          [0, 1, 0, 1, 0],
          [1, 0, 0, 0, 1]];

x(6) === [[1, 0, 0, 0, 0, 1],
          [0, 1, 0, 0, 1, 0],
          [0, 0, 1, 1, 0, 0],
          [0, 0, 1, 1, 0, 0],
          [0, 1, 0, 0, 1, 0],
          [1, 0, 0, 0, 0, 1]];

*/

#include <stdio.h>

void
X(int n, int m[n][n])
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			m[i][j] = 0;
			if (i == j || i + j == n - 1)
				m[i][j] = 1;
		}
	}
}

void
P(int n, int m[n][n])
{
	int i, j;

	printf("N=%d\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void
test(int n)
{
	int m[n][n];

	X(n, m);
	P(n, m);
}

int
main()
{
	test(5);
	test(6);

	return 0;
}
