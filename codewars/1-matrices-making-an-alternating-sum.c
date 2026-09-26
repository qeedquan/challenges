/*

We have a matrix of integers with m rows and n columns.

We want to calculate the total sum for the matrix.

The name "alternating sum" of the title is due to the sign of the terms that changes from one term to its contiguous one and so on.

Let's see an example:

matrix = [[1, 2, 3], [-3, -2, 1], [3, - 1, 2]]

total_sum = (1 - 2 + 3) + [-(-3) + (-2) - 1] + [3 - (-1) + 2] = 2 + 0 + 6 = 8

You may be given matrixes with their dimensions between these values:10 < m < 300 and 10 < n < 300.

More example cases in the Example Test Cases. Enjoy it!!

*/

#include <assert.h>
#include <stdio.h>

int
parity(int n)
{
	return (n & 1) ? -1 : 1;
}

int
altsum(size_t r, size_t c, int m[r][c])
{
	size_t i, j;
	int v;

	v = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			v += m[i][j] * parity(i + j);
	}
	return v;
}

int
main()
{
	int m1[3][3] = {
		{ 1, 2, 3 },
		{ -3, -2, 1 },
		{ 3, -1, 2 },
	};
	int m2[5][4] = {
		{ 1, 2, 3, 4 },
		{ -3, -2, 1, 1 },
		{ 3, 8, -1, 2 },
		{ 20, 5, 10, -4 },
		{ 10, -8, -8, 4 },
	};
	int m3[3][4] = {
		{ 2, 3, 2, 3 },
		{ 2, 3, 2, 3 },
		{ 2, 3, 2, 3 },
	};

	assert(altsum(3, 3, m1) == 8);
	assert(altsum(5, 4, m2) == -32);
	assert(altsum(3, 4, m3) == -2);

	return 0;
}
