/*

Two fishing vessels are sailing the open ocean, both on a joint ops fishing mission.

On a high stakes, high reward expidition - the ships have adopted the strategy of hanging a net between the two ships.

The net is 40 miles long. Once the straight-line distance between the ships is greater than 40 miles, the net will tear, and their valuable sea harvest will be lost! We need to know how long it will take for this to happen.

Given the bearing of each ship, find the time in minutes at which the straight-line distance between the two ships reaches 40 miles. Both ships travel at 90 miles per hour. At time 0, assume the ships have the same location.

Bearings are defined as degrees from north, counting clockwise. These will be passed to your function as integers between 0 and 359 degrees. Round your result to 2 decmal places.

If the net never breaks, return float('inf')

Happy sailing!

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x) * M_PI / 180)

double
breaktime(double a, double b)
{
	double r, t;

	if (a == b)
		return INFINITY;

	t = deg2rad(a - b);
	r = sqrt(800 / (1 - cos(t)));
	r = (r / 90) * 60;
	return r;
}

void
test(double a, double b, double r)
{
	double t;

	t = breaktime(a, b);
	printf("%f\n", t);
	if (isinf(r))
		assert(isinf(t));
	else
		assert(fabs(t - r) < 1e-2);
}

int
main()
{
	test(0, 90, 18.86);
	test(270, 90, 13.33);
	test(90, 90, INFINITY);

	return 0;
}
