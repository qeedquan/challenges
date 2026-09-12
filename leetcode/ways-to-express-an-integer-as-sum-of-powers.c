/*

Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of unique positive integers,
in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 10^9 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

Example 1:

Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
Example 2:

Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.

Constraints:

1 <= n <= 300
1 <= x <= 5

Hint 1
You can use dynamic programming, where dp[k][j] represents the number of ways to express k as the sum of the x-th power of unique
positive integers such that the biggest possible number we use is j.

Hint 2
To calculate dp[k][j], you can iterate over the numbers smaller than j and try to use each one as a power of x to make our sum k.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

typedef long long vlong;

vlong
knapsack(vlong n, vlong x)
{
	static const vlong mod = 1000000007;

	vlong i, j, *p, r, v;

	if (n < 1 || x < 1)
		return 0;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -errno;

	p[0] = 1;
	for (i = 1; i <= n; ++i) {
		v = pow(i, x);
		if (v > n)
			break;

		for (j = n; j >= v; j--) {
			p[j] = (p[j] + p[j - v]) % mod;
		}
	}
	r = p[n];

	free(p);
	return r;
}

int
main()
{
	assert(knapsack(10, 2) == 1);
	assert(knapsack(4, 1) == 2);

	return 0;
}
