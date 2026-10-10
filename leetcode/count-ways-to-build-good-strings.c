/*

Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.

Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".


Constraints:

1 <= low <= high <= 10^5
1 <= zero, one <= low

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

long
mod(long x, long m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

long
goodstrings(long low, long high, long zero, long one)
{
	static const long limit = 1000000007L;

	long i, r, *p;

	if (high < 0 || low > high || zero > low || one > low)
		return -1;

	p = calloc(high + 1, sizeof(*p));
	if (!p)
		return -errno;

	r = 0;
	p[0] = 1;
	for (i = 1; i <= high; i++) {
		if (i >= zero)
			p[i] = mod(p[i] + p[i - zero], limit);
		if (i >= one)
			p[i] = mod(p[i] + p[i - one], limit);
		if (i >= low)
			r = mod(r + p[i], limit);
	}

	free(p);
	return r;
}

int
main(void)
{
	assert(goodstrings(3, 3, 1, 1) == 8);
	assert(goodstrings(2, 3, 1, 2) == 5);

	return 0;
}
