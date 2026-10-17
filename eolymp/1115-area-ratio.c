/*

Given the coordinates of the vertices of a triangle in space,
find the ratio of the area of the circle inscribed in the triangle to the area of the circle circumscribed about the triangle.

https://static.e-olymp.com/content/b4/b4538b26fa0c6ebde083fe841b7ce6e36c1e5280.jpg

Input
Each line contains 9 integers x1, y1, z1, x2, y2, z2, x3, y3, z3
(−1000≤xi,yi,zi ≤1000) — the coordinates of the vertices of the triangle. No three points are collinear.

Output
For each test case, print the required ratio on a separate line with three decimal digits.
If rounding to the given accuracy results in zero, print the message Zero! (without quotes).

Examples

Input #1
0 0 0 0 0 1 0 1 0

Answer #1
0.172

*/

#include <stdio.h>
#include <math.h>

double
sqr(double x)
{
	return x * x;
}

double
len(int x1, int y1, int z1, int x2, int y2, int z2)
{
	return sqrt(sqr(x2 - x1) + sqr(y2 - y1) + sqr(z2 - z1));
}

double
solve(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3)
{
	double a, c, b, p;
	double r, R;

	a = len(x1, y1, z1, x2, y2, z2);
	b = len(x2, y2, z2, x3, y3, z3);
	c = len(x3, y3, z3, x1, y1, z1);
	p = (a + b + c) / 2;
	r = sqrt((p - a) * (p - b) * (p - c) / p);
	R = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
	return sqr(r) / sqr(R);
}

int
main()
{
	printf("%.3f\n", solve(0, 0, 0, 0, 0, 1, 0, 1, 0));

	return 0;
}
