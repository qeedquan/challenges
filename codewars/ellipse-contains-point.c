/*

You are given a length of string and two thumbtacks.
On thumbtack goes into the focus point F₀ with coordinates x₀ and y₀, and the other does into point F₁ with points x₁ and y₁.
The string is then tied at the ends to the thumbtacks and has length l excluding the knots at the ends.
If you pull the string taught with a pencil and draw around the plane you'll have an ellipse with focuses at F₀ and F₁.
Given a new point P, determine if it falls inside of the ellipse.

You must write a function that takes arguments f0, f1, l, and p and returns true or false depending on whether or not p falls inside the ellipse.

Each of f0, f1, and p has has properties x and y for its coordinates.

You will never be given the case where the string is too short to reach between the points.

*/

#include <assert.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

Point
pt(double x, double y)
{
	return (Point){ x, y };
}

bool
contains(Point f0, Point f1, double l, Point p)
{
	return hypot(p.x - f0.x, p.y - f0.y) + hypot(p.x - f1.x, p.y - f1.y) <= l;
}

int
main()
{
	assert(contains(pt(0, 0), pt(0, 0), 2, pt(0, 0)) == true);
	assert(contains(pt(0, 0), pt(0, 0), 2, pt(1, 1)) == false);

	return 0;
}
