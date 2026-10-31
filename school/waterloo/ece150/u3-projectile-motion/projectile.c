/*

Given a projectile that is fired with an initial speed of v0 at an angle of θ radians, it is possible to predict both the maximum height and range of the projectile assuming no air friction.

h = (v^2 * sin^2(θ)) / (2*g)

r = (v^2 * sin(2θ)) / g
where g is acceleration due to gravity. Given an initial speed and angle, you should write two functions that calculate these two values. The function declarations should be:

double projectile_maximum_height( double initial_speed, double angle );
double projectile_range( double initial_speed, double angle );
and your documentation should clearly specify the units of the parameters and the units of the return values.

Now, write a function that, given the initial speed of the projectile and a desired range, have that function return an appropriate angle at which to launch the projectile.

double projectile_angle( double initial_speed, double desired_range );
Throw a std::domain_error exception if the range is beyond the maximum range of the projectile.

Your documentation should specify whether you are returning the smaller or larger angle, as with the exception of the maximum range (45°), there are two angles that will reach the same point.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

static const double G = 9.8;

double
projectile_maximum_height(double v0, double t)
{
	double s;

	s = sin(t);
	return (v0 * v0 * s * s) / (2 * G);
}

double
projectile_range(double v0, double t)
{
	return (v0 * v0 * sin(2 * t)) / G;
}

double
projectile_angle(double v0, double r)
{
	return asin((r * G) / (v0 * v0)) * 0.5;
}

int
main(void)
{
	double v0, h, t, r;

	v0 = 24;
	t = 0.3;
	h = projectile_maximum_height(v0, t);
	r = projectile_range(v0, t);
	t = projectile_angle(v0, r);
	printf("%f %f %f\n", h, r, t);

	return 0;
}
