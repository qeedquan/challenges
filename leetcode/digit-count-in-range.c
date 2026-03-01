/*

Description
Given an integer d between 0 and 9, and two positive integers low and high as lower and upper bounds, respectively. Return the number of times that d occurs as a digit in all integers between low and high, including the bounds low and high.

Example 1:

Input: d = 1, low = 1, high = 13

Output: 6

Explanation:

The digit d=1 occurs 6 times in 1,10,11,12,13. Note that the digit d=1 occurs twice in the number 11.

Example 2:

Input: d = 3, low = 100, high = 250

Output: 35

Explanation:

The digit d=3 occurs 35 times in 103,113,123,130,131,…,238,239,243.

Note:

0 <= d <= 9
1 <= low <= high <= 2×10^8

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
count(int n, int d)
{
	int c, m, p, q, r;

	c = 0;
	for (p = 1; p <= n; p *= 10) {
		m = p * 10;
		q = n / m;
		r = n % m;
		if (q > 0)
			c += q * p;
		if (d == 0)
			c -= p;
		if (r >= d * p)
			c += min(r - d * p + 1, p);
	}

	return c;
}

int
digits(int n, int lo, int hi)
{
	return count(hi, n) - count(lo - 1, n);
}

int
main(void)
{
	assert(digits(1, 1, 13) == 6);
	assert(digits(3, 100, 250) == 35);

	return 0;
}
