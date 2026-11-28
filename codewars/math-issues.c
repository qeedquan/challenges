/*

Oh no, our Math object was "accidently" reset. Can you re-implement some of those functions? We can assure, that only non-negative numbers are passed as arguments. So you don't have to consider things like undefined, null, NaN, negative numbers, strings and so on.

Here is a list of functions, we need:

Math.round()
Math.ceil()
Math.floor()

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
xfloor(double x)
{
	return (int)x;
}

double
xround(double x)
{
	return xfloor(x + 0.5);
}

double
xceil(double x)
{
	double r;

	r = xfloor(x);
	if (fmod(x, 1) > 0)
		r += 1;
	return r;
}

int
main()
{
	double i;

	for (i = 0; i <= 1e5; i += 1e-3) {
		assert(floor(i) == xfloor(i));
		assert(round(i) == xround(i));
		assert(ceil(i) == xceil(i));
	}
	return 0;
}
