/*

Laguerre polynomials are solutions to Laguerre's equation, a second-order linear differential equation: xy′′+(1−x)y′+ny=0.
For a given value of n, the solution, y, is named Ln(x).

The polynomials can be found without calculus using recursion:

L[0, x]   = 1
L[1, x]   = 1 - x
L[k+1, x] = ((2k + 1 - x)L[k, x] - kL[k-1, x]) / (k + 1)

Summation can be used to the same end:
L[n, x] = Sum[k=0, n] binomial(n, k) * (-1)^k/k! * x^k
L[n, x] = Sum[i=0, n] Prod[k=1, i] -(n-k+1)*x / k^2

The first Laguerre polynomials are as follows:
https://i.stack.imgur.com/LR4kc.png

Coefficients can be found here.

The Challenge
Given a nonnegative integer n and a real number x, find L[n, x].

Rules
This is code-golf so the shortest answer in bytes wins.

Assume only valid input will be given.

Error should be under one ten-thousandth (±0.0001) for the test cases.

Test Cases
Here, n is the first number and x is the second.

In: 1 2
Out: -1

In: 3 1.416
Out: -0.71360922

In: 4 8.6
Out: −7.63726667

In: 6 -2.1
Out: 91.86123261

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
L(int n, double x)
{
	double p, r;
	int i, k;

	r = 0;
	for (i = 0; i <= n; i++) {
		p = 1;
		for (k = 1; k <= i; k++)
			p *= -((n - k + 1) * x) / (k * k);

		r += p;
	}
	return r;
}

void
test(int n, double x, double r)
{
	double v;

	v = L(n, x);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-8);
}

int
main(void)
{
	test(1, 2, -1);
	test(3, 1.416, -0.71360922);
	test(4, 8.6, -7.63726667);
	test(6, -2.1, 91.86123261);

	return 0;
}
