/*

Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1.
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
Example 3:

Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 10^9 + 7, the result is 505379714.


Constraints:

1 <= n <= 10^5

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A047778
uvlong
concatbin(uvlong n)
{
	static const uvlong mod = 1000000007ULL;

	uvlong i, r, s;

	if (n == 0)
		return 0;

	r = 1;
	s = 4;
	for (i = 2; i <= n; i++) {
		if (i == s)
			s <<= 1;
		r = ((r * s) + i) % mod;
	}
	return r;
}

int
main(void)
{
	assert(concatbin(1) == 1);
	assert(concatbin(3) == 27);
	assert(concatbin(12) == 505379714ULL);

	return 0;
}
