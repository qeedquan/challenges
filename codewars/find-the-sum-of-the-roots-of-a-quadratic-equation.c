/*

Implement function which will return sum of roots of a quadratic equation rounded to 2 decimal places, if there are any possible roots, else return None/null/nil/nothing.
If you use discriminant,when discriminant = 0, x1 = x2 = root => return sum of both roots. There will always be valid arguments.

Quadratic equation - https://en.wikipedia.org/wiki/Quadratic_equation

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solve(double a, double b, double c)
{
	double d;

	d = (b * b) - (4 * a * c);
	if (d < 0)
		return NAN;
	return -b / a;
}

void
test(double a, double b, double c, double r)
{
	double s;

	s = solve(a, b, c);
	if (isnan(r))
		assert(isnan(s));
	else
		assert(fabs(s - r) < 1e-2);
}

int
main()
{
	test(6, 3, 8, NAN);
	test(2, 11, -6, -5.5);
	test(5, -8, 3, 1.6);
	test(6, 4, 9, NAN);
	test(1, -2, -5.25, 2);
	test(3, -10, 5, 3.33);
	test(5, 2, 4, NAN);
	test(1, 4, 3, -4);
	test(2, 3, 1, -1.5);
	test(1, -4, 4, 4);
	test(1, 3, 9, NAN);
	test(1, -1, -20, 1);
	test(2, -4, -2, 2);
	test(6, 11, -35, -1.83);
	test(3, 4, 9, NAN);
	test(-4, -7, 12, -1.75);
	test(1, -1, -3, 1);
	test(5, -2, -9, 0.4);
	test(2, 8, 0, -4);
	test(3, 5, 10, NAN);

	return 0;
}
