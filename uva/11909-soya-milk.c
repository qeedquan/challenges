/*

On the dining table we have a packet of soya milk.
We can look at the packet as a rectangular box with height h, length l and width w.
We tilt it against a base edge, as shown in the picture.
Soya milk then comes out through the opening in the top face.
This process stops when the milk level is no longer higher than the opening.
Write a program that computes the volume of soya milk remaining in the packet.
Note that the problem description may not perfectly match the real-life situation, but to solve this problem you must follow our assumptions.

Input
Each input file contains multiple test cases, and each test case starts on a new line.
Each case consists of four positive integers l, w, h (in centimetres) and θ (in degrees), all strictly less than 90.

Output
For each test case, output a line containing the volume of soya milk inside the packet in millilitres, correct to 3 decimal places.

Sample Input
9 6 19 20

Sample Output
937.555 mL

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x)*M_PI / 180)

double
volume(double l, double w, double h, double t)
{
	double a;

	a = tan(deg2rad(t));
	if (l * a <= h)
		return (l * w * h) - (w * 0.5 * l * l * a);
	return (w * 0.5 * h * h) / a;
}

void
test(double l, double w, double h, double t, double r)
{
	double v;

	v = volume(l, w, h, t);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	test(9, 6, 19, 20, 937.555);

	return 0;
}
