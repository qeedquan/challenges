#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
circumference(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a, b, c, r;

	a = hypot(x1 - x2, y1 - y2);
	b = hypot(x1 - x3, y1 - y3);
	c = hypot(x3 - x2, y3 - y2);
	r = (a * b * c) / sqrt((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b));
	return 2 * M_PI * r;
}

void
test(double x1, double y1, double x2, double y2, double x3, double y3, double r)
{
	double p;

	p = circumference(x1, y1, x2, y2, x3, y3);
	printf("%.2f\n", p);
	assert(fabs(p - r) < 1e-2);
}

int
main(void)
{
	test(0.0, -0.5, 0.5, 0.0, 0.0, 0.5, 3.14);
	test(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 4.44);
	test(5.0, 5.0, 5.0, 7.0, 4.0, 6.0, 6.28);
	test(0.0, 0.0, -1.0, 7.0, 7.0, 7.0, 31.42);
	test(50.0, 50.0, 50.0, 70.0, 40.0, 60.0, 62.83);
	test(0.0, 0.0, 10.0, 0.0, 20.0, 1.0, 632.24);
	test(0.0, -500000.0, 500000.0, 0.0, 0.0, 500000.0, 3141592.65);

	return 0;
}
