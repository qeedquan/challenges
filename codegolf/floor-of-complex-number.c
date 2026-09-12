/*

Background
Complex floor is a domain extension of the mathematical floor function for complex numbers. This is used in some APL languages to implement floor ⌊, ceiling ⌈, residue |, GCD ∨, and LCM ∧ on complex numbers.

For the rest of this challenge, an integer refers to a Gaussian integer, i.e. a complex number whose real and imaginary parts are integers.

Eugene McDonnell defined seven requirements of a complex floor function (copied from the wiki page, with APL code fragments translated into plain math notation):

Existence. Every number has a floor.

Uniqueness. Every number has only one floor.

Fractionality. The magnitude of the difference of a number and its floor shall be less than one. This property must be satisfied to guarantee that remainders are less in magnitude than divisors. It may be called the fundamental property of the floor function.

Integrity. The floor of a number is an integer.

Convexity. If g is the floor of the numbers z and w, then it is also the floor of all numbers on the line segment between z and w.

Integer Translation. For c a complex integer, c+⌊z⌋=⌊c+z⌋.

Compatibility. The complex floor function is compatible with the real floor function. Furthermore, its action on purely imaginary numbers is similar to the action of the real floor function on real numbers.
In particular, re(⌊z⌋)≤re(⌈z⌉) and im(⌊z⌋)≤im(⌈z⌉). (Ceiling for complex numbers is defined as ⌈z⌉=−⌊−z⌋.)

One shape that satisfies these conditions is a rectangle sqrt(1/2) units high and sqrt(2) units wide, rotated 45 degrees, as in the following image.

https://i.stack.imgur.com/BdrN5.png

One interesting consequence of fractionality is that the magnitude of the residue is always smaller than that of the divisor, and the Euclidean algorithm always terminates on arbitrary complex number inputs.

Task
Define your own complex floor that satisfies the requirements listed above, and implement it. It is OK if you simply use McDonnell's function. If you use a different function, please include an explanation of how it satisfies the requirements.

Please note that simply flooring the two components is NOT a valid answer since it violates Fractionality: when z=3.9+2.9i,

⌊z⌋     = 3+2i
z - ⌊z⌋ = 0.9+0.9i
|z−⌊z⌋| = |0.9+0.9i| = 0.92*sqrt(2) > 1

You may represent a complex number as a built-in complex number or a pair of real numbers. You don't need to care too much about boundary conditions, since floating-point imprecision will impact its correctness anyway.

It is known to be implemented in Dyalog APL, J, and NARS2000. You are not allowed to use floor/ceiling/residue/GCD/LCM functions with non-real complex arguments for these languages.

Standard code-golf rules apply. Shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

/*

https://aplwiki.com/wiki/Residue
https://aplwiki.com/wiki/Complex_floor
https://aplwiki.com/wiki/Ceiling
https://www.jsoftware.com/papers/eem/complexfloor.htm

*/

double
fractional(double x)
{
	double f;

	f = fmod(x, 1);
	if (x < 0)
		f += 1;
	return f;
}

double complex
cfloor(double complex z)
{
	double complex b;
	double r, i;
	double x, y;

	r = creal(z);
	i = cimag(z);

	x = fractional(r);
	y = fractional(i);

	b = CMPLX(floor(r), floor(i));
	if (1 <= x + y) {
		if (x >= y)
			b += CMPLX(1, 0);
		else
			b += CMPLX(0, 1);
	}

	return b;
}

double complex
cceil(double complex z)
{
	return -cfloor(-z);
}

void
test(double complex z, double complex r)
{
	static const double eps = 1e-8;
	double complex c, f;

	f = cfloor(z);
	c = cceil(z);
	printf("%.3f%+.3fi | floor=%.3f%+.3fi ceil=%.3f%+.3fi\n", creal(z), cimag(z), creal(f), cimag(f), creal(c), cimag(c));
	assert(fabs(creal(f) - creal(r)) < eps);
	assert(fabs(cimag(f) - cimag(r)) < eps);
}

int
main(void)
{
	test(CMPLX(0.3, 0.6), CMPLX(0, 0));
	test(CMPLX(0.6, 0.8), CMPLX(0, 1));
	test(CMPLX(0.8, 0.6), CMPLX(1, 0));
	test(CMPLX(0.6, 0.3), CMPLX(0, 0));
	test(CMPLX(1.8, 2.5), CMPLX(2, 2));
	test(CMPLX(2.5, 2.2), CMPLX(2, 2));
	test(CMPLX(1.7, 2.2), CMPLX(1, 2));
	test(CMPLX(-1.8, -2.5), CMPLX(-2, -3));

	return 0;
}
