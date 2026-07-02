#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
area(double r, double n)
{
	return (r * r * n * sin((2 * M_PI) / n)) / 2;
}

void
test(double r, double n, double a)
{
	double p;

	p = area(r, n);
	printf("%f\n", p);
	assert(fabs(p - a) < 1e-3);
}

int
main(void)
{
	test(2, 2000, 12.566);
	test(10, 3000, 314.159);

	return 0;
}
