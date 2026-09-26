/*

A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.

*/

#include <assert.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
isboomerang(Point a, Point b, Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) != 0;
}

int
main(void)
{
	Point p1[3] = {
		{ 1, 1 },
		{ 2, 3 },
		{ 3, 2 },
	};

	Point p2[3] = {
		{ 1, 1 },
		{ 2, 2 },
		{ 3, 3 },
	};

	assert(isboomerang(p1[0], p1[1], p1[2]) == true);
	assert(isboomerang(p2[0], p2[1], p2[2]) == false);

	return 0;
}
