/*

For those who didn't know, Sigma is a Greek letter which is heavily used in mathematics as the summation sign.
Given a string representing an expression depending on k that we will denote E(k), compute the sum of the results for E(k), for each k∈{1,2,3,4,5}.
Concisely, you should find S such that:

S=∑k=[1, 5] E(k)

An example of an expression: E(k)=k/2+k^2

Specs
You are guaranteed:
that the expression is valid, so it contains no errors, and that it's dependent of the syntax chosen (e.g: if you only support 2*k, there will be no 2k)
to only have defined values amongst your results, so no values like 1/0, inf or nan will appear
You can assume that the expression above is fitting the limits of the programming language of your choice, so it won't result in overflows or any other limit-related errors
Any other non-whitespace ASCII Character instead of k can be chosen

Your program must support the following operations:
addition (+, plus(),add(),sum())
subtraction (-, minus(), subtract())
exponentiation (**,^,pow() or others, should be specified), with support to negative bases and exponents
square root in the form of sqrt(k), k^0.5, k**0.5, or however else you wish
multiplication and division
The submission can either be a full program or a function, while mentioning its usage
Any trailing / leading whitespace is allowed when outputting

Minimum precision: 2 decimal places
Test Cases (with k)
+---------------+--------------+
|  Input = E(k) |    Output    |
|---------------+--------------|
|2*k            | 30           |
|---------------+--------------|
|sqrt(k)        | 8.38         | (* with minimum decimal precision)
|---------------+--------------|
|k+k/2+k**2     | 77.5         |
|---------------+--------------|
|k**2           | 55           |
+---------------+--------------+

The score will be the number of bytes (of the source + compiler flags). The lowest scoring valid submission wins, while taking note that these loopholes are strictly forbidden. Here is a Python pseudo-code, to make things clearer.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
f1(double x)
{
	return 2 * x;
}

double
f2(double x)
{
	return sqrt(x);
}

double
f3(double x)
{
	return x + (x / 2.0) + (x * x);
}

double
f4(double x)
{
	return x * x;
}

double
sigma(double (*f)(double))
{
	double r;
	int i;

	r = 0;
	for (i = 1; i <= 5; i++)
		r += f(i);
	return r;
}

void
test(double (*f)(double), double r)
{
	double v;

	v = sigma(f);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-2);
}

int
main(void)
{
	test(f1, 30);
	test(f2, 8.38);
	test(f3, 77.5);
	test(f4, 55);

	return 0;
}
