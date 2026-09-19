/*

Compute the Gamma function at any given complex number, accurate to at least 1 in 10^-10.

Gamma function is defined in the mathematician way, i.e: Γ(n) = (n-1)! for positive integer n.

Note: You shouldn't try to compute the value of this function at the poles. Please return null if this happens. (For C#, please throw an ArgumentException.)

Range of inputs: -100<=real<=100, -100<=imag<=100

p.s You will want to complete at least these two katas first:

Computing the complex exponential function
Computing the complex logarithm function

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://en.wikipedia.org/wiki/Lanczos_approximation
double complex
cgamma(double complex z)
{
	static const double complex p[] = {
	    676.5203681218851,
	    -1259.1392167224028,
	    771.32342877765313,
	    -176.61502916214059,
	    12.507343278686905,
	    -0.13857109526572012,
	    9.9843695780195716e-6,
	    1.5056327351493116e-7,
	};

	double complex t, x, y;
	size_t i;

	if (creal(z) < 0.5)
		y = M_PI / (csin(M_PI * z) * cgamma(1 - z));
	else {
		z -= 1;
		x = 0.99999999999980993;
		for (i = 0; i < nelem(p); i++) {
			x += p[i] / (z + i + 1);
		}
		t = z + nelem(p) - 0.5;
		y = csqrt(2 * M_PI) * cpow(t, z + 0.5) * cexp(-t) * x;
	}
	return y;
}

int
main()
{
	double complex u;
	double v;
	int i;

	for (i = 0; i <= 10; i++) {
		u = cgamma(CMPLX(i, 0));
		v = tgamma(i);
		printf("%f %f %f\n", creal(u), cimag(v), v);
	}
	return 0;
}
