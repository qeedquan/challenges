#include <stdio.h>
#include <math.h>

double
solve(double n)
{
	double x, y;

	x = floor(cbrt(n));
	y = (n - pow(x, 3)) / (3 * pow(x, 2));
	return x + y;
}

int
main()
{
	printf("%.4f\n", solve(1729.03));
	printf("%.4f\n", solve(64));
	printf("%.4f\n", solve(63.999));

	return 0;
}
