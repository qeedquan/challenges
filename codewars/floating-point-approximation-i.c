/*

Consider the function

f: x -> sqrt(1 + x) - 1 at x = 1e-15.

We get: f(x) = 4.44089209850062616e-16

or something around that, depending on the language.

This function involves the subtraction of a pair of similar numbers when x is near 0 and the results are significantly erroneous in this region. Using pow instead of sqrt doesn't give better results.

A "good" answer is 4.99999999999999875... * 1e-16.

Can you modify f(x) to give a good approximation of f(x) in the neighborhood of 0?

Note:
Don't round or truncate your results. See the testing function in Sample Tests:.

*/

#include <assert.h>
#include <math.h>

double
approximate(double x)
{
	return expm1(log1p(x) / 2);
}

void
test(double x, double r)
{
	static const double eps = 1e-12;
	double y;

	y = approximate(x);
	assert(fabs(y - r) < eps);
}

int
main()
{
	test(2.6e-08, 1.29999999155e-08);
	test(1.4e-09, 6.999999997549999e-10);
	test(5.0e-06, 2.499996875007812e-06);
	test(2.4e-07, 1.1999999280000085e-07);

	return 0;
}
