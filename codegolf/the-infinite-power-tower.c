/*

The challenge
Quite simple, given an input x, calculate it's infinite power tower!

x^x^x^x^x^x...
For you math-lovers out there, this is x's infinite tetration.

Keep in mind the following:

x^x^x^x^x^x... = x^(x^(x^(x^(x...)))) != (((((x)^x)^x)^x)^x...)
Surprised we haven't had a "simple" math challenge involving this!*

Assumptions
x will always converge.
Negative and complex numbers should be able to be handled
This is code-golf, so lowest bytes wins!
Your answers should be correct to at least 5 decimal places
Examples
Input >> Output

1.4 >> 1.8866633062463325
1.414 >> 1.9980364085457847
[Square root of 2] >> 2
-1 >> -1
i >> 0.4382829367270323 + 0.3605924718713857i
1 >> 1
0.5 >> 0.641185744504986
0.333... >> 0.5478086216540975
1 + i >> 0.6410264788204891 + 0.5236284612571633i
-i >> 0.4382829367270323 -0.3605924718713857i
[4th root of 2] >> 1.239627729522762

*(Other than a more complicated challenge here)
https://codegolf.stackexchange.com/questions/124391/evaluate-modular-power-towers

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

typedef long double complex Complex;

// https://commons.wikimedia.org/wiki/File:Tetration_period.png
// A fractal with regions of convergences and divergences.
Complex
tower(Complex x)
{
	Complex x0;
	int i;

	x0 = x;
	for (i = 0; i < 1000; i++)
		x = cpowl(x0, x);
	return x;
}

void
test(Complex x, Complex r)
{
	static const long double eps = 1e-12;
	Complex y;

	y = tower(x);
	printf("%+Lf%+Lf\n", creall(y), cimagl(y));
	assert(creall(y) - creall(r) < eps);
	assert(cimagl(y) - cimagl(r) < eps);
}

int
main()
{
	test(1.4, 1.8866633062463325);
	test(1.414, 1.9980364085457847);
	test(sqrtl(2), 2);
	test(-1, -1);
	test(CMPLX(0, 1), CMPLX(0.4382829367270323, 0.3605924718713857));
	test(1, 1);
	test(0.5, 0.641185744504986);
	test(1 / 3.0, 0.5478086216540975);
	test(CMPLX(1, 1), CMPLX(0.6410264788204891, 0.5236284612571633));
	test(CMPLX(0, -1), CMPLX(0.4382829367270323, -0.3605924718713857));
	test(cpowl(2, 0.25), 1.239627729522762);

	return 0;
}
