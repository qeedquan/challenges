/*

Hello,

I am Jomo Pipi

and today we will be evaluating an expression like this:

(there are an infinite number of radicals)

sqrt(x + sqrt(x + sqrt(x ...)))

for a given value x

Simple!

arguments passed in will be 1 or greater

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solve(double x)
{
	return (sqrt((4 * x) + 1) + 1) / 2;
}

void
test(double x, double r)
{
	double v;

	v = solve(x);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-6);
}

int
main()
{
	test(2, 2);
	test(6, 3);
	test(12, 4);

	return 0;
}
