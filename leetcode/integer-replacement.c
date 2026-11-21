/*

Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Example 1:

Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1
Example 2:

Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1
Example 3:

Input: n = 4
Output: 2


Constraints:

1 <= n <= 2^31 - 1

*/

#include <stdio.h>
#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A353058
unsigned
intrep(unsigned n)
{
	unsigned r;

	for (r = 0; n > 1; r++) {
		if ((n & 1) == 0)
			n >>= 1;
		else if (n == 3 || ((n >> 1) & 1) == 0)
			n--;
		else
			n++;
	}
	return r;
}

int
main(void)
{
	static const unsigned tab[] = {0, 1, 2, 2, 3, 3, 4, 3, 4, 4, 5, 4, 5, 5, 5, 4, 5, 5, 6, 5, 6, 6, 6, 5, 6, 6, 7, 6, 7, 6, 6, 5, 6, 6, 7, 6, 7, 7, 7, 6, 7, 7, 8, 7, 8, 7, 7, 6, 7, 7, 8, 7, 8, 8, 8, 7, 8, 8, 8, 7, 8, 7, 7, 6, 7, 7, 8, 7, 8, 8, 8, 7, 8, 8, 9, 8, 9, 8, 8, 7, 8, 8, 9, 8, 9, 9, 9, 8};

	size_t i;

	assert(intrep(8) == 3);
	assert(intrep(7) == 4);
	assert(intrep(4) == 2);
	for (i = 0; i < nelem(tab); i++)
		assert(intrep(i + 1) == tab[i]);

	return 0;
}
