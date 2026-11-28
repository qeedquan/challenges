/*

Task
There is a vine wrapped around a tree n times (from the bottom to the top). We know the height and the radius of the tree. Please, calculate the shortest possible length of the vine.

Note: for historical reasons the result should be additionally rounded to two decimal places in JavaScript; the examples below do not reflect this requirement, and show the expected length as is.

Examples
n = 2
h = 10
r = 1
length = 16.059690856844963

n = 5
h = 20
r = 0.5
length = 25.431085506270353

n = 3
h = 4
r = 5
length = 94.33262405435578

Hint
You can interpret the tree as a cylinder, and the vine as a line going from its bottom to its top. Turning the three-dimensional geometry into plane geometry can help you solve the problem.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
vinelength(double wraps, double height, double radius)
{
	return hypot(2 * M_PI * radius * wraps, height);
}

void
test(double wraps, double height, double radius, double expected)
{
	static const double eps = 1e-8;

	double length;

	length = vinelength(wraps, height, radius);
	printf("%f\n", length);
	assert(fabs(length - expected) < eps);
}

int
main()
{
	test(2, 10, 1, 16.059690856844963);
	test(5, 20, 0.5, 25.431085506270353);
	test(3, 4, 5, 94.33262405435578);
	return 0;
}
