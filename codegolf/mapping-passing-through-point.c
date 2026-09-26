/*

(Inspired by this challenge.)

Given six real values in three pairs: (x1,x2), (y1,y2), and (x0,y0), where x1<x0<x2 and y1<y0<y2, create a function which maps between (x1,x2) and (y1,y2) which also passes through (x0,y0).
In other words, make some function

f:R→R,f((x1,x2))=(y1,y2),f(x0)=y0

Note that the image of the function has to be over the whole interval -- in other words, for every y∈(y1,y2), there must be some x∈(x1,x2), such that f(x)=y.

For example, for (x1,x2)=(0,10),(y1,y2)=(0,10),(x0,y0)=(4,2), a possible function is

0.5x         0 < x <= 4
-4/3x + 46/3 4 < x < 10

Which looks like:

https://i.stack.imgur.com/IYazQ.png

On the edge points (i.e. when x=x1 or x=x2) or outside of the interval, the function can have whatever value you want, or it can be undefined.

Note: You don't have to return a function -- you could also write your code so that it takes in x1,x2,y1,y2,x0,y0,x and returns y=f(x) following the constraints above.

Standard loopholes are forbidden. Since this is code-golf, the shortest function wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
poly(double *a, size_t n, double x)
{
	double r, p;
	size_t i;

	r = 0;
	p = 1;
	for (i = 0; i < n; i++) {
		r += a[i] * p;
		p *= x;
	}
	return r;
}

// https://magedkamel.com/2a-quadratic-interpolation/
void
quadfit(double x0, double y0, double x1, double y1, double x2, double y2, double a[3])
{
	double d0, d1, d2;

	d0 = (x2 - x0) * (x1 - x0);
	d1 = (x1 - x0) * (x2 - x1);
	d2 = (x2 - x0) * (x2 - x1);

	a[0] = y0 * (x1 * x2) / d0;
	a[0] += y1 * (-x0 * x2) / d1;
	a[0] += y2 * (x0 * x1) / d2;

	a[1] = y0 * -(x2 + x1) / d0;
	a[1] += y1 * (x2 + x0) / d1;
	a[1] += y2 * -(x1 + x0) / d2;

	a[2] = y0 / d0;
	a[2] += -y1 / d1;
	a[2] += y2 / d2;
}

void
test(double x0, double y0, double x1, double y1, double x2, double y2)
{
	static const double eps = 1e-8;
	double a[3];

	quadfit(x0, y0, x1, y1, x2, y2, a);
	printf("%.3f*x^2 + %.3f*x + %.3f\n", a[0], a[1], a[2]);
	assert(fabs(poly(a, nelem(a), x0) - y0) < eps);
	assert(fabs(poly(a, nelem(a), x1) - y1) < eps);
	assert(fabs(poly(a, nelem(a), x2) - y2) < eps);
}

int
main(void)
{
	test(0, 0, 4, 2, 10, 10);
	test(1, 1, 2, 2, 3, 3);
	test(13, 4, 5, 3, 10, 234);
	test(-10, -30, -59, -390, 194, 596);
	test(5, 3, 1, 6, 12, 5908);

	return 0;
}
