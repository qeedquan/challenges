/*

I have a collection of points, called P. For this challenge the points will all be on a 2D plane. The Convex Hull problem is to find a convex polygon made from points in P which contains all of the points in P. There are several approaches to this problem, including brute-force (not good) and several O(n2) solutions (naive, not brilliant) and some fairly in-depth algorithms.

Some such algorithms are described here (a Java applet, be warned - change the display to 2d first) or on Wikipedia. The choice is yours, but because you're in r/DailyProgrammer try and challenge yourself! Try and implement one of the more interesting algorithms.

For example, a convex hull of P:

Cannot be this because a point is excluded from the selection

Also cannot be this because the shape is not convex - the triangles enclosed in green are missing

Looks like this. The shape is convex and contains all of the points in the image - either inside it or as a boundary.

Input Description
First you will be given a number, N. This number is how many points are in our collection P.

You will then be given N further lines of input in the format:

X,Y
Where X and Y are the co-ordinates of the point on the image. Assume the points are named in alphabetical order as A, B, C, D, ... in the order that they are input.

Output Description
You must give the convex hull of the shape in the format:

ACFGKLO
Where the points are described in no particular order. (as an extra challenge, make them go in order around the shape.)

Notes
In the past we've had some very pretty images and graphs from people's solutions. If you feel up to it, add an image output from your challenge which displays the convex hull of the collection of points.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// ported from @skeeto solution

typedef struct {
	int id;
	double x, y;
} Vertex;

double
ccw(Vertex v1, Vertex v2, Vertex v3)
{
	return (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);
}

int
compare_coord(const void *a, const void *b)
{
	const Vertex *v1, *v2;
	double z;

	v1 = a;
	v2 = b;
	if (v1->y != v2->y)
		z = v1->y - v2->y;
	else
		z = v1->x - v2->x;
	return copysign(1.0, z);
}

int
compare_angle(const void *a, const void *b, void *arg)
{
	const Vertex *v1, *v2, *center;
	double v1a, v2a;

	v1 = a,
	v2 = b,
	center = arg;
	v1a = atan2(v1->y - center->y, v1->x - center->x);
	v2a = atan2(v2->y - center->y, v2->x - center->x);
	return copysign(1.0, v1a - v2a);
}

// https://en.wikipedia.org/wiki/Graham_scan
size_t
convex_hull(Vertex *verts, size_t nverts, Vertex *hull)
{
	size_t nhull;
	size_t i;

	if (nverts < 3)
		return 0;

	qsort(verts, nverts, sizeof(*verts), compare_coord);
	qsort_r(verts + 1, nverts - 1, sizeof(*verts), compare_angle, verts);

	nhull = 3;
	hull[0] = verts[0];
	hull[1] = verts[1];
	hull[2] = verts[2];
	for (i = 3; i < nverts; i++) {
		while (ccw(hull[nhull - 2], hull[nhull - 1], verts[i]) < 0)
			nhull--;
		hull[nhull++] = verts[i];
	}

	return nhull;
}

void
print_hull(Vertex *hull, size_t nhull)
{
	size_t i;

	for (i = 0; i < nhull; i++) {
		printf("%d %f %f\n", hull[i].id, hull[i].x, hull[i].y);
	}
}

int
main()
{
	Vertex verts[] = {
		{ 0, 0, 0 },
		{ 1, 1, 1 },
		{ 2, 1, 0 },
		{ 3, 0, 1 },
	};

	Vertex hull[32];
	size_t nhull;

	nhull = convex_hull(verts, nelem(verts), hull);
	print_hull(hull, nhull);
	return 0;
}
