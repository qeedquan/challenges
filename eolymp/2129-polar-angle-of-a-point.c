/*

Find the polar angle of the given point.

Input
Two integers are given — the Cartesian coordinates of a point that does not coincide with the origin. The absolute value of each number does not exceed 10000.

Output
Print one real number — the polar angle of the given point in radians from the interval [0;2π). The answer should be rounded to 6 decimal places.

Examples

Input #1
2 3

Answer #1
0.982794

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
solve(double x, double y)
{
	double t;

	t = atan2(y, x);
	if (t < 0)
		t += 2 * M_PI;
	return t;
}

int
main()
{
	printf("%.6f\n", solve(2, 3));
	return 0;
}
