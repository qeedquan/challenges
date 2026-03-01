/*

Find the volume of the largest cube that will fit inside a cylinder of given height h and radius r.

Don't round your result. The result needs to be within 0.01 error margin of the expected result.

HINT: There are two cases to consider. Will it be the cylinder's height or the cylinder's radius that determines the maximum size of your cube? An if/else statement might be useful here.

Two Examples

1. for height  3, radius 7 => should return  27.0
2. for height 11, radius 5 => should return 353.55

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
volume(double h, double r)
{
	return pow(fmin(r * M_SQRT2, h), 3);
}

void
test(double h, double r, double vr)
{
	double v;

	v = volume(h, r);
	printf("%f\n", v);
	assert(fabs(v - vr) < 1e-2);
}

int
main()
{
	test(3, 7, 27);
	test(11, 5, 353.55);
	return 0;
}
