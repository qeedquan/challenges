/*

Compute the complex logarithm at any given complex number, accurate to at least 1 in 10^-12. The imaginary part should be inside the interval (−π, π] (i.e if the imaginary part is exactly π, keep it as is).

Note: You shouldn't try to compute the value of this function at the poles. Please return null/NULL/nil/None (C#: throw an ArgumentException, Java: throw an ArithmeticException) if this happens.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex
myclog(double complex z)
{
	double a, b;

	a = creal(z);
	b = cimag(z);
	return CMPLX(log(hypot(a, b)), atan2(b, a));
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
			u = clog(z);
			v = myclog(z);
			assert(fabs(creal(u) - creal(v)) < eps);
			assert(fabs(cimag(u) - cimag(v)) < eps);
		}
	}
	return 0;
}
