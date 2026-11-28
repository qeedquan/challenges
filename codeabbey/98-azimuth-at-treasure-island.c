/*

A group of pirates was lucky to lay their hands on the map of the Treasure Island.

To their disappointment the map does not contain a vague drawings with a small black cross - but instead just several lines like the following:

at the southern beach of the Island find the pole stuck into the sand with the plaque Start attached;
turn azimuth 50 and go 300 feet;
proceed 500 feet by azimuth 270;
stride 150 feet more by azimuth 300;
dig here!
Pirates read in Wikipedia that azimuth 0 is the direction to the North, azimuth 90 is the direction to the East and so on.

However, they use a kind of GPS-navigator in place of compass. Instead of directions the device can show coordinates or offsets in feets.

So pirates need to solve the following problem: suggesting that the point of "the pole with the plaque Start" is the origin of coordinate system with Y axis pointing to the North and X axis pointing to the East - what are the coordinates of the treasure point?

Input data will be in format close to the directions inscribed on a map:
The first line contains words Stand at the pole with the plaque START - you can safely ignore this.
Next lines contain words go X feet by azimuth Y - you are to extract numbers from them.
Last line contains phrase Dig here!
Answer should contain coordinates of the point where the Treasure is hidden, rounded to closest integers.

Example:

input data:
Stand at the pole with the plaque START
go 140 feet by azimuth 332
go 460 feet by azimuth 78
Dig here!

answer:
384 219

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define deg2rad(x) ((x) * M_PI / 180)

void
solve(const char **s, size_t n)
{
	size_t i;
	double r, p;
	double x, y;

	x = y = 0;
	for (i = 0; i < n; i++) {
		if (sscanf(s[i], "go %lf feet by azimuth %lf", &r, &p) == 2) {
			p = deg2rad(p);
			x += r * sin(p);
			y += r * cos(p);
		}
	}
	printf("%.0f %.0f\n", round(x), round(y));
}

int
main()
{
	const char *s1[] = {
		"Stand at the pole with the plaque START",
		"go 140 feet by azimuth 332",
		"go 460 feet by azimuth 78",
		"Dig here!",
	};

	solve(s1, nelem(s1));
	return 0;
}
