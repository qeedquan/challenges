/*

Create a function that takes three numbers as arguments and returns true if it's a triangle and false if not.
Examples

isTriangle(2, 3, 4) ➞ true

isTriangle(3, 4, 5) ➞ true

isTriangle(4, 3, 8) ➞ false

Notes

    a, b and, c are the side lengths of the triangles.
    Test input will always be three positive numbers.

*/

#include <assert.h>

void
swapu(unsigned *a, unsigned *b)
{
	unsigned t;

	t = *a;
	*a = *b;
	*b = t;
}

bool
triangle(unsigned a, unsigned b, unsigned c)
{
	if (a > b)
		swapu(&a, &b);
	if (a > c)
		swapu(&a, &c);
	if (b > c)
		swapu(&b, &c);
	return c < a + b;
}

int
main(void)
{
	assert(triangle(1, 1, 1) == true);
	assert(triangle(1, 2, 3) == false);
	assert(triangle(2, 1, 3) == false);
	assert(triangle(1, 3, 2) == false);
	assert(triangle(3, 2, 1) == false);
	assert(triangle(3, 1, 2) == false);
	assert(triangle(2, 2, 2) == true);
	assert(triangle(3, 4, 5) == true);
	assert(triangle(3, 5, 4) == true);
	assert(triangle(5, 3, 4) == true);
	assert(triangle(5, 4, 3) == true);
	assert(triangle(10, 9, 3) == true);
	assert(triangle(100, 10, 10) == false);
	assert(triangle(2, 3, 4) == true);
	assert(triangle(3, 4, 5) == true);
	assert(triangle(4, 3, 8) == false);
	assert(triangle(4, 5, 6) == true);
	assert(triangle(3, 4, 6) == true);
	assert(triangle(2, 5, 7) == false);
	assert(triangle(2, 5, 9) == false);
	assert(triangle(2, 9, 5) == false);
	assert(triangle(9, 2, 5) == false);
	assert(triangle(11, 12, 20) == true);
	assert(triangle(14, 3, 12) == true);
	assert(triangle(23, 4, 28) == false);
	assert(triangle(21, 4, 25) == false);

	return 0;
}
