#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

void
areas(double l, double *ca, double *ra)
{
	double w, r;

	w = l * 0.6;
	r = l * 0.2;
	*ra = M_PI * r * r;
	*ca = (l * w) - *ra;
}

void
test(double l, double rra, double rca)
{
	static const double eps = 1e-2;

	double ca, ra;

	areas(l, &ca, &ra);
	printf("%.2f %.2f\n", ca, ra);
	assert(fabs(rca - ca) < eps);
	assert(fabs(rra - ra) < eps);
}

int
main(void)
{
	test(10, 12.57, 47.43);

	return 0;
}
