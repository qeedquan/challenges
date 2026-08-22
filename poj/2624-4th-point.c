/*

Description

Given are the (x,y) coordinates of the endpoints of two adjacent sides of a parallelogram. Find the (x,y) coordinates of the fourth point.
Input

Each line of input contains eight floating point numbers: the (x,y) coordinates of one of the endpoints of the first side followed by the (x,y) coordinates of the other endpoint of the first side, followed by the (x,y) coordinates of one of the endpoints of the second side followed by the (x,y) coordinates of the other endpoint of the second side. All coordinates are in meters, to the nearest mm. All coordinates are between -10000 and +10000.
Output

For each line of input, print the (x,y) coordinates of the fourth point of the parallelogram in meters, to the nearest mm, separated by a single space.

Sample Input

0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
1.000 0.000 3.500 3.500 3.500 3.500 0.000 1.000
1.866 0.000 3.127 3.543 3.127 3.543 1.412 3.145

Sample Output

1.000 0.000
-2.500 -2.500
0.151 -0.398

Source

The UofA Local 1999.10.16

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

bool
near(Point p, Point q)
{
	static const double eps = 1e-3;

	return fabs(p.x - q.x) < eps && fabs(p.y - q.y) < eps;
}

Point
fourth(Point a, Point b, Point c, Point d)
{
	Point r;

	if (near(a, c))
		r = (Point){b.x + d.x - a.x, b.y + d.y - a.y};
	else if (near(a, d))
		r = (Point){b.x + c.x - a.x, b.y + c.y - a.y};
	else if (near(b, c))
		r = (Point){a.x + d.x - b.x, a.y + d.y - b.y};
	else
		r = (Point){a.x + c.x - b.x, a.y + c.y - b.y};

	return r;
}

void
test(Point a, Point b, Point c, Point d, Point r)
{
	Point p;

	p = fourth(a, b, c, d);
	printf("%f %f\n", p.x, p.y);
	assert(near(p, r));
}

int
main(void)
{
	test((Point){0.000, 0.000},
	     (Point){0.000, 1.000},
	     (Point){0.000, 1.000},
	     (Point){1.000, 1.000},
	     (Point){1.000, 0.000});

	test((Point){1.000, 0.000},
	     (Point){3.500, 3.500},
	     (Point){3.500, 3.500},
	     (Point){0.000, 1.000},
	     (Point){-2.500, -2.500});

	test((Point){1.866, 0.000},
	     (Point){3.127, 3.543},
	     (Point){3.127, 3.543},
	     (Point){1.412, 3.145},
	     (Point){0.151, -0.398});

	return 0;
}
