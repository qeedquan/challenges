/*

Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

There are at least 3 and at most 10,000 points. Coordinates are in the range -10,000 to 10,000. You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.

Example 1:

[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Example 2:

[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

int
cross(Point p, Point q, Point r)
{
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

bool
isconvex(Point *p, size_t n)
{
	size_t i;
	int c, s;

	if (n < 3)
		return false;

	s = 0;
	for (i = 0; i < n; i++) {
		c = cross(p[i], p[(i + 1) % n], p[(i + 2) % n]);
		if (c == 0)
			continue;

		if (s == 0)
			s = c;
		else if (c * s < 0)
			return false;
	}
	return true;
}

int
main(void)
{
	Point p1[] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
	Point p2[] = {{0, 0}, {0, 10}, {10, 10}, {10, 0}, {5, 5}};
	Point p3[] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
	Point p4[] = {{0, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

	assert(isconvex(p1, nelem(p1)) == true);
	assert(isconvex(p2, nelem(p2)) == false);
	assert(isconvex(p3, nelem(p3)) == true);
	assert(isconvex(p4, nelem(p4)) == false);

	return 0;
}
