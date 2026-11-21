/*

Euclidean distance between two lattice points (x1,y1) and (x2,y2)
sqrt((x1-x2)^2 + (y1-y2)^2)

Imagine now a lattice N x N replicated infinitely many times next to itself. The two points (x1,y1) and (x2,y2) also get replicated. Euclidean distance on a torus is then the minimal distance between all these points.

Input: x1, y1, x2, y2 and N. Arrange these in any convenient order or way (e.g. represent (3,4), (5,6) as 4 arguments 3, 4, 5, 6, two complex numbers 3+4j, 5+6j, a list [[3,4],[5,6]], a list [3,4,5,6] or anything that's not too bizarre).
Coordinates must be integers in the range 0..N-1 or 1..N. The size of the torus (N) must be an integer (you can assume 1 < N < 100).

Output: a real number, with precision better than 1%.

Test cases:

x1	y1	x2	y2	N	Result
1	0	1	1	2	1.00
2	3	2	3	4	0.00
0	0	2	2	4	2.83
0	9	1	1	10	2.24
9	0	9	8	10	2.00
12	34	56	78	99	62.23
0	0	98	98	99	1.41

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
distance(double x1, double y1, double x2, double y2, double n)
{
	double dx, dy;
	double tx, ty;

	dx = fabs(x1 - x2);
	dy = fabs(y1 - y2);

	tx = fmin(dx, n - dx);
	ty = fmin(dy, n - dy);

	return hypot(tx, ty);
}

void
test(double x1, double y1, double x2, double y2, double n, double r)
{
	double d;

	d = distance(x1, y1, x2, y2, n);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-2);
}

int
main(void)
{
	test(1, 0, 1, 1, 2, 1);
	test(2, 3, 2, 3, 4, 0);
	test(0, 0, 2, 2, 4, 2.83);
	test(0, 9, 1, 1, 10, 2.24);
	test(9, 0, 9, 8, 10, 2.00);
	test(12, 34, 56, 78, 99, 62.23);
	test(0, 0, 98, 98, 99, 1.41);

	return 0;
}
