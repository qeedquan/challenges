/*

This is a simple challenge: given n in any way practical (Function arg, stdin, file, constant in code) output the internal angles (NOT the sum of the internal angles, just one) of a regular polygon with n sides. The output can be in degrees, gradians or radians, and can be displayed in any way practical (Function return, stdout, stderr if you feel like it, file etc)

As usual, smallest byte count wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define TAU (2 * M_PI)

#define rad2deg(x) ((x)*180 / M_PI)

double
angle(double n)
{
	return M_PI - (TAU / n);
}

int
main(void)
{
	int i;

	for (i = 1; i <= 1024; i++)
		printf("%d %f\n", i, rad2deg(angle(i)));

	return 0;
}
