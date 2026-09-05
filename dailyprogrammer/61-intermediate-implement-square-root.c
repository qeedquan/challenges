/*

Today you should implement a function that all of us programmers depend heavily on, but most never give a second thought as to how it's actually coded: the square root function.

Write a function that given a number as input, will return the square root of that number, in floating point.

Obviously, you are not allowed to use the library version of sqrt() in the implementation of your function. Also, stay away from log() and exp(). In fact, don't use any mathematical functions that aren't the basic arithmetic ones (addition, subtraction, multiplication, division) or bit operations (though you can of course still use operators that compares numbers with each other, like "less than", "equal to", "more than", etc.)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

// ported from @bh3 solution
double
xsqrt(double n)
{
	uint64_t p, e;
	double r;
	int i;

	if (n <= 0.0)
		return 0.0;

	memcpy(&p, &n, sizeof(n));
	e = ((p & 0x7ff0000000000000LL) >> 52) - 1023;
	e >>= 1;
	p &= 0x800fffffffffffffLL;
	p |= ((e + 1023) << 52);
	memcpy(&r, &p, sizeof(p));

	for (i = 0; i < 8; i++)
		r = (r + (n / r)) / 2;
	return r;
}

int
main()
{
	static const double eps = 1e-12;
	double i, x, y;

	for (i = 0; i <= 1000; i += 1e-5) {
		x = sqrt(i);
		y = xsqrt(i);
		assert(fabs(x - y) < eps);
	}
	return 0;
}
