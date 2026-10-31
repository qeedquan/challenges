/*

Given a second order system, we can determine the bandwidth from the damping ratio and settling/peak time

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
bwdrst(double DR, double TS)
{
	double x1, x2, x3;

	x1 = sqrt((4 * pow(DR, 4)) - (4 * pow(DR, 2)) + 2);
	x2 = 1 - (2 * pow(DR, 2));
	x3 = 4 / (TS * DR);
	return x3 * sqrt(x1 + x2);
}

double
bwdrpt(double DR, double TP)
{
	double x1, x2, x3, x4;

	x1 = sqrt((4 * pow(DR, 4)) - (4 * pow(DR, 2)) + 2);
	x2 = 1 - (2 * pow(DR, 2));
	x3 = TP * sqrt(1 - pow(DR, 2));
	x4 = M_PI / x3;
	return x4 * sqrt(x1 + x2);
}

int
main(void)
{
	double DR;

	for (DR = 0; DR <= 1; DR += 1e-3)
		printf("%f %f\n", bwdrst(DR, 1), bwdrpt(DR, 1));

	return 0;
}
