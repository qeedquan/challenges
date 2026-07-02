#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
solve(double R, double V)
{
	return (R * M_PI) / (2 * V);
}

int
main()
{
	printf("%f\n", solve(45, 100));
	printf("%f\n", solve(5, 1547));
	printf("%f\n", solve(1000, 10000));
	printf("%f\n", solve(5668, 5467));

	return 0;
}
