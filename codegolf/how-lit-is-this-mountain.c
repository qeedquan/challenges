/*

A mountain is defined to be a set of line segments whose first point has coordinates (0,a) where a > 0, and whose last point has coordinates (b,0), where b > 0. All intermediate points have a y-coordinate (ordinate) strictly greater than 0. You are given the points on the mountain sorted in ascending order of x-coordinate (abscissa). Note that two points can have the same x-coordinate, producing a vertical segment of the mountain. If you are given two points with the same x-coordinate, they should be connected in the order they are given. In addition, there can be horizontal segments of the mountain These horizontal segments are not lit, no matter what. All coordinates are nonnegative integers.

The question: what is the total length of the mountain that would be lit, assuming the sun is an infinite vertical plane of light located to the right of the mountain? This number does not need to be rounded, but if it is rounded, include at least four decimal places. I have included a picture:

https://i.sstatic.net/JsPyz.jpg

Here, the lines that are bolded represent the segments that are lit. Note that in the input, P appears before Q (PQ is a vertical line segment) so the previous point is connected to P and not Q.

You may take input in any reasonable format, like a list of lists, a single list, a string, etc.

Test case:

(0,3000)
(500, 3500)
(2500, 1000)
(5000,5000)
(9000,2000)
(9000,3500)
(10200,0)

Output: 6200.0000
There are two lit-up segments here, as shown in this image:

https://i.sstatic.net/bUCbM.png

The first one has length 5000/2 = 2500 and the second one has length 3700.

This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

double
lit(Point *p, size_t n)
{
	double l, m;
	Point *a, *b;
	size_t i;

	if (n < 1)
		return 0;

	l = 0;
	m = 0;
	a = p + n - 1;
	for (i = n - 1; i > 0; i--) {
		b = p + i - 1;
		if (b->y > m) {
			l += (b->y - m) * hypot((b->x - a->x) * 1.0 / (b->y - a->y), 1);
			m = b->y;
		}
		a = b;
	}

	return l;
}

void
test(Point *p, size_t n, double r)
{
	double l;

	l = lit(p, n);
	printf("%f\n", l);
	assert(fabs(l - r) < 1e-6);
}

int
main()
{
	Point p[] = {{0, 3000}, {500, 3500}, {2500, 1000}, {5000, 5000}, {9000, 2000}, {9000, 3500}, {10200, 0}};

	test(p, nelem(p), 6200);

	return 0;
}
