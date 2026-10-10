/*

https://static.e-olymp.com/content/ea/ea3a7fdb7ec71e09db423f3d2db4616734d80aff.jpg

Given the area of a ring and the radius of its external circle, find the radius of the internal circle.

Input
The input consists of two real numbers: the area of the ring and the radius of the external circle. The radii do not exceed 100.

Output
Output the radius of the internal circle with 2 digits after the decimal point.

Examples

Input #1
50.2655 5

Answer #1
3.00

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
solve(double s, double r)
{
	return sqrt((r * r * M_PI - s) / M_PI);
}

int
main()
{
	printf("%.3f\n", solve(50.2655, 5));

	return 0;
}
