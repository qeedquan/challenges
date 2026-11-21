/*

The challenge
This challenge is very straightforward. Given four 3-dimensional points, calculate the surface area of the tetrahedron that they form. This is code-golf, so shortest code wins. Standard loopholes apply, with the added stipulation that any built-in function to do this task given four points is prohibited.

You can assume all four points will be distinct, and will be given via STDIN, 1 point per line. Each point will consist of three 16-bit unsigned integers. The exact format of each point can be modified if it makes things easier, such as three space separated integers. Having each point on a separate line is mandatory however. Output should be through STDOUT, to at least 2 decimal places.

For those of you who do not know, a tetrahedron is a 3-d solid, formed by 4 triangular faces.

Example
# input (format is up to you, see clarification above)
[23822, 47484, 57901]
[3305, 23847, 42159]
[19804, 11366, 14013]
[52278, 28626, 52757]

# output
2932496435.95
Please leave a note if you notice my math is wrong.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y, z;
} Point;

double
distance(Point a, Point b)
{
	double dx, dy, dz;

	dx = a.x - b.x;
	dy = a.y - b.y;
	dz = a.z - b.z;
	return sqrt((dx * dx) + (dy * dy) + (dz * dz));
}

double
heron(double a, double b, double c)
{
	double s;

	s = 0.5 * (a + b + c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double
tetras(Point p[4])
{
	static const int id[][3] = {
	    {0, 1, 2},
	    {0, 1, 3},
	    {0, 2, 3},
	    {1, 2, 3},
	};

	double a, b, c, r;
	Point p0, p1, p2;
	size_t i;

	r = 0;
	for (i = 0; i < nelem(id); i++) {
		p0 = p[id[i][0]];
		p1 = p[id[i][1]];
		p2 = p[id[i][2]];

		a = distance(p0, p1);
		b = distance(p1, p2);
		c = distance(p2, p0);
		r += heron(a, b, c);
	}

	return r;
}

void
test(Point p[4], double r)
{
	double s;

	s = tetras(p);
	printf("%f\n", s);
	assert(fabs(s - r) < 1e-2);
}

int
main(void)
{
	Point p1[] = {
	    {23822, 47484, 57901},
	    {3305, 23847, 42159},
	    {19804, 11366, 14013},
	    {52278, 28626, 52757},
	};

	test(p1, 2932496435.95);

	return 0;
}
