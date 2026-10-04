/*

Task.

Calculate area of given triangle. Create a function t_area that will take a string which will represent triangle, find area of the triangle, one space will be equal to one length unit. The smallest triangle will have one length unit.

Hints

Ignore dots.

All triangles will be right isoceles.

Example:

.
.      .
.      .       .      ---> should return 2.0

.
.      .
.      .       .
.      .       .      .      ---> should return 4.5

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
area(const char *s)
{
	size_t i;
	double h;

	h = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '\n')
			h++;
	}
	h = fmax(0, h - 2);
	return 0.5 * h * h;
}

int
main()
{
	assert(area("\n.\n. .\n") == 0.5);
	assert(area("\n.\n. .\n. . .\n") == 2);
	assert(area("\n.\n. .\n. . .\n. . . .\n. . . . .\n. . . . . .\n. . . . . . .\n. . . . . . . .\n. . . . . . . . .\n") == 32);
	assert(area("\n.\n. .\n. . .\n. . . .\n. . . . .\n") == 8);

	return 0;
}
