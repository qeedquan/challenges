/*

Description

When a thin rod of length L is heated n degrees, it expands to a new length L'=(1+n*C)*L, where C is the coefficient of heat expansion.
When a thin rod is mounted on two solid walls and then heated, it expands and takes the shape of a circular segment, the original rod being the chord of the segment.

Your task is to compute the distance by which the center of the rod is displaced.

Input

The input contains multiple lines. Each line of input contains three non-negative numbers: the initial lenth of the rod in millimeters, the temperature change in degrees and the coefficient of heat expansion of the material. Input data guarantee that no rod expands by more than one half of its original length. The last line of input contains three negative numbers and it should not be processed.

Output

For each line of input, output one line with the displacement of the center of the rod in millimeters with 3 digits of precision.

Sample Input

1000 100 0.0001
15000 10 0.00006
10 0 0.001
-1 -1 -1

Sample Output

61.329
225.020
0.000

Source

Waterloo local 2004.06.12

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
displacement(double l, double n, double c)
{
	static const double eps = 1e-12;

	double lo, hi;
	double lp, x, v, r;

	lo = 0;
	hi = M_PI / 2;
	lp = (1 + (n * c)) * l;
	while (hi - lo >= eps) {
		x = (lo + hi) / 2;
		v = l * x / sin(x);
		if (v >= lp)
			hi = x;
		else
			lo = x;
	}
	r = lp / (2 * x);
	r = r - (r * cos(x));
	return r;
}

void
test(double l, double n, double c, double r)
{
	double v;

	v = displacement(l, n, c);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	test(1000, 100, 0.0001, 61.329);
	test(15000, 10, 0.00006, 225.020);
	test(10, 0, 0.001, 0);

	return 0;
}
