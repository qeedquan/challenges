/*

This series of katas will introduce you to basics of doing geometry with computers.

Point objects have x, y attributes. Triangle objects have attributes a, b, c describing their corners, each of them is a Point.

Write a function calculating area of a Triangle defined this way.

Tests round answers to 6 decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

typedef struct {
	Point a, b, c;
} Triangle;

double
det3x3(double m[3][3])
{
	double c00, c01, c02;

	c00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	c01 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
	c02 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	return (m[0][0] * c00) + (m[0][1] * c01) + (m[0][2] * c02);
}

double
area(Triangle *t)
{
	double m[3][3] = {
	    {t->a.x, t->a.y, 1},
	    {t->b.x, t->b.y, 1},
	    {t->c.x, t->c.y, 1},
	};
	return fabs(0.5 * det3x3(m));
}

void
test(Triangle *t, double r)
{
	double v;

	v = area(t);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-6);
}

int
main()
{
	Triangle t1 = {
	    {10, 10},
	    {40, 10},
	    {10, 50},
	};

	Triangle t2 = {
	    {15, -10},
	    {40, 20},
	    {20, 50},
	};

	test(&t1, 600);
	test(&t2, 675);

	return 0;
}
