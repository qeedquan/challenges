/*

Given an array of numbers, return an array, with each member of input array rounded to a nearest number, divisible by 5.

For example:

roundToFive([34.5, 56.2, 11, 13]);

should return

[35, 55, 10, 15]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
roundtofive(double *a, size_t n, int *r)
{
	size_t i;
	double v;

	for (i = 0; i < n; i++) {
		v = fmod(a[i], 5);
		if (v >= 2.5)
			r[i] = a[i] - v + 5;
		else
			r[i] = a[i] - v;
	}
}

void
test(double *a, size_t n, int *r)
{
	int p[32];

	roundtofive(a, n, p);
	dump(p, n);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	double a1[] = {34.5, 56.2, 11, 13};
	double a2[] = {1, 5, 87, 45, 8, 8};
	double a3[] = {3, 56.2, 11, 13};
	double a4[] = {22.5, 544.9, 77.5};

	int r1[] = {35, 55, 10, 15};
	int r2[] = {0, 5, 85, 45, 10, 10};
	int r3[] = {5, 55, 10, 15};
	int r4[] = {25, 545, 80};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);

	return 0;
}
