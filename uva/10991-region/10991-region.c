#include <assert.h>
#include <stdio.h>
#include <math.h>

double
shaded(double r1, double r2, double r3)
{
	double p1, p2, p3;
	double v1, v2, v3;
	double a, b, c;
	double s;
	double u;

	a = r2 + r3;
	b = r1 + r3;
	c = r1 + r2;
	s = (a + b + c) / 2;

	u = sqrt(s * (s - a) * (s - b) * (s - c));

	p1 = acos((b * b + c * c - a * a) / (2.0 * b * c));
	p2 = acos((a * a + c * c - b * b) / (2.0 * a * c));
	p3 = acos((a * a + b * b - c * c) / (2.0 * a * b));

	v1 = p1 * 0.5 * r1 * r1;
	v2 = p2 * 0.5 * r2 * r2;
	v3 = p3 * 0.5 * r3 * r3;

	return u - v1 - v2 - v3;
}

void
test(double r1, double r2, double r3, double a)
{
	double p;

	p = shaded(r1, r2, r3);
	printf("%.6f\n", p);
	assert(fabs(p - a) < 1e-4);
}

int
main(void)
{
	test(5.70, 1.00, 7.89, 1.2243);
	test(478.61, 759.84, 28.36, 2361.0058);

	return 0;
}
