#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

double
sqr(double x)
{
	return x * x;
}

Point
circle(Point a, Point b, Point c)
{
	Point ab, ac, o;
	double a1, b1, c1;
	double a2, b2, c2;
	double D, D1, D2;

	ab.x = (a.x + b.x) / 2;
	ab.y = (a.y + b.y) / 2;
	ac.x = (a.x + c.x) / 2;
	ac.y = (a.y + c.y) / 2;
	a1 = a.x - b.x;
	b1 = a.y - b.y;
	c1 = (a1 * ab.x) + (b1 * ab.y);
	a2 = a.x - c.x;
	b2 = a.y - c.y;
	c2 = (a2 * ac.x) + (b2 * ac.y);
	D = (a1 * b2) - (a2 * b1);
	D1 = (c1 * b2) - (c2 * b1);
	D2 = (a1 * c2) - (a2 * c1);
	o.x = D1 / D;
	o.y = D2 / D;
	return o;
}

void
solve(Point a, Point b, Point c)
{
	double C, D, E, H, K;
	double r2;
	char c1, c2, c3;
	Point o;

	o = circle(a, b, c);
	r2 = sqr(a.x - o.x) + sqr(a.y - o.y);

	c1 = c2 = c3 = '+';
	if (o.x >= 0)
		c1 = '-';
	if (o.y >= 0)
		c2 = '-';
	if (r2 - sqr(o.x) - sqr(o.y) >= 0)
		c3 = '-';

	H = fabs(o.x);
	K = fabs(o.y);
	C = fabs(2 * o.x);
	D = fabs(2 * o.y);
	E = fabs(r2 - sqr(o.x) - sqr(o.y));
	printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", c1, H, c2, K, sqrt(r2));
	printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n", c1, C, c2, D, c3, E);
	puts("");
}

int
main()
{
	Point a1 = { 7, -5 };
	Point b1 = { -1, 1 };
	Point c1 = { 0, -6 };

	Point a2 = { 1, 7 };
	Point b2 = { 8, 6 };
	Point c2 = { 7, -2 };

	solve(a1, b1, c1);
	solve(a2, b2, c2);

	return 0;
}
