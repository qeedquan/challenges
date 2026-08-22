/*

https://static.eolymp.com/content/1a/1a274ceccb52211fcef916274c94b59d970b441a.png

Determine at how many points two circles intersect.

Input
Six real numbers x1, y1, r1, x2, y2, r2 where x1, y1, x2, y2 are the coordinates of the centers of the circles,
and r1, r2 are their radii.

All numbers are real, do not exceed 10^9 in absolute value, and are given with at most 3 decimal places.

Output
Output a single number — the number of intersection points. If the number of intersection points is infinite, output -1.

Examples

Input #1
0 0 5 5 0 1

Answer #1
2

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

bool
eq(double x, double y)
{
	static const double eps = 1e-3;

	return fabs(x - y) < eps;
}

/*

https://lucidar.me/en/mathematics/how-to-calculate-the-intersection-points-of-two-circles/

d = sqrt((x2-x1)^2 + (y2-y1)^2)

if d > r1 + r2 the circles are too far apart and do not intersect;
if d < |r1 - r2| one circle is inside the other and do not intersect;
if d = 0 and r1 = r2 the circles are merged and there are an infinite number of points of intersection;
if d = r1 + r2 there is a single intersection point;
if d = r1 - r2 or d = r2 - r1 there is a single intersection point, but one circle in inside the other;
if d < r1 + r2 there are two intersection points.

*/

int
solve(double x1, double y1, double r1, double x2, double y2, double r2)
{
	double d;

	d = hypot(x2 - x1, y2 - y1);
	if (eq(d, 0) && eq(r1, r2))
		return -1;
	if (eq(d, r1 + r2))
		return 1;
	if (eq(d, fabs(r1 - r2)))
		return 1;
	if (d > r1 + r2)
		return 0;
	if (d < fabs(r1 - r2))
		return 0;
	if (d < r1 + r2)
		return 2;
	return 0;
}

int
main()
{
	assert(solve(0, 0, 5, 5, 0, 1) == 2);

	return 0;
}
