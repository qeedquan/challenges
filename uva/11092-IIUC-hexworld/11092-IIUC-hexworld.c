#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define SQRT3 1.732050807568877293527446341505872366942805253810380628055806
#define SQRT3_2 (SQRT3 / 2)

typedef struct {
	double x, y;
} Point;

Point
pt(double x, double y)
{
	return (Point){ x, y };
}

Point
hexloc(int x)
{
	double cx, cy;
	int i;

	cx = cy = 0;
	for (i = 0; i < INT_MAX; i++) {
		if (x <= i * 6)
			break;

		cx += 0.5;
		cy -= SQRT3_2;
		x -= i * 6;
	}

	if (x == 0)
		return pt(cx, cy);

	x -= 1;
	cx += 0.5;
	cy += SQRT3_2;
	if (x < i) {
		cx += x * 0.5;
		cy += x * SQRT3_2;
		return pt(cx, cy);
	}

	x -= i;
	cx += (i - 2) * 0.5;
	cy += i * SQRT3_2;
	if (x < i) {
		cx -= x * 0.5;
		cy += x * SQRT3_2;
		return pt(cx, cy);
	}

	x -= i;
	cx -= (i - 1) * 0.5 + 1;
	cy += (i - 1) * SQRT3_2;
	if (x < i) {
		cx -= x;
		return pt(cx, cy);
	}

	x -= i;
	cx -= (i - 0.5);
	cy -= SQRT3_2;
	if (x < i) {
		cx -= x * 0.5;
		cy -= x * SQRT3_2;
		return pt(cx, cy);
	}

	x -= i;
	cx -= (i * 0.5 - 1);
	cy -= i * SQRT3_2;
	if (x < i) {
		cx += x * 0.5;
		cy -= x * SQRT3_2;
		return pt(cx, cy);
	}

	x -= i;
	cx += (i - 1) * 0.5 + 1;
	cy -= (i - 1) * SQRT3_2;

	cx += x;
	return pt(cx, cy);
}

double
hexdist(int A, int B)
{
	Point la, lb;

	la = hexloc(A);
	lb = hexloc(B);
	return hypot(la.x - lb.x, la.y - lb.y);
}

void
solve(int A, int B)
{
	int d1;
	double d2;

	d1 = abs(A - B);
	d2 = hexdist(A, B);
	printf("%d %.3f\n", d1, d2);
}

int
main()
{
	solve(1, 2);
	solve(1, 3);
	solve(1, 4);
	solve(1, 7);
	solve(1, 8);
	solve(1, 9);

	return 0;
}
