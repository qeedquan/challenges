/*

Many computer games are played by moving some pieces or heroes over a map or a field of some kind. There are two popular kinds for geometry of such maps:

rectangular grid - the field is tiled by rectangles or squares;
hexagonal grid - the field is tiled by hexagons.
Well-known game Heroes of Might and Magic for example utilized both variants - rectangular grid is used on the world map while riding between castles (with ability of diagonal movements), while hexagonal grid is used as a battle field in combat mode.

Hexagonal tiling looks more beautiful for user, but the programming its geometry is slightly more tricky. That is what we are going to practice now.

Problem statement

Suppose the "hero" is placed at some cell of hexagonal grid. Then he can move in six directions. On the picture above X marks the initial cell and letters A, B, C, D, E, F - the possible movements for 1 step. A moves the hero directly to the right and other directions are named in the counter-clockwise order.

You will be given a sequence of steps, performed by hero, each step described by a corresponding letter. You are to tell after all these steps, how far the hero is now from his initial position (measured by straight line, i.e. "Euclidean distance").

We agree that the hero is always placed at the center of the cell and that distance between centers of two adjacent cells (i.e. sharing a side) is 1.0.

Input data will contain number of test-cases in the first line.
Next lines will contain the sequence of steps (one sequence per line) as a string of letters.
Answer should contain the distances between starting and ending point for each of sequences, separated by spaces and with accuracy of 1e-7 at least.

Example:

input data:
3
AABF
FEDCBA
BCB

answer:
3.0 0.0 2.64575131

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solve(const char *s)
{
	double t, x, y;

	for (x = y = 0; *s; s++) {
		if ('A' <= *s && *s <= 'F') {
			t = (*s - 'A') * (M_PI / 3);
			x += cos(t);
			y += sin(t);
		}
	}
	return hypot(x, y);
}

void
test(const char *s, double r)
{
	double d;

	d = solve(s);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-8);
}

int
main()
{
	test("AABF", 3);
	test("FEDCBA", 0);
	test("BCB", 2.64575131);

	return 0;
}
