/*

Three distinct points are plotted at random on a Cartesian plane, for which -1000 <= x, y <= 1000, such that a triangle is formed.

Consider the following two triangles:

A(-340, 495) B(-153, -910) C(835, -947)
X(-175, 41) Y(-421, -714) Z(574, -645)

It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.

Using triangles.txt (right click and 'Save Link/Target As...'), a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles for which the interior contains the origin.

NOTE: The first two examples in the file represent the triangles in the example given above.

*/

#include <stdio.h>
#include <errno.h>

typedef long long vlong;

typedef struct {
	vlong x, y;
} Point;

vlong
wedge(Point a, Point b)
{
	return (a.x * b.y) - (a.y * b.x);
}

vlong
solve(const char *name)
{
	FILE *fp;
	Point a, b, c;
	vlong p, q, r;
	vlong t;

	fp = fopen(name, "rb");
	if (!fp)
		return -errno;

	t = 0;
	while (fscanf(fp, "%lld,%lld,%lld,%lld,%lld,%lld", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6) {
		p = wedge(a, b) > 0;
		q = wedge(b, c) > 0;
		r = wedge(c, a) > 0;
		if (p == q && q == r)
			t++;
	}

	fclose(fp);
	return t;
}

int
main(void)
{
	printf("%lld\n", solve("p0102_triangles.txt"));
	return 0;
}
