/*

Given a two-dimensional array of size n×m, your task is to find the sum of the elements within a specified subarray.

Input
The first line contains two integers, n and m (1≤n,m≤100), representing the number of rows and columns, respectively.
This is followed by n lines, each containing m integers, which are the elements of the array.

The final line provides four integers: r1, c1, r2, c2(r1≤r2, c1≤c2).
These numbers specify the row and column indices of the top-left and bottom-right corners of the subarray.
All array elements are integers with absolute values not exceeding 100. Note that the indexing starts from 1.

Output
Print the sum of the elements within the specified subarray.

Examples

Input #1
4 5
1 3 2 4 5
4 2 7 6 5
9 2 3 5 1
7 8 1 7 2
2 2 3 4

Answer #1
25

*/

#include <assert.h>
#include <stdio.h>

int
solve(size_t r, size_t c, int m[r][c], size_t r1, size_t c1, size_t r2, size_t c2)
{
	size_t i, j;
	int s;

	s = 0;
	for (i = r1 - 1; i <= r2 - 1; i++) {
		for (j = c1 - 1; j <= c2 - 1; j++)
			s += m[i][j];
	}
	return s;
}

int
main()
{
	int m[4][5] = {
		{ 1, 3, 2, 4, 5 },
		{ 4, 2, 7, 6, 5 },
		{ 9, 2, 3, 5, 1 },
		{ 7, 8, 1, 7, 2 },
	};

	assert(solve(4, 5, m, 2, 2, 3, 4) == 25);

	return 0;
}
