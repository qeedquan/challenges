#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solve(double d, double v, double u)
{
	double r;

	if (v >= u)
		return -1;

	r = (d / (sqrt((u * u) - (v * v)))) - (d / u);
	return (r > 0) ? r : -1;
}

void
test(double d, double v, double u, double r)
{
	double p;

	p = solve(d, v, u);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-3);
}

int
main(void)
{
	test(8, 5, 6, 1.079);
	test(1, 2, 3, 0.114);
	test(1, 5, 6, 0.135);

	return 0;
}
