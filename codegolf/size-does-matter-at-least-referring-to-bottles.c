/*

Introduction
I have an even number of bottles, all of different sizes. Unfortunately, I only know the size of the smallest bottle: 300ml.
I also know the following:

Half of the bottles are twice the size of the other half, meaning that the smallest small bottle and the smallest large bottle are in a ratio of 2:1.
The smaller bottles, from smallest to largest, increase in size by n%, where n is the number of bottles multiplied by 3.
Could you help find what sizes my bottles are?

Challenge
Your input is to be an even number of bottles.
The output should be the size of all of the small bottles (from smallest to largest), then all of the large bottles (from smallest to largest).

Example I/O
In: 2
Out: 300, 600

In: 4
Out: 300, 336, 600, 672

In: 10
Out: 300, 390, 507, 659.1, 856.83, 600, 780, 1014, 1318.2, 1713.66

(Note: commas are unnecessary; this answer can be formatted in any way you want as long as all of the "small" bottles come before the "large" bottles.)

Rules
Standard loophole rules apply.
This is code-golf, so shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(double *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%.2f ", p[i]);
	printf("\n");
}

size_t
sizes(int n, double *r)
{
	size_t l;
	int i;

	l = 0;
	for (i = 0; i < n / 2; i++)
		r[l++] = 300 * pow(1 + (0.03 * n), i);
	for (i = 0; i < n / 2; i++)
		r[l++] = 600 * pow(1 + (0.03 * n), i);
	return l;
}

void
test(int n, double *r, size_t nr)
{
	static const double eps = 1e-3;

	double p[128];
	size_t np;
	size_t i;

	np = sizes(n, p);
	print(p, np);
	assert(np == nr);
	for (i = 0; i < np; i++)
		assert(fabs(p[i] - r[i]) < eps);
}

int
main()
{
	double r1[] = {300, 600};
	double r2[] = {300, 336, 600, 672};
	double r3[] = {300, 390, 507, 659.1, 856.83, 600, 780, 1014, 1318.2, 1713.66};

	test(2, r1, nelem(r1));
	test(4, r2, nelem(r2));
	test(10, r3, nelem(r3));

	return 0;
}
