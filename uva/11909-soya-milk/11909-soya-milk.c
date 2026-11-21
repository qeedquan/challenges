#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x) * M_PI / 180)

double
volume(double l, double w, double h, double t)
{
	double a;

	a = tan(deg2rad(t));
	if (l * a <= h)
		return (l * w * h) - (w * 0.5 * l * l * a);
	return (w * 0.5 * h * h) / a;
}

void
test(double l, double w, double h, double t, double r)
{
	double v;

	v = volume(l, w, h, t);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	test(9, 6, 19, 20, 937.555);

	return 0;
}
