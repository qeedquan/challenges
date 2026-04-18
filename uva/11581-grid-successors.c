/*

Consider a 3 × 3 grid of numbers g where each cell contains either a ‘0’
or a ‘1’. We define a function f that transforms such a grid: each cell
of the grid f(g) is the sum (modulo 2) of its adjacent cells in g (two
cells are considered adjacent if and only if they share a common side).
Furthermore, we define f[i](g) recursively f[0](g) = g and f[i+1](g) = f(f(i)(g)) (where i ≤ 0).
Finally, for any grid h, let kg(h) be the number of indices i such that h = f[i](g) (we may have k[g](h) = ∞).
Given a grid g, your task is to compute the greatest index i such that k[g](f[i](g)) is finite.

Input
Input begins with the number of test cases on its own line. Each case consists of a blank line followed
by three lines of three characters, each either ‘1’ or ‘0’. The j’th character of the i’th row of the test
case is the value in the j’th cell of the i’th row of the grid g.

Output
For each test case, output the greatest index i such that k[g](f[i](g)) is finite.
If there is no such index, output ‘-1’.

Sample Input

3
111
100
001

101
000
101

000
000
000

Sample Output
3
0
-1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef int mat3[3][3];

bool
zero(mat3 m)
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (m[i][j] > 0)
				return false;
		}
	}
	return true;
}

void
f(mat3 m)
{
	mat3 h;

	h[0][0] = (m[0][1] + m[1][0]) % 2;
	h[0][1] = (m[0][0] + m[1][1] + m[0][2]) % 2;
	h[0][2] = (m[0][1] + m[1][2]) % 2;

	h[1][0] = (m[0][0] + m[1][1] + m[2][0]) % 2;
	h[1][1] = (m[0][1] + m[1][0] + m[1][2] + m[2][1]) % 2;
	h[1][2] = (m[1][1] + m[0][2] + m[2][2]) % 2;

	h[2][0] = (m[2][1] + m[1][0]) % 2;
	h[2][1] = (m[2][0] + m[1][1] + m[2][2]) % 2;
	h[2][2] = (m[2][1] + m[1][2]) % 2;

	memcpy(m, h, sizeof(h));
}

int
solve(mat3 m)
{
	int r;

	for (r = -1; r < INT_MAX; r++) {
		if (zero(m))
			return r;
		f(m);
	}
	return -1;
}

int
main()
{
	mat3 m1 = {
		{ 1, 1, 1 },
		{ 1, 0, 0 },
		{ 0, 0, 1 },
	};

	mat3 m2 = {
		{ 1, 0, 1 },
		{ 0, 0, 0 },
		{ 1, 0, 1 },
	};

	mat3 m3 = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 },
	};

	assert(solve(m1) == 3);
	assert(solve(m2) == 0);
	assert(solve(m3) == -1);

	return 0;
}
