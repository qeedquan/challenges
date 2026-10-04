/*

Description

Given a triangle field and a rope of a certain length (Figure-1), you are required to use the rope to enclose a region within the field and make the region as large as possible.

http://poj.org/images/1927_1.jpg

Input

The input has several sets of test data. Each set is one line containing four numbers separated by a space. The first three indicate the lengths of the edges of the triangle field, and the fourth is the length of the rope. Each of the four numbers have exactly four digits after the decimal point. The line containing four zeros ends the input and should not be processed. You can assume each of the edges are not longer than 100.0000 and the length of the rope is not longer than the perimeter of the field.
Output

Output one line for each case in the following format:

Case i: X

Where i is the case number, and X is the largest area which is rounded to two digits after the decimal point.
Sample Input

12.0000 23.0000 17.0000 40.0000
84.0000 35.0000 91.0000 210.0000
100.0000 100.0000 100.0000 181.3800
0 0 0 0
Sample Output

Case 1: 89.35
Case 2: 1470.00
Case 3: 2618.00
Source

Beijing 2004 Preliminary@POJ

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
area(double a, double b, double c, double l)
{
	double p, s, r, R, v;

	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	R = (2 * s) / (a + b + c);

	if (l > a + b + c)
		return s;

	if (l <= R * 2 * M_PI)
		return (l * l) / (4 * M_PI);

	r = R * (l - a - b - c) / (2 * M_PI * R - a - b - c);
	v = s - (s * r * r) / (R * R) + (r * r * M_PI);
	return v;
}

void
test(double a, double b, double c, double l, double r)
{
	double v;

	v = area(a, b, c, l);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-2);
}

int
main(void)
{
	test(12.0000, 23.0000, 17.0000, 40.0000, 89.35);
	test(84.0000, 35.0000, 91.0000, 210.0000, 1470.00);
	test(100.0000, 100.0000, 100.0000, 181.3800, 2618.00);

	return 0;
}
