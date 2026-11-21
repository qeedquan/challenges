/*

Challenge:
To take two points on the plane and figure out the position of the point that's a) on the line that connects them, and b) equally distant from each of the original points.

Example:
(0,0), (3,3) -> (1.5,1.5)

(-1,-1), (1,1) -> (0,0)

(-7,3), (2,-2) -> (-2.5,0.5)

(3, 1), (-5,9) -> (-1,5)

Rules:
The input and output can be a tuple, array, list, or any other type of sequence.
There must be two inputs, each representing a point.
The output has to support floating point numbers.
Shortest solution in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

Point
pt(double x, double y)
{
	return (Point){x, y};
}

Point
center(Point a, Point b)
{
	return (Point){
	    (a.x + b.x) * 0.5,
	    (a.y + b.y) * 0.5,
	};
}

void
test(Point a, Point b, Point r)
{
	static const double eps = 1e-8;

	Point p;

	p = center(a, b);
	printf("%f %f\n", p.x, p.y);
	assert(fabs(p.x - r.x) < eps);
	assert(fabs(p.y - r.y) < eps);
}

int
main(void)
{
	test(pt(0, 0), pt(3, 3), pt(1.5, 1.5));
	test(pt(-1, -1), pt(1, 1), pt(0, 0));
	test(pt(-7, 3), pt(2, -2), pt(-2.5, 0.5));
	test(pt(3, 1), pt(-5, 9), pt(-1, 5));

	return 0;
}
