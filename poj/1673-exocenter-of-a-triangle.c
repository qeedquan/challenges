/*

Description

Given a triangle ABC, the Extriangles of ABC are constructed as follows:
On each side of ABC, construct a square (ABDE, BCHJ and ACFG in the figure below).
Connect adjacent square corners to form the three Extriangles (AGD, BEJ and CFH in the figure).
The Exomedians of ABC are the medians of the Extriangles, which pass through vertices of the original triangle,extended into the original triangle (LAO, MBO and NCO in the figure. As the figure indicates, the three Exomedians intersect at a common point called the Exocenter (point O in the figure).
This problem is to write a program to compute the Exocenters of triangles.

http://poj.org/images/1673_1.jpg

Input

The first line of the input consists of a positive integer n, which is the number of datasets that follow. Each dataset consists of 3 lines; each line contains two floating point values which represent the (two -dimensional) coordinate of one vertex of a triangle.
So, there are total of (n*3) + 1 lines of input.
Note: All input triangles will be strongly non-degenerate in that no vertex will be within one unit of the line through the other two vertices.

Output

For each dataset you must print out the coordinates of the Exocenter of the input triangle correct to four decimal places.

Sample Input

2
0.0 0.0
9.0 12.0
14.0 0.0
3.0 4.0
13.0 19.0
2.0 -10.0

Sample Output

9.0000 3.7500
-48.0400 23.3600

Source

Greater New York 2003


*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

typedef struct {
	Point a, b;
} Line;

Point
intersection(Line u, Line v)
{
	Point p;
	double t;

	p = u.a;
	t = ((u.a.x - v.a.x) * (v.a.y - v.b.y) - (u.a.y - v.a.y) * (v.a.x - v.b.x)) /
	    ((u.a.x - u.b.x) * (v.a.y - v.b.y) - (u.a.y - u.b.y) * (v.a.x - v.b.x));
	p.x += (u.b.x - u.a.x) * t;
	p.y += (u.b.y - u.a.y) * t;
	return p;
}

Point
exocenter(Point a, Point b, Point c)
{
	Line u, v;

	u.a = c;
	u.b.x = u.a.x - a.y + b.y;
	u.b.y = u.a.y + a.x - b.x;

	v.a = b;
	v.b.x = v.a.x - a.y + c.y;
	v.b.y = v.a.y + a.x - c.x;

	return intersection(u, v);
}

void
test(Point v[3], Point r)
{
	static const double eps = 1e-8;
	Point p;

	p = exocenter(v[0], v[1], v[2]);
	printf("%f %f\n", p.x, p.y);
	assert(fabs(p.x - r.x) < eps);
	assert(fabs(p.y - r.y) < eps);
}

int
main(void)
{
	Point v1[] = {{0, 0}, {9, 12}, {14, 0}};
	Point r1 = {9, 3.75};

	Point v2[] = {{3, 4}, {13, 19}, {2, -10}};
	Point r2 = {-48.0400, 23.3600};

	test(v1, r1);
	test(v2, r2);

	return 0;
}
