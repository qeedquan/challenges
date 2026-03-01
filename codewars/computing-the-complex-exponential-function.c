/*

Compute the exponential function at any given complex number, accurate to at least 1 in 10^-12.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex
mycexp(double complex z)
{
	double a, b;

	a = creal(z);
	b = cimag(z);
	return exp(a) * CMPLX(cos(b), sin(b));
}

int
main()
{
	static const double eps = 1e-12;

	double complex u, v;
	double complex z;
	double a, b;
	double N, S;

	N = 50;
	S = 1e-2;
	for (a = -N; a <= N; a += S) {
		for (b = -N; b <= N; b += S) {
			z = CMPLX(a, b);
			u = cexp(z);
			v = mycexp(z);
			assert(fabs(creal(u) - creal(v)) < eps);
			assert(fabs(cimag(u) - cimag(v)) < eps);
		}
	}
	return 0;
}
