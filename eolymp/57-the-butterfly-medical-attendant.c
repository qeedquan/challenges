/*

Schoolchildren, on their way from home to school or vice versa, enjoy eating candies.
However, as is often the case, this pleasant habit sometimes leads to unpleasant consequences — children often throw candy wrappers in the schoolyard.

Smugastyk always kept the schoolyard clean, and butterflies, grateful for the beautiful photographs Smugastyk took, gladly helped him.
Butterflies could use their wings as lenses and adjust their focal length at will.
When a butterfly spotted a candy wrapper at the point with coordinates X1, Y1 in the schoolyard,
it would fly to the point with coordinates X2, Y2, Z2 — along the path of a sunbeam that reaches the wrapper — adjust the focal length of its wing-lenses,
and burn the candy wrapper.

What was the optical power D of the butterfly's wing-lenses at that moment?

Input
The first line contains two integers: the coordinates X1, Y1 of the candy wrapper.

The second line contains three integers: the coordinates X2, Y2, Z2 of the butterfly at the moment of burning the wrapper.

All input numbers are integers with absolute value not exceeding 1000.

Output
Output a single number — the optical power D of the wing-lenses, rounded mathematically to three decimal places.

Examples

Input #1
10 20
10 20 100

Answer #1
0.010

*/

#include <stdio.h>
#include <math.h>

#define sqr(x) ((x) * (x))

double
solve(double x1, double y1, double x2, double y2, double z2)
{
	double r;

	r = sqrt(sqr(x2 - x1) + sqr(y2 - y1) + (z2 * z2));
	return 1 / r;
}

int
main()
{
	printf("%.3f\n", solve(10, 20, 10, 20, 100));

	return 0;
}
