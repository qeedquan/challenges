#include <assert.h>
#include <stdio.h>
#include <math.h>

void
boundary(double x, double y, double r, double *s, double *l)
{
	double z;

	z = hypot(x, y);
	*s = r - z;
	*l = r + z;
}

void
test(double x, double y, double r, double rs, double rl)
{
	static const double eps = 1e-2;

	double s, l;

	boundary(x, y, r, &s, &l);
	printf("%.2f %.2f\n", s, l);
	assert(fabs(rs - s) < eps);
	assert(fabs(rl - l) < eps);
}

int
main(void)
{
	test(0, 0, 100, 100, 100);
	test(3, 4, 10, 5, 15);
	test(5, 0, 5, 0, 10);

	return 0;
}
