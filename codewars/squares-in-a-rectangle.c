/*

A rectangle can be split up into a grid of 1x1 squares, the amount of which being equal to the product of the two dimensions of the rectangle.
Depending on the size of the rectangle, that grid of 1x1 squares can also be split up into larger squares, for example a 3x2 rectangle has a total of 8 squares, as there are 6 distinct 1x1 squares, and two possible 2x2 squares.
A 4x3 rectangle contains 20 squares.
Your task is to write a function findSquares that returns the total number of squares for any given rectangle, the dimensions of which being given as two integers with the first always being equal to or greater than the second.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

// https://oeis.org/A000217
vlong
triangular(vlong n)
{
	return n * (n + 1) / 2;
}

// https://oeis.org/A000330
vlong
pyramidal(vlong n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

vlong
fsqbf(vlong x, vlong y)
{
	vlong r;

	if (x < y || y < 0)
		return 0;

	for (r = 0; y > 0;) {
		r += x * y;
		x -= 1;
		y -= 1;
	}
	return r;
}

vlong
fsq(vlong x, vlong y)
{
	vlong z, w;

	if (x < y || y < 0)
		return 0;

	z = triangular(y - 1);
	w = pyramidal(y - 1);
	return (x * y * y) - (x * z) - (y * z) + w;
}

int
main()
{
	vlong n, x, y;

	assert(fsq(3, 2) == 8);
	assert(fsq(4, 3) == 20);
	assert(fsq(11, 4) == 100);

	n = 5000;
	for (y = 0; y <= n; y++) {
		for (x = 0; x <= n; x++) {
			assert(fsq(x, y) == fsqbf(x, y));
		}
	}

	return 0;
}
