/*

Railway is a broken line of N segments. The problem is to find such a position for the railway station
that the distance from it to the given point M is the minimal.

Input
The input will consist of several input blocks. Each input block begins with two lines with coordinates
Xm and Ym of the point M. In the third line there is N — the number of broken line segments.
The next 2N + 2 lines contain the X and the Y coordinates of consecutive broken line corners.
The input is terminated by EOF.

Output
For each input block there should be two output lines. The first one contains the first coordinate of
the station position, the second one contains the second coordinate. Coordinates are the floating-point
values with four digits after decimal point.

Sample Input
6
-3
3
0
1
5
5
9
-5
15
3
0
0
1
1
0
2
0

Sample Output
7.8966
-2.2414
1.0000
0.0000

*/

#include <stdio.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

typedef Point Vector;

Vector
sub(Point p1, Point p2)
{
	return (Vector){ p2.x - p1.x, p2.y - p1.y };
}

Vector
scale(Vector v, double s)
{
	return (Vector){ v.x * s, v.y * s };
}

Point
translate(Point p, Vector v)
{
	return (Point){ p.x + v.x, p.y + v.y };
}

double
dot(Vector v1, Vector v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

double
distance(Point p1, Point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double
distance_to_line(Point p, Point a, Point b, Point *c)
{
	Vector ap, ab;
	double u;

	ap = sub(a, p);
	ab = sub(a, b);
	u = dot(ap, ab) / dot(ab, ab);
	*c = translate(a, scale(ab, u));
	return distance(p, *c);
}

double
distance_to_line_segment(Point p, Point a, Point b, Point *c)
{
	Vector ap, ab;
	double u;

	ap = sub(a, p);
	ab = sub(a, b);
	u = dot(ap, ab) / dot(ab, ab);

	if (u < 0.0) {
		*c = a;
		return distance(p, a);
	}

	if (u > 1.0) {
		*c = b;
		return distance(p, b);
	}

	return distance_to_line(p, a, b, c);
}

Point
solve(Point station, Point *segments, size_t num_segments)
{
	Point location;
	Point bestp;
	double best;
	double distance;
	size_t i;

	best = DBL_MAX;
	bestp = (Point){};
	for (i = 1; i < num_segments; i++) {
		distance = distance_to_line_segment(station, segments[i - 1], segments[i], &location);
		if (distance < best) {
			best = distance;
			bestp = location;
		}
	}
	return bestp;
}

void
test(Point station, Point *segments, size_t num_segments)
{
	Point result;

	result = solve(station, segments, num_segments);
	printf("%.4f %.4f\n", result.x, result.y);
}

int
main()
{
	Point segments1[] = { { 0, 1 }, { 5, 5 }, { 9, -5 }, { 15, 3 } };
	Point segments2[] = { { 1, 0 }, { 2, 0 } };

	Point station1 = { 6, -3 };
	Point station2 = { 0, 0 };

	test(station1, segments1, nelem(segments1));
	test(station2, segments2, nelem(segments2));

	return 0;
}
