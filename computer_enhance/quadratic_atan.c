#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define sqr(x) ((x) * (x))

double
quadratic_atan(double x)
{
	double a, b;

	a = sqr(M_PI) * x;
	b = 4 + sqrt(34 + (4 * sqr(M_PI) * sqr(x)));
	return a / b;
}

int
main()
{
	double x, y1, y2;
	double max_error;

	max_error = 0;
	for (x = -M_PI / 2; x <= M_PI / 2; x += 1e-4) {
		y1 = atan(x);
		y2 = quadratic_atan(x);
		max_error = fmax(max_error, fabs(y1 - y2));
	}
	printf("Max Error: %f\n", max_error);

	return 0;
}
