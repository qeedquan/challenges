/*

Fit a*x^2 + b*x + c = sin(x) from [0, pi]
sin(0)    = 0
sin(pi/2) = 1
sin(pi)   = 0

Solve for a, b, c using the above constraints

a = -4/pi^2
b = 4/pi
c = 0

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
quadratic_sin(double x)
{
	static const double a = -4 / (M_PI * M_PI);
	static const double b = 4 / M_PI;

	return fma(a, x * x, fma(b, x, 0));
}

int
main()
{
	double x, y1, y2;
	double max_error;

	max_error = 0;
	for (x = 0; x <= M_PI; x += 1e-3) {
		y1 = sin(x);
		y2 = quadratic_sin(x);
		max_error = fmax(max_error, fabs(y1 - y2));
	}
	printf("Max Error: %f\n", max_error);

	return 0;
}
