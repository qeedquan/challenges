/*

Write a function that returns the number of '2's in the factorization of a number.
For example,

twoCount(24)

should return 3, since the factorization of 24 is 2^3 x 3

twoCount(17280)

should return 7, since the factorization of 17280 is 2^7 x 5 x 3^3

The number passed to two_count (twoCount) will always be a positive integer greater than or equal to 1.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
twosbf(uvlong n)
{
	uvlong r;

	if (n == 0)
		return 0;

	for (r = 0; !(n & 1); n >>= 1)
		r++;
	return r;
}

// https://oeis.org/A007814
uvlong
twos(uvlong n)
{
	if (n == 0)
		return 0;
	return log2(n - (n & (n - 1)));
}

int
main()
{
	static const uvlong tab[] = {
		0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1,
		0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2,
		0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1,
		0, 3, 0, 1, 0, 2, 0, 1, 0, 6, 0, 1, 0, 2, 0, 1, 0, 3,
		0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1,
		0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2,
		0, 1, 0
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(twos(i + 1) == tab[i]);

	for (i = 0; i <= 100000000; i++)
		assert(twos(i) == twosbf(i));

	assert(twos(24) == 3);
	assert(twos(17280) == 7);

	return 0;
}
