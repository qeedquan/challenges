#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
burden(double a[][3], size_t n)
{
	double r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++)
		r += ((a[i][0] / a[i][1]) * a[i][2]) * a[i][1];
	return r;
}

void
test(double a[][3], size_t n, double r)
{
	double p;

	p = burden(a, n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-8);
}

int
main(void)
{
	double a1[][3] = {
		{ 1, 1, 1 },
		{ 2, 2, 2 },
		{ 3, 3, 3 },
		{ 2, 3, 4 },
		{ 8, 9, 2 },
	};

	double a2[][3] = {
		{ 9, 1, 8 },
		{ 6, 12, 1 },
		{ 8, 1, 1 },
	};

	double a3[][3] = {
		{ 10, 30, 40 },
		{ 9, 8, 5 },
		{ 100, 1000, 70 },
	};

	test(a1, nelem(a1), 38);
	test(a2, nelem(a2), 86);
	test(a3, nelem(a3), 7445);

	return 0;
}
