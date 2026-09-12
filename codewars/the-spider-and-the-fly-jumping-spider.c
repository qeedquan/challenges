/*

Background
A spider web is defined by

"rings" numbered out from the centre as 0, 1, 2, 3, 4

"radials" labelled clock-wise from the top as A, B, C, D, E, F, G, H

Here is a picture to help explain:

https://imgur.com/tGeWQVq

Web Coordinates
As you can see, each point where the rings and the radials intersect can be described by a "web coordinate".

So in this example the spider is at H3 and the fly is at E2

Kata Task
Our friendly jumping spider is resting and minding his own spidery business at web-coordinate spider.

An inattentive fly bumbles into the web at web-coordinate fly and gets itself stuck.

Your task is to calculate and return the distance the spider must jump to get to the fly.

Example
The solution to the scenario described by the picture is 4.63522

Notes
The centre of the web will always be referred to as A0
The rings intersect the radials at evenly spaced distances of 1 unit

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define deg2rad(x) ((x) * M_PI / 180)

double
spider2fly(const char *spider, const char *fly)
{
	static const char radial[] = "CBAHGFED";

	const char *radial0, *radial1;
	double ring0, ring1;
	double theta;

	radial0 = strchr(radial, spider[0]);
	radial1 = strchr(radial, fly[0]);
	if (!radial0 || !radial1)
		return -1;

	ring0 = spider[1] - '0';
	ring1 = fly[1] - '0';
	theta = labs(radial1 - radial0) * 45;

	return sqrt((ring0 * ring0) + (ring1 * ring1) - (2 * ring0 * ring1 * cos(deg2rad(theta))));
}

void
test(const char *spider, const char *fly, double expected)
{
	double value;

	value = spider2fly(spider, fly);
	printf("%f\n", value);
	assert(fabs(value - expected) < 1e-5);
}

int
main()
{
	test("H3", "E2", 4.63522);

	test("C2", "C2", 0);
	test("A0", "A0", 0);
	test("F3", "F3", 0);

	test("H1", "H2", 1);
	test("H1", "H4", 3);

	test("H1", "H2", 1);
	test("H1", "H4", 3);

	test("G4", "C4", 8);
	test("G4", "C3", 7);

	return 0;
}
