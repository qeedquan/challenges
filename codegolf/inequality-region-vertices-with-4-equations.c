/*

Given the following inequalities:

ax + by <= c
dx + ey <= f
gx + hy <= i
jx + ky <= l

These inequalities enclose a region in the shape of a convex polygon.

Your goal is to output the vertices of this polygon. You need to report the coordinates with at least three significant places of accuracy.

A possible method is to take each pair of inequalities, solve for (x,y), and see if these x and y satisfy all four inequalities. This is a somewhat tedious process, however.

Some notes to make this easier:

Assume that there will be a region. That is, the region will have positive area, and there will be at least one pair (x,y) that satisfies all the inequalities.
Assume all the lines intersect with each other at some point (so none of the lines have the same slope).
From above, that means there will be at least three vertices.

Example case:

2.2x - 4.1y <= -0.87
2.15x - 2.2y <= -3.47
-7.5x + 4y <= 30
1x + 0.24y <= 0.47

The coordinates of this region are approximately:

(-0.91724, 5.78017) (0.07408, 1.64967) (-3.09761, -1.44994) (-5.4451, -2.70957)

Here is an image illustrating the region in the example:

https://i.sstatic.net/oTGEFVzAm.png

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

void
show(Point *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("[%.6f %.6f] ", p[i].x, p[i].y);
	printf("\n");
}

/*

@Ahamad

The idea is to loop through the inequalities and find lines that are not parallel lines to each other (the problem implies unique intersection points).
Find their intersection points for those pair of lines, and then check that it satisfies all of the inequalities imposed.
If all inequalities are satisfied, it is a boundary point of the convex polygon and we can add it to the solution set.

*/

size_t
region(double A[], double B[], double C[], size_t n, Point *h)
{
	static const double tol = 1e-9;

	size_t i, j, k, l;
	double d, v;
	Point p;

	for (i = l = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			d = (A[i] * B[j]) - (A[j] * B[i]);
			if (d == 0)
				continue;

			p.x = ((C[i] * B[j]) - (C[j] * B[i])) / d;
			p.y = ((C[j] * A[i]) - (C[i] * A[j])) / d;
			for (k = 0; k < n; k++) {
				v = (A[k] * p.x) + (B[k] * p.y);
				if (v > C[k] + tol)
					break;
			}
			if (k == n)
				h[l++] = p;
		}
	}
	return l;
}

void
test(double A[], double B[], double C[], size_t n)
{
	Point p[32];
	size_t l;

	l = region(A, B, C, n, p);
	show(p, l);
}

int
main()
{
	double A[] = { 2.2, 2.15, -7.5, 1.0 };
	double B[] = { -4.1, -2.2, 4.0, 0.24 };
	double C[] = { -0.87, -3.47, 30.0, 0.47 };

	test(A, B, C, nelem(A));
	return 0;
}
