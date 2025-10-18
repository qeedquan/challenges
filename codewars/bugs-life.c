/*

A bug lives in a world which is a cuboid and has to walk from one corner of the cuboid to the opposite corner (see the picture below).

Google 'Cuboid Space Diagonal'

Task
Define a function which takes 3 arguments: the length a , width b, and height c of the bug's "world", and finds the shortest distance needed to walk from start to finish. The dimensions will be positive numbers.

Note: The bug cannot fly and has to maintain contact with a surface at all times but can walk up walls.

Example
a=1, b=2, c=3: distance=4.242640687119285

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
shortest(double a, double b, double c)
{
	double d;

	d = hypot(a, b + c);
	d = fmin(d, hypot(b, a + c));
	d = fmin(d, hypot(c, a + b));
	return d;
}

void
test(double a, double b, double c, double r)
{
	double d;

	d = shortest(a, b, c);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-7);
}

int
main()
{
	test(1, 2, 3, 4.242640687119285);
	test(1, 1, 1, 2.236067978);
	test(134, 191.5, 45.5, 262.4738082);
	return 0;
}
