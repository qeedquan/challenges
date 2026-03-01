/*

Write a program that gets coordinates of two objects on Earth, and calculates how far are they from each other directly in space (a straight line through Earth) and on the surface (through the shortest route on the Earth surface). Don't take into account that polar and equatorial radii differ, consider Earth's radius 6371.0 km.

Write a program that gets 4 numbers:

Obj1 latitude ( [ -90.0° ; 90.0° ] )
Obj1 longitude ( ( -180.0° ; 180.0° ] )
Obj2 latitude ( [ -90.0° ; 90.0° ] )
Obj2 longitude ( ( -180.0° ; 180.0° ] )
and gives 2 numbers: the physical distance in space between two objects and the distance of the shortest route to go through on the Earth surface. In the context of the task Earth is a perfect sphere with no highlands/mountains or lowlands, etc..

Positive and negative values are for different hemispheres, degrees with decimal part representing minutes and seconds (e.g. -38.20 means -38°12'00", so no need to overthink). No need to check the input values, they're guaranteed to be in the range.

Hardcore. Calculate two values (in degrees) that represent:

Direction of the shortest route from Obj1 to Obj2 (0° is the north, 180° is the south (-180° is represented like 180° and so on), positive degrees are on the east side (90° is the east), negative - on the west (-90° is the west)), of course before any movement, only in the starting point;
From the perspective of the one of the objects, angle between its horizon and the physical position of the second object below the horizon (inclination, here always below the horizon, e.g. 180° means directly on the opposite side of Earth).

Overall output:

physical_distance shortest_route shortest_route_direction inclination_below_horizon

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x) * M_PI / 180)

/*

@Jonathan Allan

How?
Labelling the two longitudes as λi and the two latitudes as ϕi, the angle between the lines from each of the two points and the centre of the sphere, the central angle, is[1]:

Δσ=arccos(cos|λ1−λ2|*cos(ϕ1)*cos(ϕ2) + sin(ϕ1)*sin(ϕ2))

Note: Since cos is symmetric around the y-axis, we can use λ2−λ1 in place of |λ1−λ2|.

The shortest distance between two points in Euclidean space is a straight line,
so we have an isosceles triangle with the equal side lengths being the sphere's radius, r=6371 kilometres,
so the direct path in space is (using opposite = hypotenuse*sinα):

d = 2*r*sin(Δσ/2)

The shortest distance between two points on a sphere is the minor arc of the great circle on which they lie. This is the arc projected by the angle Δσ and thus has length:

s=r*Δσ

[1] https://en.wikipedia.org/wiki/Great-circle_distance

*/

void
farness(double p1, double p2, double l1, double l2, double *s, double *d)
{
	static const double r = 6371;
	double t;

	t = acos(cos(l2 - l1) * cos(p1) * cos(p2) + sin(p1) * sin(p2));
	*d = 2 * r * sin(t / 2);
	*s = r * t;
}

void
test(double p1, double p2, double l1, double l2, double sr, double dr)
{
	static const double eps = 1e-12;
	double s, d;

	farness(deg2rad(p1), deg2rad(p2), deg2rad(l1), deg2rad(l2), &s, &d);
	printf("%f %f\n", s, d);
	assert(fabs(s - sr) < eps);
	assert(fabs(d - dr) < eps);
}

int
main(void)
{
	test(0, 0, 0, 90, 10007.543398010286, 9009.954605878987);
	test(43.11, -62.04, -178.53, 109.09, 13343.545135889812, 11034.972663487397);

	return 0;
}
