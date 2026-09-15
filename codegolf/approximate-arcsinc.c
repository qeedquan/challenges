/*

The goal is simple: Output a nonzero real solution x to the equation sin(x) = -mx, given input m, in the fewest number of bytes.

Specifications:

Your answer must be correct to 3 significant figures.
You may output any real solution other than the trivial solution x=0. You can assume m is such that at least one solution exists. You may also assume m!=0.
An obviously suboptimal python solution using gradient descent:

from math import *
from random import *
a=x=0.001
m = 5.
def dE(x):return 2*(sin(x)+m*x+1)*(cos(x)+m)
for i in xrange(1000): x-=dE(x)*a
print x
Test cases

-0.25 -> ±2.4746
-0.1  -> ±2.8523 or ±7.0682 or ±8.4232
 0.2  -> ±4.1046 or ±4.9063

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
arcsinc(double m)
{
	double x, y;

	x = 1;
	do {
		y = sin(x) + (m * x);
		x += y;
	} while (fabs(y) > 1e-8);

	return x;
}

void
test(double m, double r)
{
	double x;

	x = arcsinc(m);
	printf("%f\n", x);
	assert(fabs(x - fabs(r)) < 1e-4);
}

int
main(void)
{
	test(-0.25, 2.4746);
	test(-0.1, 2.8523);
	test(0.2, 4.1046);

	return 0;
}
