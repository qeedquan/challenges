/*

You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y).
You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi).
A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location.
If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.

The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).

Example 1:

Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
Output: 2
Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location,
with a distance of 1. [2,4] has the smallest index, so return 2.

Example 2:

Input: x = 3, y = 4, points = [[3,4]]
Output: 0
Explanation: The answer is allowed to be on the same location as your current location.

Example 3:

Input: x = 3, y = 4, points = [[2,3]]
Output: -1
Explanation: There are no valid points.

Constraints:

    1 <= points.length <= 10^4
    points[i].length == 2
    1 <= x, y, ai, bi <= 10^4

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

int
manhattan(Point a, Point b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

ssize_t
nearest(Point p, Point *a, size_t n)
{
	int d, v;
	size_t i;
	ssize_t r;

	r = -1;
	d = INT_MAX;
	for (i = 0; i < n; i++) {
		if (p.x != a[i].x && p.y != a[i].y)
			continue;

		v = manhattan(p, a[i]);
		if (v < d) {
			r = i;
			d = v;
		}
	}
	return r;
}

int
main(void)
{
	Point a1[] = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
	Point p1 = {3, 4};

	Point a2[] = {{3, 4}};
	Point p2 = {3, 4};

	Point a3[] = {{2, 3}};
	Point p3 = {3, 4};

	assert(nearest(p1, a1, nelem(a1)) == 2);
	assert(nearest(p2, a2, nelem(a2)) == 0);
	assert(nearest(p3, a3, nelem(a3)) == -1);

	return 0;
}
