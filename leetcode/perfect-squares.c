/*

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Constraints:

1 <= n <= 10^4

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

// https://oeis.org/A002828
vlong
lsq(vlong n)
{
	vlong i, j;
	vlong *p, r;

	if (n < 0)
		return -1;

	if (n == 0)
		return 0;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -errno;

	for (i = 0; i <= n; i++)
		p[i] = n;

	p[0] = 0;
	p[1] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 1; j * j <= i; j++)
			p[i] = min(p[i], p[i - (j * j)] + 1);
	}
	r = p[n];

	free(p);
	return r;
}

int
main(void)
{
	assert(lsq(12) == 3);
	assert(lsq(13) == 2);

	return 0;
}
