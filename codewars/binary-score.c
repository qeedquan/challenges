/*

Objective
Given a number n we will define its scORe to be 0 | 1 | 2 | 3 | ... | n, where | is the bitwise OR operator.

Write a function that takes n and finds it's scORe.

n             scORe n
0               0
1               1
49           63
1000000 1048575

Any feedback would be much appreciated

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
scorebf(uvlong n)
{
	uvlong i, r;

	for (i = r = 0; i <= n; i++)
		r |= i;
	return r;
}

uvlong
score(uvlong n)
{
	uvlong r;

	if (n == 0)
		return 0;

	r = 1ULL << (stdc_bit_width(n) - 1);
	r |= (r - 1);
	return r;
}

int
main()
{
	uvlong i;

	assert(score(0) == 0);
	assert(score(1) == 1);
	assert(score(49) == 63);
	assert(score(1000000) == 1048575);
	assert(score(10000000) == 16777215);
	assert(score(UINT_MAX) == UINT_MAX);

	for (i = 0; i <= 50000; i++)
		assert(score(i) == scorebf(i));

	return 0;
}
