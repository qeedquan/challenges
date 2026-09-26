/*

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.

Example 1:

Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

Example 2:

Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.

Example 3:

Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

Constraints:

0 <= n < 10^9

Note: This question is the same as 476: https://leetcode.com/problems/number-complement/

Hint 1
A binary number plus its complement will equal 111....111 in binary. Also, N = 0 is a corner case.

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long ulong;

// https://oeis.org/A035327
ulong
complement(ulong n)
{
	if (n == 0)
		return 1;
	return ~n ^ (~0ul << stdc_bit_width(n));
}

ulong
complementbf(ulong n)
{
	ulong m;

	m = 1;
	while (n > m)
		m = (m << 1) + 1;
	return m - n;
}

int
main()
{
	static const ulong tab[] = {
		1, 0, 1, 0, 3, 2, 1, 0, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10,
		9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22,
		21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2,
		1, 0, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48,
		47, 46
	};

	ulong i;

	assert(complement(5) == 2);
	assert(complement(7) == 0);
	assert(complement(10) == 5);

	for (i = 0; i < nelem(tab); i++)
		assert(complement(i) == tab[i]);

	for (i = 0; i <= 10000000; i++)
		assert(complement(i) == complementbf(i));

	return 0;
}
