/*

My boss just told me to write a cosine function. Being a good math geek, my mind immediately conjured the appropriate Taylor Series.

cos(x) = 1/0! - x^2/2! + x^4/4! - x^6/6! + ... + (-1)^k*x^(2*k) / (2*k)!

However, my boss is very picky. He would like to be able to specify exactly how many terms of the Taylor Series to compute. Can you help me write this function?

Your Task
Given a floating point value x from 0 to 2π and a positive integer n less than 100, compute the sum of the first n terms of the Taylor series given above for cos(x).

This is code-golf, so shortest code wins. Input and output can be taken in any of the standard ways. Standard loopholes are forbidden.

Notes
Input can be taken in any reasonable form, as long as there is a clear separation between x and n.
Input and output should be floating-point values, at least as accurate as calculating the formula using single-precision IEEE floating point numbers with some standard rounding rule.
If it makes sense for the language being used, computations may be done using exact rational quantities, but the input and output shall still be in decimal form.

Examples
 x  |  n | Output
----+----+--------------
0.0 |  1 | 1.0
0.5 |  1 | 1.0
0.5 |  2 | 0.875
0.5 |  4 | 0.87758246...
0.5 |  9 | 0.87758256...
2.0 |  2 | -1.0
2.0 |  5 | -0.4158730...

*/

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

double taylor_cos(double x, int n)
{
	double y = 0.0;
	for (n = 2 * n; n > 0; n -= 2)
		y = 1 - (y * x * x) / (n * (n - 1));
	return y;
}

void test(double x, int n, double r)
{
	double y = taylor_cos(x, n);
	cout << y << endl;
	assert(fabs(y - r) < 1e-7);
}

int main()
{
	test(0, 1, 1);
	test(0.5, 1, 1);
	test(0.5, 2, 0.875);
	test(0.5, 4, 0.87758246);
	test(0.5, 9, 0.87758256);
	test(2, 2, -1);
	test(2, 5, -0.4158730);

	return 0;
}
