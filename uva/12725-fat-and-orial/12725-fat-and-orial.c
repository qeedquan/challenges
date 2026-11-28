#include <assert.h>
#include <stdio.h>
#include <math.h>

double
grade(double n, double m, double a, double b)
{
	double r;

	r = ((m * (a + b)) - (n * a)) / b;
	if (r < 0 || r > 10)
		r = -1;
	return r;
}

void
test(double n, double m, double a, double b, double r)
{
	double p;

	p = grade(n, m, a, b);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-2);
}

int
main(void)
{
	test(7, 8, 1, 1, 9);
	test(7, 9, 5, 2, -1);
	test(9.05, 9.20, 28, 20, 9.41);

	return 0;
}
