/*

In mathematics, an nth root of a number x, where n is usually assumed to be a positive integer, is a number r which, when raised to the power n, yields x:

r^n=x,

Given number n, such that n > 1, find if its 2nd root, 4th root and 8th root are all integers (fractional part is 0), return true if it exists, false if not.

// 2nd root of 256 is 16
// 4th root of 256 is 4
// 8th root of 256 is 2

perfectRoots(256) // returns true

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

// https://oeis.org/A001016
bool
perfectroots(uvlong n)
{
	uvlong x, x2, x4, x8;

	x = pow(n, 0.125);
	x2 = x * x;
	x4 = x2 * x2;
	x8 = x4 * x4;
	return x8 == n;
}

int
main()
{
	assert(perfectroots(256) == true);
	assert(perfectroots(1000) == false);
	assert(perfectroots(6561) == true);

	return 0;
}
