/*

The blancmange function is used as an example in basic calculus of a function that is continuous everywhere, but differentiable nowhere. It achieves this effect by using the sums of ever-diminishing triangle-wave functions.

Your task is to build a program that takes a binary fractional number in the interval [0, 1] and returns the exact height of the blancmange curve at that position. Both fractions can be represented using the notation of your choice, but if you are using a nonstandard one (e.g. not IEEE floating-point or an integer with a fixed radix point), you must explain it in your solution, and your notation must support an accuracy of at least 2^-52.

*/

#include <stdio.h>
#include <math.h>

double
triangle(double x)
{
	return fabs(x - round(x));
}

// https://en.wikipedia.org/wiki/Blancmange_curve
double
bm(double x)
{
	double i, p, r;

	r = 0;
	for (i = 0; i < 50; i++) {
		p = pow(2, i);
		r += triangle(p * x) / p;
	}
	return r;
}

int
main(void)
{
	double N, s;
	double i;

	N = 5;
	s = 1e-3;
	for (i = -N; i <= N; i += s)
		printf("%f\n", bm(i));

	return 0;
}
