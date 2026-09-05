/*

Given two distinct points on a plane, perform the following calculations:

Determine the vector that starts at the first point and ends at the second point.

Find the unit vector corresponding to the vector from the first task.

Calculate a vector in the same direction as the initial vector, but with a specified length.

Compute the vector obtained by rotating the initial vector by 90∘ clockwise.

Compute the vector obtained by rotating the initial vector by 90∘ counterclockwise.

Input
The input consists of three lines. The first two lines each contain two integers representing the coordinates of the given points.
The third line contains a natural number specifying the length for the vector in the third task. All numbers in the input do not exceed 1000 in absolute value.

Output
For each task item, output the coordinates of the resulting vector on a separate line, with an accuracy of 10^-4.

Examples

Input #1
3 6
3 8
5

Answer #1
0.000000000 2.000000000
0.000000000 1.000000000
0.000000000 5.000000000
2.000000000 -0.000000000
-2.000000000 0.000000000

*/

#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} vec2;

vec2
sub(vec2 a, vec2 b)
{
	return (vec2){ a.x - b.x, a.y - b.y };
}

vec2
normalize(vec2 a)
{
	double l;

	l = hypot(a.x, a.y);
	return (vec2){ a.x / l, a.y / l };
}

vec2
scale(vec2 a, double s)
{
	return (vec2){ a.x * s, a.y * s };
}

vec2
rot90ccw(vec2 a)
{
	return (vec2){ -a.y, a.x };
}

vec2
rot90cw(vec2 a)
{
	return (vec2){ a.y, -a.x };
}

void
solve(vec2 a, vec2 b, double l)
{
	vec2 v, u, s, cw, ccw;

	v = sub(b, a);
	u = normalize(v);
	s = scale(u, l);
	cw = rot90cw(v);
	ccw = rot90ccw(v);

	printf("%f %f\n", v.x, v.y);
	printf("%f %f\n", u.x, u.y);
	printf("%f %f\n", s.x, s.y);
	printf("%f %f\n", cw.x, cw.y);
	printf("%f %f\n", ccw.x, ccw.y);
	printf("\n");
}

int
main()
{
	vec2 a = { 3, 6 };
	vec2 b = { 3, 8 };

	solve(a, b, 5);

	return 0;
}
