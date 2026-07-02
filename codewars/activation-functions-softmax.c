/*

Activation Functions: Softmax
The softmax activation function is commonly used in multi-class classification tasks to convert raw scores (logits) into probabilities.
It exponentiates each score and normalizes them to sum up to 1, representing the probabilities of each class.

Formula
The formula for softmax activation is:

softmax(x) = e^x[i] / Sum[i=1, n] e^x[i]

Where:
x is the input array containing raw scores (logits) for each class.
e^x computes the exponential of each individual score.
x^i represents the i-th element of the input array
AKA...
Calculate the exponential of each score.
Divide each exponential by the sum of all exponentials.
Your Job:
Implement a function that accepts an array of logits (raw scores) and computes their softmax activation.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
softmax(double *x, size_t n, double *y)
{
	double s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++) {
		y[i] = exp(x[i]);
		s += y[i];
	}
	for (i = 0; i < n; i++)
		y[i] /= s;
}

void
test(double *x, size_t n, double *r)
{
	size_t i;
	double y[16];

	softmax(x, n, y);

	for (i = 0; i < n; i++)
		printf("%f ", y[i]);
	printf("\n");

	for (i = 0; i < n; i++)
		assert(fabs(y[i] - r[i]) < 1e-6);
}

int
main()
{
	double x1[] = {1.0, 2.0, 3.0, 4.0, 1.0, 2.0, 3.0};
	double y1[] = {0.02364054, 0.06426166, 0.1746813, 0.474833, 0.02364054, 0.06426166, 0.1746813};

	test(x1, nelem(x1), y1);
	return 0;
}
