#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

double
distance(double x1, double x2, double y1, double y2)
{
	return hypot(x1 - x2, y1 - y2);
}

bool
inside(double x, double y, double z)
{
	if (distance(0, x, 0, y) > z)
		return false;
	if (distance(z, x, 0, y) > z)
		return false;
	if (distance(z, x, z, y) > z)
		return false;
	if (distance(0, x, z, y) > z)
		return false;
	return true;
}

double
area(Point *p, size_t n, double z)
{
	size_t i;
	double c;

	c = 0;
	for (i = 0; i < n; i++) {
		if (inside(p[i].x, p[i].y, z))
			c++;
	}
	return (c * z * z) / n;
}

void
test(Point *p, size_t n, double z, double r)
{
	double u;

	u = area(p, n, z);
	printf("%f\n", u);
	assert(fabs(u - r) < 1e-6);
}

int
main(void)
{
	Point p1[] = { { 5, 5 } };

	test(p1, nelem(p1), 10, 100);
	return 0;
}
