#include <stdio.h>
#include <math.h>

double
solve(double x, double y, double c)
{
	static const double eps = 1e-12;

	double l, r;
	double d, tc;
	double dx, dy;

	l = 0;
	r = fmin(x, y);
	for (;;) {
		d = (l + r) / 2;
		dx = sqrt((x * x) - (d * d));
		dy = sqrt((y * y) - (d * d));
		tc = (dy * dx) / (dy + dx);
		if (fabs(tc - c) <= eps)
			break;

		if (tc > c)
			l = d;
		else
			r = d;
	}
	return d;
}

int
main()
{
	printf("%f\n", solve(30, 40, 10));
	printf("%f\n", solve(12.619429, 8.163332, 3));
	printf("%f\n", solve(10, 10, 3));
	printf("%f\n", solve(10, 10, 1));

	return 0;
}
