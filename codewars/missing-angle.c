/*

Below is a right-angled triangle:

  |\
  | \
  |  \
  |   \
o |    \ h
  |     \
  |    θ \
  |_______\
     a
Your challange is to write a function (missingAngle in C/C#, missing_angle in Ruby), that calculates the angle θ in degrees to the nearest integer. You will be given three arguments representing each side: o, h and a. One of the arguments equals zero. Use the length of the two other sides to calculate θ. You will not be expected to handle any erronous data in your solution.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define rad2deg(x) ((x) * 180 / M_PI)

double
missingangle(double h, double a, double o)
{
	if (o == 0)
		o = sqrt(fabs(a * a - h * h));
	if (a == 0)
		a = sqrt(fabs(o * o - h * h));
	return round(rad2deg(atan(o / a)));
}

void
test(double h, double a, double o, double r)
{
	double t;

	t = missingangle(h, a, o);
	printf("%f\n", t);
	assert(fabs(t - r) < 1e-9);
}

int
main()
{
	test(0, 400, 300, 37);
	test(5, 4, 0, 37);
	test(8, 0, 5, 39);
	test(16.7, 0, 12.3, 47);
	test(7, 5, 0, 44);
	return 0;
}
