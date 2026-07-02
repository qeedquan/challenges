/*

Your task is to write a function angle_planes(lstPts) that calculates the angle between two planes, each of them being defined by a tuple of three points.

Input:

lstPts – list of 6 tuples that contain 3 coordinates: x, y and z for each point. The first three points are defining the first plane, the second three are for the second one. All coordinates are integers.

Output:

A float: the angle between the two planes in radians and rounded off to 2 decimal places.

Example:

angle_planes([(2,1,2),(1,2,2),(2,2,0), (2,0,0),(2,0,2),(0,2,2)])

Should return

0.34

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y, z;
} Vec3;

typedef Vec3 Plane[3];

Vec3
sub(Vec3 a, Vec3 b)
{
	return (Vec3){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
	};
}

double
dot(Vec3 a, Vec3 b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vec3
cross(Vec3 a, Vec3 b)
{
	return (Vec3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
	};
}

double
length(Vec3 a)
{
	return sqrt(dot(a, a));
}

// https://math.stackexchange.com/questions/2658300/computing-the-normal-of-a-plane-given-3-points
Vec3
normal(Plane p)
{
	Vec3 a, b;

	a = sub(p[1], p[0]);
	b = sub(p[2], p[0]);
	return cross(a, b);
}

// https://www.superprof.co.uk/resources/academic/maths/analytical-geometry/distance/angle-between-two-planes.html
double
planeangle(Plane p0, Plane p1)
{
	Vec3 n0, n1;

	n0 = normal(p0);
	n1 = normal(p1);
	return acos(fabs(dot(n0, n1)) / (length(n0) * length(n1)));
}

void
test(Plane p0, Plane p1, double r)
{
	double a;

	a = planeangle(p0, p1);
	printf("%.2f\n", a);
	assert(fabs(a - r) < 1e-2);
}

int
main()
{
	Plane p0 = { { 2, 1, 2 }, { 1, 2, 2 }, { 2, 2, 0 } };
	Plane p1 = { { 2, 0, 0 }, { 2, 0, 2 }, { 0, 2, 2 } };

	Plane p2 = { { -17, -31, -36 }, { -48, 43, 0 }, { 49, 13, 10 } };
	Plane p3 = { { 45, 38, 1 }, { 21, -36, 18 }, { 35, 10, 11 } };

	test(p0, p1, 0.34);
	test(p2, p3, 1.47);

	return 0;
}
