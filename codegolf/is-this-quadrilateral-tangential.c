/*

Background
A tangential quadrilateral is a quadrilateral which has an incircle:

https://i.stack.imgur.com/v1HIp.gif

Examples include any square, rhombus, or a kite-like shape. Rectangles or parallelograms in general are not tangential.

Task
Given the four vertices of a quadrilateral (as Cartesian coordinates), determine if it is tangential.

Input & output
For input, it is allowed to use any format that unambiguously specifies the four vertices' coordinates (eight real or floating-point numbers). You can assume the following on the input:

The points specify a simple convex quadrilateral, i.e. all internal angles are strictly less than 180 degrees, and the edges meet only at the vertices.
The points are specified in counter-clockwise order (or the other way around if you want).
For output, you can use one of the following:

Truthy/falsy values as defined by your language of choice (swapping the two is allowed), or
Two consistent values for true/false respectively.
It is acceptable if your code produces wrong output due to floating-point inaccuracies.

Test cases

Tangential
(0, 0), (0, 1), (1, 1), (1, 0)  # unit square
(-2, 0), (0, 1), (2, 0), (0, -1)  # rhombus
(1, -2), (-2, -1), (-1, 2), (4, 2)  # kite
(0, 0), (50, 120), (50, 0), (32, -24)  # all four sides different
Not tangential
(0, 0), (0, 1), (2, 1), (2, 0)  # rectangle
(0, 0), (1, 1), (3, 1), (2, 0)  # parallelogram
Scoring & winning criterion
Standard code-golf rules apply. The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdbool.h>
#include <complex.h>

typedef complex int Point;

Point
pt(int x, int y)
{
	return x + (y * I);
}

/*

https://mathworld.wolfram.com/TangentialQuadrilateral.html

A quadrilateral which has an incircle, i.e., one for which a single circle can be constructed which is tangent to all four sides
Opposite sides of such a quadrilateral satisfy s=a+c=b+d

Since points are passed in ccw order, we can just subtract them to get the side lengths

*/

bool
tangential(Point a, Point b, Point c, Point d)
{
	double u, v;

	u = cabs(a - b) + cabs(c - d);
	v = cabs(b - c) + cabs(d - a);
	return u == v;
}

int
main(void)
{
	assert(tangential(pt(0, 0), pt(0, 1), pt(1, 1), pt(1, 0)) == true);
	assert(tangential(pt(-2, 0), pt(0, 1), pt(2, 0), pt(0, -1)) == true);
	assert(tangential(pt(1, -2), pt(-2, -1), pt(-1, 2), pt(4, 2)) == true);
	assert(tangential(pt(0, 0), pt(50, 120), pt(50, 0), pt(32, -24)) == true);

	assert(tangential(pt(0, 0), pt(0, 1), pt(2, 1), pt(2, 0)) == false);
	assert(tangential(pt(0, 0), pt(1, 1), pt(3, 1), pt(2, 0)) == false);

	return 0;
}
