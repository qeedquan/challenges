/*

Finding a treasure hidden by pirates is really easy. Everything you need for this is a map. It is widely known that pirates draw maps by hand and describe the algorithm to find a place in the following way: "Stand near a lone palm tree, do 30 steps towards the forest, 15 towards the lake, ..."

A journey through such route is usually a great opportunity to see the scenery... However, nowadays nobody has time for that. That's why treasure seekers have asked you to write a program that would determine the exact location of a treasure using a given map.

Input
The input consists of multiple instructions <Direction> <Distance>, separated with commas (that are followed by one whitespace each).

Direction is one of the following:
N - North, S - South, E - East, W - West,
NE - Northeast, NW - Northwest, SE - Southeast, SW - Southwest.

Distance is an integer (1 to 1000).

Output
The result is the coordinates where you end up after finishing the instructions, with three decimal places, separated with a comma and a whitespace. Start location has zero coordinates (0, 0).

The first coordinate is X (East means coordinates larger than zero, West means less than zero).
The second coordinate is Y (North means more than zero, South means less than zero).

Examples
1. N 3, E 1, N 1, E 3, S 2, W 1

    3.000, 2.000

2. NW 10

    -7.071, 7.071

3. NE 42, NW 42, SE 42, SW 42

    0.000, 0.000

Source (in Ukrainian). Input format is different there.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define deg2rad(x) ((x) * M_PI / 180)

typedef struct {
	double x, y;
} vec2;

vec2
add(vec2 p, vec2 q)
{
	p.x += q.x;
	p.y += q.y;
	return p;
}

vec2
scale(vec2 p, double s)
{
	p.x *= s;
	p.y *= s;
	return p;
}

const char *
next(const char *s, char *d, double *l)
{
	const char *p;

	if (sscanf(s, "%3s %lf", d, l) != 2)
		return NULL;

	p = s;
	while (*p && *p != ',')
		p++;

	while (*p == ',' || *p == ' ')
		p++;

	return p;
}

vec2
direction(const char *s)
{
	static const struct heading {
		const char *name;
		double angle;
	} headings[] = {
	    {"E", 0},
	    {"NE", 45},
	    {"N", 90},
	    {"NW", 135},
	    {"W", 180},
	    {"SW", 225},
	    {"S", 270},
	    {"SE", 315},
	};

	const struct heading *p;
	size_t i;
	double t;
	vec2 d;

	d.x = d.y = 0;
	for (i = 0; i < nelem(headings); i++) {
		p = headings + i;
		if (!strcmp(s, p->name)) {
			t = deg2rad(p->angle);
			d.x = cos(t);
			d.y = sin(t);
			break;
		}
	}
	return d;
}

vec2
treasure(const char *s)
{
	vec2 p;
	char d[4];
	double l;

	p.x = p.y = 0;
	while ((s = next(s, d, &l)))
		p = add(p, scale(direction(d), l));

	return p;
}

void
test(const char *s, vec2 r)
{
	static const double eps = 1e-3;
	vec2 p;

	p = treasure(s);
	printf("%f %f\n", p.x, p.y);
	assert(fabs(p.x - r.x) < eps);
	assert(fabs(p.y - r.y) < eps);
}

int
main()
{
	vec2 r1 = {3, 2};
	vec2 r2 = {-7.071, 7.071};
	vec2 r3 = {0.000, 0.000};

	test("N 3, E 1, N 1, E 3, S 2, W 1", r1);
	test("NW 10", r2);
	test("NE 42, NW 42, SE 42, SW 42", r3);

	return 0;
}
