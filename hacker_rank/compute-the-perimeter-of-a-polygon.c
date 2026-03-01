/*

You are given the cartesian coordinates of a set of points in a 2D plane. When traversed sequentially, these points form a Polygon, P, which is not self-intersecting in nature. Can you compute the perimeter of polygon P?

Input Format

The first line contains an integer, N, denoting the number of points.
The N subsequent lines each contain 2 space-separated integers denoting the respective x and y coordinates of a point.

Constraints

No 2 points are coincident, and polygon P is obtained by traversing the points in a clockwise direction.
3 <= N <= 1000
0 <= x, y <= 1000

Output Format

For each test case, print the perimeter of P (correct to a scale of one decimal place).

Note: Do not add any leading/trailing spaces or units.

Sample Input

4
0 0
0 1
1 1
1 0

Sample Output

4

Explanation

The given polygon is a square, and each of its sides are 1 unit in length.
perimeter(P) = 1 + 1 + 1 + 1 = 4, so we print 4 on a new line.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

double
distance(Point a, Point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

double
perimeter(Point *p, size_t n)
{
	double r;
	size_t i;

	r = 0;
	for (i = 1; i <= n; i++)
		r += distance(p[i % n], p[i - 1]);
	return r;
}

void
test(Point *p, size_t n, double r)
{
	static const double eps = 1e-8;
	double x;

	x = perimeter(p, n);
	printf("%f\n", x);
	assert(fabs(x - r) < eps);
}

int
main()
{
	Point p1[] = {
	    {0, 0},
	    {0, 1},
	    {1, 1},
	    {1, 0},
	};

	test(p1, nelem(p1), 4);

	return 0;
}
