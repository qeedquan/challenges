/*

We want to approximate the length of a curve representing a function y = f(x) with  a <= x <= b.
First, we split the interval [a, b] into n sub-intervals with widths h1, h2, ... , hn by defining points x1, x2 , ... , xn-1 between a and b.
This defines points P0, P1, P2, ... , Pn on the curve whose x-coordinates are a, x1, x2 , ... , xn-1, b and y-coordinates f(a), f(x1), ..., f(xn-1), f(b).
By connecting these points, we obtain a polygonal path approximating the curve.

Our task is to approximate the length of a parabolic arc representing the curve y = x * x with x in the interval [0, 1].
We will take a common step h between the points xi: h1, h2, ... , hn = h = 1/n and we will consider the points P0, P1, P2, ... , Pn on the curve.
The coordinates of each Pi are (xi, yi = xi * xi).

The function len_curve (or similar in other languages) takes n as parameter (number of sub-intervals) and returns the length of the curve.

https://imgur.com/kyjJcE4

Note:
When you "Attempt" tests are done with a tolerance of 1e-06 (except in PureScript where you must truncate your result to 9 decimal places).

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
curvelength(int n)
{
	double a, b, r;
	int i;

	r = 0;
	for (i = 0; i < n; i++) {
		a = 1.0 / (n * n);
		b = (i + i + 1.0) / (n * n);
		r += sqrt(a + (b * b));
	}
	return r;
}

void
test(int n, double r)
{
	double l;

	l = curvelength(n);
	printf("%f\n", l);
	assert(fabs(l - r) < 1e-9);
}

int
main()
{
	test(1, 1.414213562);
	test(10, 1.478197397);
	return 0;
}
