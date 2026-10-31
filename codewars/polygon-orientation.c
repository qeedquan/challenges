/*

The problem
Your task is simple: find out if a given polygon has clockwise or counter clockwise orientation.

Points will be represented as {X: x, Y: y} Cartesian coordinates.

The polygon will be an array of points which are the polygon's vertices. The last point in the array connects back to the first point.

The function will return true if the polygon's direction is clockwise and false otherwise.

You can assume:

The polygon will be a valid polygon. That is, it will have at least three points, and exactly two edges will meet at each vertex.
In the tests, the point will never fall exactly on an edge of the polygon.
Testing
To help you visualize your test cases, there is a method preloaded that draws the polygon:

showAndTest(poly, orientation) // which also calls Test.expect automatically
So if you call:

showAndTest([{X: 0, Y: 5}, {X: 5, Y: -5}, {X: -5, Y: -5}], true);
then you'll see:

    A

C       B

Clockwise

And if you call:

showAndTest([{X: -5, Y: 5}, {X: -5, Y: -5}, {X: 5, Y: -5}, {X: 5, Y: 5}], false);
then you'll see:


A     D


B     C

Counter-Clockwise

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

/*

https://stackoverflow.com/questions/1165647/how-to-determine-if-a-list-of-polygon-points-are-in-clockwise-order

@Beta

Here's a simple one that will work with non-convex polygons (it'll even work with a self-intersecting polygon like a figure-eight, telling you whether it's mostly clockwise).

Sum over the edges, (x2 - x1)(y2 + y1). If the result is positive the curve is clockwise, if it's negative the curve is counter-clockwise. (The result is twice the enclosed area, with a +/- convention.)

*/

bool
clockwise(Point *p, size_t n)
{
	Point *a, *b;
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		a = p + i;
		b = p + ((i + 1) % n);
		r += (b->x - a->x) * (b->y + a->y);
	}
	return r >= 0;
}

int
main()
{
	Point p1[] = {{0, 5}, {5, -5}, {-5, -5}};
	Point p2[] = {{-5, 5}, {-5, -5}, {5, -5}, {5, 5}};
	Point p3[] = {{5, 0}, {6, 4}, {4, 5}, {1, 5}, {1, 0}};

	assert(clockwise(p1, nelem(p1)) == true);
	assert(clockwise(p2, nelem(p2)) == false);
	assert(clockwise(p3, nelem(p3)) == false);

	return 0;
}
