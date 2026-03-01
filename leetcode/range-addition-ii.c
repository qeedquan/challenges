/*

You are given an m x n matrix M initialized with all 0's and an array of operations ops,
where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.

Example 2:
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4

Example 3:
Input: m = 3, n = 3, ops = []
Output: 9

Constraints:

1 <= m, n <= 4 * 10^4
0 <= ops.length <= 10^4
ops[i].length == 2
1 <= ai <= m
1 <= bi <= n

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
maxcount(int m, int n, int ops[][2], size_t nops)
{
	size_t i;

	for (i = 0; i < nops; i++) {
		m = min(m, ops[i][0]);
		n = min(n, ops[i][1]);
	}
	return m * n;
}

int
main()
{
	int ops1[][2] = { { 2, 2 }, { 3, 3 } };
	int ops2[][2] = { { 2, 2 }, { 3, 3 }, { 3, 3 }, { 3, 3 }, { 2, 2 }, { 3, 3 }, { 3, 3 }, { 3, 3 }, { 2, 2 }, { 3, 3 }, { 3, 3 }, { 3, 3 } };

	assert(maxcount(3, 3, ops1, nelem(ops1)) == 4);
	assert(maxcount(3, 3, ops2, nelem(ops2)) == 4);
	assert(maxcount(3, 3, NULL, 0) == 9);

	return 0;
}
