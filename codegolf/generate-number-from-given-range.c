/*

Your function must accept three numbers in any order:

A signed real number (or ±Infinity) - The number (N) for which you have to generate a number from the range
A signed integer - Minimum of the range
A signed integer - Maximum of the range
Input:

The minimum of the range will always be less than the maximum of the range, so don't worry about it
N can be any real (if it is possible Infinity and -Infinity also can be passed)
Requirements:

Your function must output same result each time for same inputs
Your function must output different result each time for different N (except when it's due to a floating point error)
The output must be in the given range
The outputs of your function for all numbers N must cover the entire range (except when missing outputs are due to floating point error)
Please specify:

The order of the input
Is it possible to pass ±Infinity as a N?
Are the minimum and maximum of the range inclusive or exclusive?
Unable to provide test cases because there are many ways to solve this problem, so please provide your test cases.

The shortest code in each programming language wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

// Use @97.100.97.109 function
double
f(double x, double a, double b)
{
	return ((b - a) / (1 + pow(2, x))) + a;
}

void
test(double a, double b)
{
	double x, v;

	for (x = a; x <= b; x += 1e-3) {
		v = f(x, a, b);
		assert(a <= v && v <= b);
	}
}

int
main(void)
{
	test(-10, 10);
	test(5, 60);
	test(-100, -50);
	test(0, 20);

	return 0;
}
