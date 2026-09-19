#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x) * M_PI / 180)

double
sind(double x)
{
	return sin(deg2rad(x));
}

double
solve(double f)
{
	return sind(108) / sind(63) * f;
}

int
main()
{
	printf("%.10f\n", solve(0.0000001));
	printf("%.10f\n", solve(0.0000002));
	printf("%.10f\n", solve(0.0000003));

	return 0;
}
