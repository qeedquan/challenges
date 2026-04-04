/*

Introduction
Take a list of n numbers a1, a2, a3, ..., aN to start with.

Arithmetic mean (or average) is the sum of these numbers divided by n.

Geometric mean (or average) is the product of these numbers taken to the nth root.

Example
List of numbers: 1, 3, 9, 27, 81

n = 5
Arithmetic mean = (1 + 3 + 9 + 27 + 81) / 5 = 121 / 5 = 24.2
Geometric mean = (1 * 3 * 9 * 27 * 81) ^ (1/5) = 59049 ^ (1/5) = 9

Task
You will be given a list of numbers and their arithmetic mean. However, the list is missing one number. Using this information, you must figure out and return the geometric mean of the FULL LIST, including the number that's missing.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
geomean(double *x, size_t n, double m)
{
	double p, s;
	size_t i;

	s = 0;
	p = 1;
	for (i = 0; i < n; i++) {
		s += x[i];
		p *= x[i];
	}
	p *= m * (n + 1) - s;

	return pow(p, 1.0 / (n + 1));
}

void
test(double *x, size_t n, double m, double r)
{
	double v;

	v = geomean(x, n, m);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-12);
}

int
main()
{
	double x1[] = { 2 };
	double x2[] = { 1, 2 };
	double x3[] = { 4, 6, 7, 2 };

	double x4[] = { -4, 45, 9 };
	double x5[] = { 1, 23, -2, 8, 6, 35, -34, 52 };
	double x6[] = { 1, -3, 3, 6, 5, 52, 130, -2, 4, -5 };

	test(x1, nelem(x1), 10, 6);
	test(x2, nelem(x2), 3, 2.2894284851066637);
	test(x3, nelem(x3), 5, 4.580344097847165);

	test(x4, nelem(x4), 6, 14.325905783504401);
	test(x5, nelem(x5), 10, 8.015856437398835);
	test(x6, nelem(x6), 10, 7.7330442855597);

	return 0;
}
