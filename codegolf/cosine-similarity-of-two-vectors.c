/*

The cosine similarity of two vectors A and B is defined using their dot product and magnitude as:

A⋅B/(∥A∥∥B∥)

Or in other terms

X = Sum[i=1, n] A[i]*B[i]
Y = Sum[i=1, n] A[i]*A[i]
Z = Sum[i=1, n] B[i]*B[i]
S = X/(sqrt(Y)*sqrt(Z))

Challenge
Given two vectors (can be taken as lists) calculate their cosine similarity.

If their lengths are not equal, then the shorter vector should be padded on the right to length of the longer vector with zeroes.
Input and output may be done via any reasonable method.

Test cases below.

[1,2,3], [4,5,6] => ~0.974
[9, 62, 0, 3], [25, 3, 6] => ~0.25

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
cossim(double *a, double *b, size_t n)
{
	double x, y, z;
	size_t i;

	x = y = z = 0;
	for (i = 0; i < n; i++) {
		x += a[i] * b[i];
		y += a[i] * a[i];
		z += b[i] * b[i];
	}
	return x / (sqrt(y) * sqrt(z));
}

void
test(double *a, double *b, size_t n, double r)
{
	double v;

	v = cossim(a, b, n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-2);
}

int
main(void)
{
	double a1[] = {1, 2, 3};
	double b1[] = {4, 5, 6};

	double a2[] = {9, 62, 0, 3};
	double b2[] = {25, 3, 6, 0};

	test(a1, b1, nelem(a1), 0.974);
	test(a2, b2, nelem(a2), 0.25);

	return 0;
}
