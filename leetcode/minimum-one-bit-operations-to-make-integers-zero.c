/*

Given an integer n, you must transform it into 0 using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0.

Example 1:

Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.

Example 2:

Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.


Constraints:

0 <= n <= 10^9

Hint 1
The fastest way to convert n to zero is to remove all set bits starting from the leftmost one. Try some simple examples to learn the rule of how many steps are needed to remove one set bit.

Hint 2
consider n=2^k case first, then solve for all n.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uvlong
bitopsbf(uvlong n)
{
	uvlong r;

	for (r = 0; n > 0; n >>= 1)
		r ^= n;
	return r;
}

// https://oeis.org/A006068
uvlong
bitops(uvlong n)
{
	uvlong m, s;

	s = 1;
	for (;;) {
		m = n >> s;
		if (!m)
			break;
		n ^= m;
		s <<= 1;
	}
	return n;
}

int
main()
{
	static const uvlong tab[] = {
		0, 1, 3, 2, 7, 6, 4, 5, 15, 14, 12, 13, 8, 9, 11, 10, 31, 30, 28, 29,
		24, 25, 27, 26, 16, 17, 19, 18, 23, 22, 20, 21, 63, 62, 60, 61, 56,
		57, 59, 58, 48, 49, 51, 50, 55, 54, 52, 53, 32, 33, 35, 34, 39, 38,
		36, 37, 47, 46, 44, 45, 40, 41, 43, 42, 127, 126, 124, 125, 120, 121
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(bitops(i) == tab[i]);

	for (i = 0; i <= 10000000; i++)
		assert(bitops(i) == bitopsbf(i));

	return 0;
}
