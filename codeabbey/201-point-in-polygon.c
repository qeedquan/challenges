/*

https://codeabbey.github.io/data/point_in_polygon.png

You perhaps remember the problem about Frodo and Black Riders - there we were calculating area by Monte-Carlo method. However, then it was sufficiently easy to know whether point gets into area (visible to rider) or not.

In general the task of checking whether point falls into the given polygon is more complicated. And so here is the dedicated exercise for it :)

Input data consist of several parts:

in the first line there is a number N of the points described below;
then N lines follow with X and Y coordinates of the points - note that first and last are the same (i.e. they describe polygon with N-1 sides);
next follows the line containing M - the amount of sample points;
and then M lines provide you X and Y coordinates of these random points.
Answer should contain 1-based indices of the sample points which are inside the described polygon.

Note that all coordinates are integer for simplicity. Moreover, none of the sample points will have the same X-s or Y-s as any of polygon corners.

Example (for picture shown above):

input data:
10
10 5000
3000 9950
7000 9950
9990 5000
7000 50
5453 4819
6745 1403
7144 9311
3000 50
10 5000
12
8354 7354
8144 3649
2714 2749
9673 6106
179 7081
9202 3443
1859 8863
4940 4349
8856 9648
7692 5060
5101 2511
2052 2246

answer:
1 2 3 10 12

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	int x, y;
} Point;

int
cross(Point p1, Point p2, Point p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool
point_on_segment(Point p, Point p1, Point p2)
{
	if (!(min(p1.x, p2.x) <= p.x && p.x <= max(p1.x, p2.x)))
		return false;
	if (!(min(p1.y, p2.y) <= p.y && p.y <= max(p1.y, p2.y)))
		return false;
	return cross(p1, p2, p) == 0;
}

int
winding_number(Point *polygon, size_t npolygons, Point point)
{
	Point p1, p2;
	int winding;
	size_t i;

	winding = 0;
	for (i = 0; i < npolygons; i++) {
		p1 = polygon[i];
		p2 = polygon[(i + 1) % npolygons];

		if (point_on_segment(point, p1, p2))
			return 0;

		if (p1.y <= point.y) {
			if (p2.y > point.y && cross(p1, p2, point) > 0)
				winding++;
		} else {
			if (p2.y <= point.y && cross(p1, p2, point) < 0)
				winding--;
		}
	}
	return winding;
}

// https://www.geeksforgeeks.org/cpp/point-in-polygon-in-cpp/
bool
point_in_polygon(Point *polygon, size_t npolygons, Point point)
{
	return winding_number(polygon, npolygons, point) != 0;
}

void
solve(Point *polygon, size_t npolygons, Point *points, size_t npoints)
{
	size_t i;

	for (i = 0; i < npoints; i++) {
		if (point_in_polygon(polygon, npolygons, points[i]))
			printf("%zu ", i + 1);
	}
	printf("\n");
}

int
main()
{
	Point polygon[] = {
		{ 10, 5000 },
		{ 3000, 9950 },
		{ 7000, 9950 },
		{ 9990, 5000 },
		{ 7000, 50 },
		{ 5453, 4819 },
		{ 6745, 1403 },
		{ 7144, 9311 },
		{ 3000, 50 },
		{ 10, 5000 },
	};

	Point points[] = {
		{ 8354, 7354 },
		{ 8144, 3649 },
		{ 2714, 2749 },
		{ 9673, 6106 },
		{ 179, 7081 },
		{ 9202, 3443 },
		{ 1859, 8863 },
		{ 4940, 4349 },
		{ 8856, 9648 },
		{ 7692, 5060 },
		{ 5101, 2511 },
		{ 2052, 2246 },
	};

	solve(polygon, nelem(polygon), points, nelem(points));

	return 0;
}
