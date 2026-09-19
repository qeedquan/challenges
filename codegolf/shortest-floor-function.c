/*

Your task is to implement a floor function in as few bytes as possible.

A floor function is a function that takes a real number and returns the largest integer less than or equal to the input.

Your program should support both positive and negative inputs.
Since it is provably impossible to support all real numbers you need only support a reasonable subset of them.
This subset should include positive numbers, negative numbers and of course numbers that are not integers.
Such number systems include fixed-point numbers, floating point numbers and strings.

Your code may be a complete program or function.

This is code-golf so answers will be scored in bytes with less bytes being a better score.

*/

#include <assert.h>
#include <math.h>

long
xfloor(double x)
{
	long r;

	r = x;
	if (r > x)
		r -= 1;
	return r;
}

int
main()
{
	long i, n, x, y;

	n = 100000000;
	for (i = -n; i <= n; i++) {
		x = floor(i);
		y = xfloor(i);
		assert(x == y);
	}

	return 0;
}
