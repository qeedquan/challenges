/*

This just a simple physics problem:

A race car accelerates uniformly from 18.5 m/s to 46.1 m/s in 2.47 seconds. Determine the acceleration of the car and the distance traveled.

Create a function solveit(vi, vf, t) that takes in all three values and outputs a list of acceleration and distance in format [acceleration, distance].

Formula used:

a = (vf-vi)/t
d = vi*t + 0.5*a*(t**2)
If vi > vf then it should return empty list. The solution must be rounded off to double decimal place. Example: [11.17, 79.78]

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

bool
solve(double vi, double vf, double t, double *a, double *d)
{
	*a = *d = 0;
	if (vi > vf)
		return false;

	*a = (vf - vi) / t;
	*d = (vi * t) + (0.5 * *a * t * t);
	return true;
}

void
test(double vi, double vf, double t, double ra, double rd)
{
	static const double eps = 1e-2;

	double a, d;

	solve(vi, vf, t, &a, &d);
	printf("%f %f\n", a, d);
	assert(fabs(a - ra) <= eps);
	assert(fabs(d - rd) <= eps);
}

int
main()
{
	test(18.5, 46.1, 2.47, 11.17, 79.78);
	return 0;
}
