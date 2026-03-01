/*

Given Points A, B, C ∈ ℤ2 and dA, dB, dC ∈ ℤ their respective squared euclidian distances to a certain point P ∈ ℤ2, return the value of P.

Note
A, B, and C will always be distinct and non-collinear

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

double
sqrdist(Point a, Point b)
{
	double dx, dy;

	dx = a.x - b.x;
	dy = a.y - b.y;
	return (dx * dx) + (dy * dy);
}

// https://math.stackexchange.com/questions/884807/find-x-location-using-3-known-x-y-location-using-trilateration
Point
trilaterate(Point a, double da, Point b, double db, Point c, double dc)
{
	double A, B, C, D, E, F;
	double x1, x2, x3;
	double y1, y2, y3;
	double r1, r2, r3;

	x1 = a.x;
	x2 = b.x;
	x3 = c.x;
	y1 = a.y;
	y2 = b.y;
	y3 = c.y;
	r1 = sqrt(da);
	r2 = sqrt(db);
	r3 = sqrt(dc);

	A = (-2 * x1) + (2 * x2);
	B = (-2 * y1) + (2 * y2);
	C = (r1 * r1) - (r2 * r2) - (x1 * x1) + (x2 * x2) - (y1 * y1) + (y2 * y2);
	D = (-2 * x2) + (2 * x3);
	E = (-2 * y2) + (2 * y3);
	F = (r2 * r2) - (r3 * r3) - (x2 * x2) + (x3 * x3) - (y2 * y2) + (y3 * y3);

	return (Point){
		.x = ((C * E) - (F * B)) / ((E * A) - (B * D)),
		.y = ((C * D) - (A * F)) / ((B * D) - (A * E)),
	};
}

void
test(Point a, Point b, Point c, Point r)
{
	static const double eps = 1e-12;

	double da, db, dc;
	Point p;

	da = sqrdist(a, r);
	db = sqrdist(b, r);
	dc = sqrdist(c, r);
	p = trilaterate(a, da, b, db, c, dc);

	printf("%.0f %.0f\n", p.x, p.y);

	assert(fabs(p.x - r.x) < eps);
	assert(fabs(p.y - r.y) < eps);
}

int
main()
{
	Point A[] = { { 0, 0 }, { 0, 0 }, { -1, 0 }, { -100, -100 }, { 3, 2 }, { -3, -2 } };
	Point B[] = { { 0, 1 }, { 3, 0 }, { 5, 6 }, { 1000, 20 }, { -5, -3 }, { 0, -1 } };
	Point C[] = { { 1, 0 }, { 3, 4 }, { 11, 3 }, { 0, 0 }, { -2, -1 }, { 1, 5 } };
	Point P[] = { { 1, 1 }, { 0, 4 }, { 8, 1 }, { 1, 5 }, { 1, -4 }, { 5, 0 } };

	size_t i;

	for (i = 0; i < nelem(A); i++)
		test(A[i], B[i], C[i], P[i]);

	return 0;
}
