/*

There are 3 (commonly used) trigonometric functions sin cos and tan each of these functions has an inverse function

You goal is to write 3 programs or functions (one for each inverse trigonometric function asin acos atan) that take a (real) number a input and return the result of the corresponding inverse trigonometric function

Examples/Test-cases (rounded to four decimal places)
 x         asin(x)        acos(x)   atan(x)

 0         0              1.5708       0
 1         1.5708         0            0.7854
-1        -1.5708         3.1416      -0.7854
 0.2       0.2014         1.3694       0.1974
 0.4       0.4115         1.1593       0.3805
 0.6       0.6435         0.9273       0.5404
-0.5      -0.5236         2.0944      -0.4636
-0.7      -0.7754         2.3462      -0.6107
// you do not need to support these inputs for asin&acos
2      1.5708-1.317i      -1.317i      1.1071
5      1.5708-2.292i      -2.292i      1.3734
10     1.5708-2.993i      -2.993i      1.4711
15     1.5708-3.400i      -3.400i      1.5042
20     1.5708-3.688i      -3.688i      1.5208
100    1.5708-5.298i      -5.298i      1.5608

Rules
Please add built-in solutions to the community wiki
You may declare multiple functions in the same program, if you provide a way to choose which of the trigonometric functions is applied to the argument (e.g function names, a second argument)
It is allowed to return a tuple containing the results of multiple functions
You may take a second parameter, to distinguish between different functions
Your solutions for asin/acos only have to work for arguments between -1 and 1 (inclusive)
Your solution only has to be accurate up to three decimal places
Your score is the sum of the lengths of your program(s)/function(s)
Optional additional requirements
Also support inputs that give a complex result
Do not use the complex logarithm (see the Sandbox Post for how the complex logarithm might be useful)

*/

#include <assert.h>
#include <stdio.h>
#include <complex.h>

void
invtrig(double complex x, double complex *s, double complex *c, double complex *t)
{
	*s = casin(x);
	*c = cacos(x);
	*t = catan(x);
}

void
test(double complex x, double complex rs, double complex rc, double complex rt)
{
	static const double eps = 1e-3;
	double complex s, c, t;

	invtrig(x, &s, &c, &t);
	printf("%.4f%+.4fi %.4f%+.4fi %.4f%+4fi\n",
	       creal(s), cimag(s),
	       creal(c), cimag(c),
	       creal(t), cimag(t));

	assert((creal(s) - creal(rs)) < eps);
	assert((cimag(s) - cimag(rs)) < eps);

	assert((creal(c) - creal(rc)) < eps);
	assert((cimag(c) - cimag(rc)) < eps);

	assert((creal(t) - creal(rt)) < eps);
	assert((cimag(t) - cimag(rt)) < eps);
}

int
main(void)
{
	test(0, 0, 1.5708, 0);
	test(1, 1.5708, 0, 0.7854);
	test(-1, -1.5708, 3.1416, -0.7854);
	test(0.2, 0.2014, 1.3694, 0.1974);
	test(0.4, 0.4115, 1.1593, 0.3805);
	test(0.6, 0.6435, 0.9273, 0.5404);
	test(-0.5, -0.5236, 2.0944, -0.4636);
	test(-0.7, -0.7754, 2.3462, -0.6107);
	test(2, 1.5708 + 1.317 * I, -1.317 * I, 1.1071);
	test(5, 1.5708 + 2.292 * I, -2.292 * I, 1.3734);
	test(10, 1.5708 + 2.993 * I, -2.993 * I, 1.4711);
	test(15, 1.5708 + 3.400 * I, -3.400 * I, 1.5042);
	test(20, 1.5708 + 3.688 * I, -3.688 * I, 1.5208);
	test(100, 1.5708 + 5.298 * I, -5.298 * I, 1.5608);

	return 0;
}
