/*

You are given a positive integer n.

Return the maximum product of any two digits in n.

Note: You may use the same digit twice if it appears more than once in n.

Example 1:

Input: n = 31

Output: 3

Explanation:

The digits of n are [3, 1].
The possible products of any two digits are: 3 * 1 = 3.
The maximum product is 3.

Example 2:

Input: n = 22

Output: 4

Explanation:

The digits of n are [2, 2].
The possible products of any two digits are: 2 * 2 = 4.
The maximum product is 4.

Example 3:

Input: n = 124

Output: 8

Explanation:

The digits of n are [1, 2, 4].
The possible products of any two digits are: 1 * 2 = 2, 1 * 4 = 4, 2 * 4 = 8.
The maximum product is 8.

Constraints:

10 <= n <= 10^9

Hint 1
Use brute force

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
freq(int n, int d[10])
{
	memset(d, 0, sizeof(*d) * 10);
	for (; n > 0; n /= 10)
		d[n % 10] += 1;
}

int
maxprod(int n)
{
	int d[10];
	int c, i, r;

	freq(n, d);

	r = 1;
	c = 2;
	for (i = 9; i >= 0 && c; i--) {
		for (; d[i] && c; d[i]--) {
			c -= 1;
			r *= i;
		}
	}
	return r;
}

int
main()
{
	assert(maxprod(31) == 3);
	assert(maxprod(22) == 4);
	assert(maxprod(124) == 8);

	return 0;
}
