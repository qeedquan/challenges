/*

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.

Example 1:

https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
gen(size_t n, int m[n][n])
{
	size_t a, b, i;
	int c;

	c = 1;
	for (a = 0; a < n / 2; a++) {
		b = n - a - 1;
		for (i = a; i < b; i++)
			m[a][i] = c++;
		for (i = a; i < b; i++)
			m[i][b] = c++;
		for (i = b; i > a; i--)
			m[b][i] = c++;
		for (i = b; i > a; i--)
			m[i][a] = c++;
	}

	if (n & 1)
		m[n / 2][n / 2] = c;
}

void
test(size_t n, int r[n][n])
{
	int m[n][n];

	gen(n, m);
	assert(!memcmp(r, m, sizeof(m)));
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 2, 3},
	    {8, 9, 4},
	    {7, 6, 5},
	};

	int m2[1][1] = {
	    {1},
	};

	test(3, m1);
	test(1, m2);

	return 0;
}
