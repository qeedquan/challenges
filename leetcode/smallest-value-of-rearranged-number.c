/*

You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

Return the rearranged number with minimal value.

Note that the sign of the number does not change after rearranging the digits.

Example 1:

Input: num = 310
Output: 103
Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310.
The arrangement with the smallest value that does not contain any leading zeros is 103.

Example 2:

Input: num = -7605
Output: -7650
Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
The arrangement with the smallest value that does not contain any leading zeros is -7650.

Constraints:

-10^15 <= num <= 10^15

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

void
digcnt(vlong c[10], vlong n)
{
	memset(c, 0, sizeof(*c) * 10);
	for (; n > 0; n /= 10)
		c[n % 10] += 1;
}

vlong
dignum(vlong c[10], vlong r, vlong i0, vlong i1, vlong di)
{
	vlong i;

	i = i0;
	for (;;) {
		for (; c[i] > 0; c[i]--)
			r = (r * 10) + i;

		if (i == i1)
			break;
		i += di;
	}
	return r;
}

vlong
digz(vlong c[10])
{
	vlong i;

	if (!c[0])
		return 0;

	for (i = 1; i < 10; i++) {
		if (c[i] > 0) {
			c[i] -= 1;
			return i;
		}
	}
	return 0;
}

// https://oeis.org/A328447
vlong
smallest(vlong n)
{
	vlong c[10];

	digcnt(c, llabs(n));
	if (n < 0)
		return -dignum(c, 0, 9, 0, -1);
	return dignum(c, digz(c), 0, 9, 1);
}

int
main()
{
	static const vlong tab[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 12, 22, 23, 24, 25, 26, 27, 28, 29, 30, 13, 23, 33, 34, 35, 36, 37,
		38, 39, 40, 14, 24, 34, 44, 45, 46, 47, 48, 49, 50, 15, 25, 35, 45, 55,
		56, 57, 58, 59, 60, 16, 26, 36, 46, 56, 66, 67, 68, 69, 70, 17, 27, 37,
		47, 57, 67
	};

	size_t i;

	assert(smallest(301) == 103);
	assert(smallest(-7605) == -7650);

	for (i = 0; i < nelem(tab); i++)
		assert(smallest(i) == tab[i]);

	return 0;
}
