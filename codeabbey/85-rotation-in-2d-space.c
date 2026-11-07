/*

Let's practice the geometry programming of rotations. Such functionality is quite popular in graphic editors, but it is not the only use.

For example here is the widget Sphere Tag Cloud which can be used in creating funny design of the web-page. Dragging the mouse over the cloud you should see it scrolling like a globe. The effect is achieved by performing just two rotations around two axes (for each of floating element).

We'll start with something simpler. Suggest we have a planar map with points on it. For example it could be the picture of a sky with stars shining.

The task is to perform rotation of the map by the given angle. Round the resulting coordinates to nearest integer.

To check the result please output the names of stars sorted by Y coordinate and then by X (if the Ys are equal).

Input data contain the number of stars N and the rotation angle A (counterclockwise, from 0 to 360 degrees).
Next lines will contain data about one star each in form Name X Y. Coordnates would be integer, not exceeding 1000 in absolute value.
Answer should give the names of stars sorted by Y and then by X after rotation (and rounding).

Note: sorting should be performed in ascending order, i.e. from smallest values to largest.

Example:

input data:
4 45
Deneb -10 10
Algol 10 10
Sirius -10 -10
Mira 10 -10

answer:
Sirius Deneb Mira Algol

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define deg2rad(x) ((x) * M_PI / 180)

typedef struct {
	char name[16];
	float x, y;
} Star;

int
starcmp(const void *a, const void *b)
{
	const Star *s1, *s2;

	s1 = a;
	s2 = b;
	if (s1->y < s2->y)
		return -1;
	if (s1->y > s2->y)
		return 1;
	if (s1->x < s2->x)
		return -1;
	if (s1->x > s2->x)
		return 1;
	return strcmp(s1->name, s2->name);
}

void
rotate(float x, float y, float angle, float *nx, float *ny)
{
	float xp, yp;
	float co, si;

	si = sin(angle);
	co = cos(angle);

	xp = (x * co) - (y * si);
	yp = (x * si) + (y * co);

	*nx = xp;
	*ny = yp;
}

void
solve(Star *stars, size_t nstars, float angle)
{
	Star *star;
	size_t i;

	angle = deg2rad(angle);
	for (i = 0; i < nstars; i++) {
		star = stars + i;
		rotate(star->x, star->y, angle, &star->x, &star->y);
	}
	qsort(stars, nstars, sizeof(*stars), starcmp);

	for (i = 0; i < nstars; i++) {
		star = stars + i;
		printf("%s ", star->name);
	}
	printf("\n");
}

int
main()
{
	Star stars[] = {
		{ "Deneb", -10, 10 },
		{ "Algol", 10, 10 },
		{ "Sirius", -10, -10 },
		{ "Mira", 10, -10 },
	};

	solve(stars, nelem(stars), 45);
	return 0;
}
