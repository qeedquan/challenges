/*

Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

Example 1:
https://assets.leetcode.com/uploads/2021/05/20/grid3.png
Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.

Example 2:
https://assets.leetcode.com/uploads/2021/05/20/grid4.png
Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.

Example 3:
https://assets.leetcode.com/uploads/2021/05/26/grid4.png
Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.


Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.

Hint 1
What is the maximum number of rotations you have to check?

Hint 2
Is there a formula you can use to rotate a matrix 90 degrees?

*/

#include <assert.h>
#include <stdio.h>

bool
rotation(size_t n, int m[n][n], int t[n][n])
{
	size_t i, j;
	int f;

	f = 0xf;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (m[i][j] != t[i][j])
				f &= ~0x1;
			if (m[i][j] != t[j][n - 1 - i])
				f &= ~0x2;
			if (m[i][j] != t[n - 1 - i][n - 1 - j])
				f &= ~0x4;
			if (m[i][j] != t[n - 1 - j][i])
				f &= ~0x8;
		}
	}
	return f != 0;
}

int
main()
{
	int m1[2][2] = {
		{ 0, 1 },
		{ 1, 0 },
	};

	int m2[2][2] = {
		{ 0, 1 },
		{ 1, 1 },
	};

	int m3[3][3] = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 1, 1, 1 },
	};

	int t1[2][2] = {
		{ 1, 0 },
		{ 0, 1 },
	};

	int t2[2][2] = {
		{ 1, 0 },
		{ 0, 1 },
	};

	int t3[3][3] = {
		{ 1, 1, 1 },
		{ 0, 1, 0 },
		{ 0, 0, 0 },
	};

	assert(rotation(2, m1, t1) == true);
	assert(rotation(2, m2, t2) == false);
	assert(rotation(3, m3, t3) == true);

	return 0;
}
