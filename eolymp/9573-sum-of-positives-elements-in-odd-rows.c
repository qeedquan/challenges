/*

Given a two-dimensional array with dimensions n×m, your task is to calculate the sum of all positive elements located in the odd-numbered rows of this array.

Input
The first line of input consists of two integers, n and m (1≤n,m≤100), representing the number of rows and columns, respectively. Following this, there are n lines, each containing m integers, which represent the elements of the array. Note that row numbering starts at 1.

Output
Output a single integer, which is the sum of the positive elements in the odd-numbered rows.

Examples

Input #1
4 5
1 3 2 4 5
4 2 7 6 5
9 2 3 5 1
7 8 1 7 2

Answer #1
35

*/

#include <assert.h>
#include <stdio.h>

int
solve(size_t r, size_t c, int m[r][c])
{
	size_t i, j;
	int s;

	s = 0;
	for (i = 0; i < r; i += 2) {
		for (j = 0; j < c; j++) {
			if (m[i][j] > 0)
				s += m[i][j];
		}
	}
	return s;
}

int
main()
{
	int m1[4][5] = {
		{ 1, 3, 2, 4, 5 },
		{ 4, 2, 7, 6, 5 },
		{ 9, 2, 3, 5, 1 },
		{ 7, 8, 1, 7, 2 },
	};

	assert(solve(4, 5, m1) == 35);

	return 0;
}
