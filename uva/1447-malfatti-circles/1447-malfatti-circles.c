#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

Point
add(Point a, Point b)
{
	return (Point){ a.x + b.x, a.y + b.y };
}

Point
scale(Point a, double s)
{
	return (Point){ a.x * s, a.y * s };
}

double
dist(Point a, Point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

double
wedge(Point o, Point a, Point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void
malfatti(Point A, Point B, Point C)
{
	double a, b, c, d, e, f;
	double r, s;
	double r1, r2, r3;
	Point incenter;

	a = dist(B, C);
	b = dist(A, C);
	c = dist(A, B);
	s = (a + b + c) / 2;

	incenter = add(scale(A, a), scale(B, b));
	incenter = add(incenter, scale(C, c));
	incenter = scale(incenter, 1 / (a + b + c));

	r = fabs(wedge(A, B, C)) / (a + b + c);
	d = dist(incenter, A);
	e = dist(incenter, B);
	f = dist(incenter, C);

	r1 = r * (s + d - r - e - f) / (2 * (s - a));
	r2 = r * (s + e - r - d - f) / (2 * (s - b));
	r3 = r * (s + f - r - d - e) / (2 * (s - c));

	printf("%.6lf %.6lf %.6lf\n", r1, r2, r3);
}

int
main()
{
	Point A1 = { 20, 80 };
	Point B1 = { -40, -20 };
	Point C1 = { 120, -20 };

	Point A2 = { 20, -20 };
	Point B2 = { 120, -20 };
	Point C2 = { -40, 80 };

	Point A3 = { 0, 0 };
	Point B3 = { 1, 0 };
	Point C3 = { 0, 1 };

	Point A4 = { 0, 0 };
	Point B4 = { 999, 1 };
	Point C4 = { -999, 1 };

	Point A5 = { 897, -916 };
	Point B5 = { 847, -972 };
	Point C5 = { 890, -925 };

	Point A6 = { 999, 999 };
	Point B6 = { -999, -998 };
	Point C6 = { -998, -999 };

	Point A7 = { -999, -999 };
	Point B7 = { 999, -999 };
	Point C7 = { 0, 731 };

	Point A8 = { -999, -999 };
	Point B8 = { 999, -464 };
	Point C8 = { -464, 999 };

	Point A9 = { 979, -436 };
	Point B9 = { -955, -337 };
	Point C9 = { 157, -439 };

	malfatti(A1, B1, C1);
	malfatti(A2, B2, C2);
	malfatti(A3, B3, C3);
	malfatti(A4, B4, C4);
	malfatti(A5, B5, C5);
	malfatti(A6, B6, C6);
	malfatti(A7, B7, C7);
	malfatti(A8, B8, C8);
	malfatti(A9, B9, C9);

	return 0;
}
