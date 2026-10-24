#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

double
solve(Point *p, size_t n)
{
	double x0, y0;
	double x1, y1;
	size_t i;

	x0 = y0 = DBL_MAX;
	x1 = y1 = -DBL_MAX;
	for (i = 0; i < n; i++) {
		x0 = fmin(x0, p[i].x);
		y0 = fmin(y0, p[i].y);
		x1 = fmax(x1, p[i].x);
		y1 = fmax(y1, p[i].y);
	}
	return (y1 - y0) * (x1 - x0);
}

int
main()
{
	Point p1[] = {
		{ -3, 5 },
		{ 7, 9 },
		{ 17, 5 },
	};

	Point p2[] = {
		{ 10, 10 },
		{ 10, 20 },
		{ 20, 20 },
		{ 20, 10 },
	};

	printf("%.4f\n", solve(p1, nelem(p1)));
	printf("%.4f\n", solve(p2, nelem(p2)));

	return 0;
}
