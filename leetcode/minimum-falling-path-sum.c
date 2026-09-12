/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
mfps(size_t n, int m[n][n])
{
	size_t i, j;
	int r;

	if (n == 0)
		return 0;

	r = INT_MAX;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i > 0) {
				if (j == 0)
					m[i][j] += min(m[i - 1][j], m[i - 1][j + 1]);
				else if (j + 1 == n)
					m[i][j] += min(m[i - 1][j], m[i - 1][j - 1]);
				else
					m[i][j] += min(m[i - 1][j], min(m[i - 1][j - 1], m[i - 1][j + 1]));
			}

			if (i + 1 == n)
				r = min(r, m[i][j]);
		}
	}
	return r;
}

int
main()
{
	int m1[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};

	int m2[2][2] = {
		{ -19, 57 },
		{ -40, -5 },
	};

	int m3[3][3] = {
		{ 2, 1, 3 },
		{ 6, 5, 4 },
		{ 7, 8, 9 },
	};

	assert(mfps(3, m1) == 12);
	assert(mfps(2, m2) == -59);
	assert(mfps(3, m3) == 13);

	return 0;
}
