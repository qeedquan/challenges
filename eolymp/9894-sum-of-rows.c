/*

Two dimensional array of size n⋅n is given. Find the sum of elements in its rows.

Input
First line contains the size of array n (n≤100). Each of the next n lines contains n integers.

Output
In the i-th line print the sum of elements in the i-th row of array.

https://static.eolymp.com/content/je/je53e4somd5qra0od2dss1piq8.gif

Examples
Input #1
3
4 6 7
8 3 2
5 4 2

Answer #1
17
13
11

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
solve(size_t n, int m[n][n], int r[n])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		r[i] = 0;
		for (j = 0; j < n; j++)
			r[i] += m[i][j];
	}
}

void
test(size_t n, int m[n][n], int r[n])
{
	int v[n];

	solve(n, m, v);
	assert(!memcmp(v, r, sizeof(v)));
}

int
main()
{
	int m1[3][3] = {
		{ 4, 6, 7 },
		{ 8, 3, 2 },
		{ 5, 4, 2 },
	};

	int r1[3] = { 17, 13, 11 };

	test(3, m1, r1);

	return 0;
}
