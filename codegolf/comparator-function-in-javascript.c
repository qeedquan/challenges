/*

Need to write a JS function compare(a,b) for numbers which return 1 when a > b, 0 when a == b, -1 when a < b. Also following properties should hold:

compare(NaN, NaN) = 0
NaN is bigger than any other number, so compare(NaN, any) = 1 and compare(any, NaN) = -1.
compare(-0.0, 0.0) = -1 and compare(0.0, -0.0) = 1. Other numbers are ordered by default.
Other way to define: function should behave as Double.compare method in Java.

*/

#include <assert.h>
#include <math.h>

int
cmp(double a, double b)
{
	double sa, sb;
	int na, nb;

	na = isnan(a);
	nb = isnan(b);
	if (na && nb)
		return 0;
	if (na && !nb)
		return 1;
	if (!na && nb)
		return -1;

	if (a == 0 && b == 0) {
		sa = copysign(1, a);
		sb = copysign(1, b);
		if (sa == -1 && sb == 1)
			return -1;
		if (sa == 1 && sb == -1)
			return 1;
	}

	if (a < b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

int
main(void)
{
	assert(cmp(NAN, NAN) == 0);
	assert(cmp(NAN, -436.0) == 1);
	assert(cmp(436.03, NAN) == -1);
	assert(cmp(-0.0, 0.0) == -1);
	assert(cmp(0.0, -0.0) == 1);
	assert(cmp(4.5, -0.0) == 1);
	assert(cmp(6.5, 34.0) == -1);

	return 0;
}
