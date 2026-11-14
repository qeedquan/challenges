#include <stdio.h>
#include <math.h>

double
dist(double x1, double y1, double x2, double y2)
{
	return hypot(x1 - x2, y1 - y2);
}

double
solve(double ax, double ay, double bx, double by)
{
	double cx, cy;
	double dx, dy;

	cx = -bx;
	cy = by;
	dx = ax;
	dy = -ay;
	return dist(ax, ay, bx, by) + dist(cx, cy, dx, dy);
}

int
main()
{
	printf("%.3f\n", solve(3, 1, 1, 2));

	return 0;
}
