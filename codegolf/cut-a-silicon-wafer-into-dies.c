/*

When manufacturing chips, circular silicon wafers are cut into dies of needed size:

wafer

The goal of this challenge is maximizing the number of whole dies that can be cut from a wafer of a given diameter.

The machine puts the wafer into an angular compartment:

_____________________
|     xxxxxx
|  xxxxxxxxxxxx
| xxxxxxxxxxxxxx
|xxxxxxxxxxxxxxxx
|xxxxxxxxxxxxxxxx
| xxxxxxxxxxxxxx
|  xxxxxxxxxxxx
|     xxxxxx     (this ascii art is meant to be a perfect circle)

It measures a distance dx from the left edge, and makes a vertical cut. Then it makes the needed number of additional vertical cuts, with spacing of the needed width.
It makes the horizontal cuts in the same way: first one at a distance dy, and then with spacing of height.

The material remains perfectly still during the cutting: it's not allowed to move some slices of material before making the perpendicular cuts.

The machine has a stepper motor that works at absolute accuracy but can only go integer-sized distances.

Make a program or a subroutine that gets (or reads) the following parameters:

Wafer diameter
Die width
Die height
and outputs (or prints)

dx - horizontal starting position
dy - vertical starting position
such that the number of rectangular dies is maximal.

Some fine points:

If a corner of a die lies exactly on the circumference of the circle, the die is considered usable (rectangular)
No edge cases: you can assume that the wafer's diameter is even; at least one die can be cut out; also make other reasonable assumptions
All sizes are integer numbers of millimeters; maximum wafer diameter is 450
Shortest code wins!

P.S. The code must finish running in a reasonable amount of time, e.g. over a weekend (2 days) - for wafer diameter equal to 300.

P.P.S. If there are several different output values that are optimal, the code must output one of them - no need to output all of them!

Test cases:

Wafer diameter 8, die size 2 x 2 => dx = 0, dy = 1 (6 dies)
Wafer diameter 20, die size 5 x 4 => dx = 1, dy = 2 (10 dies)
Wafer diameter 100, die size 12 x 12 => dx = 9, dy = 3 (41 dies)
Wafer diameter 300, die size 11 x 11 => dx = 7, dy = 7 (540 dies) - a realistic example
Wafer diameter 340, die size 15 x 8 => dx = 5, dy = 2 (700 dies) - a Pythagorean triple
Wafer diameter 300, die size 36 x 24 => dx = 2, dy = 6 (66 dies) - full-frame sensors
Here is a visualization of the last test case:

cutting the wafer
https://i.stack.imgur.com/pncj0.png

*/

#include <assert.h>
#include <stdio.h>

/*

Ported from @Rescudo answer

Pretty straightforward bruteforce approach - try every dx in [0, width) and every dy in [0, height), then loop through every rectangle in the resulting grid and check if all four corners are inside the circle (using basic pythagorean relations),
count the number of such rectangles, and return the first dx and dy that produced the highest count for the given configuration.

The third test case produces 0 8 rather than 9 3, but they are both valid, equally optimal, and are both found by my algorithm.

*/

void
optimize(int diameter, int width, int height, int *bestx, int *besty)
{
	int max_die_count, die_count;
	int radius, radius_squared;
	int x1, y1, x2, y2, dx, dy;

	max_die_count = 0;
	radius = diameter / 2;
	radius_squared = radius * radius;
	*bestx = *besty = 0;
	for (dx = 0; dx < width; dx++) {
		for (dy = 0; dy < height; dy++) {
			die_count = 0;
			for (x1 = dx - radius; x1 + width < radius; x1 += width) {
				x2 = x1 + width;
				for (y1 = dy - radius; y1 + height < radius; y1 += height) {
					y2 = y1 + height;
					if (x1 * x1 + y1 * y1 <= radius_squared &&
					    x2 * x2 + y2 * y2 <= radius_squared &&
					    x1 * x1 + y2 * y2 <= radius_squared &&
					    x2 * x2 + y1 * y1 <= radius_squared)
						die_count++;
				}
			}
			if (die_count > max_die_count) {
				max_die_count = die_count;
				*bestx = dx;
				*besty = dy;
			}
		}
	}
}

void
test(int diameter, int width, int height, int resultx, int resulty)
{
	int bestx, besty;

	optimize(diameter, width, height, &bestx, &besty);
	printf("%d %d\n", bestx, besty);
	assert(bestx == resultx);
	assert(besty == resulty);
}

int
main(void)
{
	test(8, 2, 2, 0, 1);
	test(20, 5, 4, 1, 2);
	test(100, 12, 12, 0, 8);
	test(300, 11, 11, 7, 7);
	test(340, 15, 8, 5, 2);
	test(300, 36, 24, 2, 6);

	return 0;
}
