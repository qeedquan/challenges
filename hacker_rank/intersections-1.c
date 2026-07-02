/*

You are given two set of points. The first set is determined by the equation A1x + B1y + C1 = 0, and the second one is determined by the equation A2x + B2y + C2 = 0.

Write the program which finds the number of points in the intersection of two given sets.

Input Format

The first line of the input contains three integer numbers A1, B1, C1 separated by space.

The second line contains three integer numbers A2, B2, C2 separated by space.

All the numbers are between -100 and 100, inclusive.

Output Format

Print the number of points in the intersection or -1 if there are infinite number of points.

Sample Input

1 1 0

2 2 0

Sample Output

-1

*/

#include <assert.h>
#include <stdio.h>

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return (a) ? a : 1;
}

/*

A line written in standard form

ax + by + c = 0

has the solution of the following form

d = (a1*b2 - a2*b1)
x = (b1*c2 - b2*c1) / d
y = (c1*a2 - c2*a1) / d

If d is not zero, then there is a unique solution
If d is zero, then there can be infinite or no solutions

To see if there are infinite solutions, we need to check if the equations produce the same line
a1x + b1y + c1
a2x + b2y + c2

This leads to the following condition: if these ratios are equal, then they are the same line

a2/a1 = b2/b1 = c2/c1

*/

int
intersections(int a1, int b1, int c1, int a2, int b2, int c2)
{
	int r1, r2, r3;
	int d;

	d = (a1 * b2) - (a2 * b1);
	if (d != 0)
		return 1;

	if (c1 == 0 && c1 == c2)
		return -1;

	r1 = a2 / gcd(a1, a2);
	r2 = b2 / gcd(b1, b2);
	r3 = c2 / gcd(c1, c2);
	if (r1 == r2 && r2 == r3)
		return -1;

	return 0;
}

int
main()
{
	assert(intersections(1, 1, 0, 2, 2, 0) == -1);
	assert(intersections(2, -1, 1, 4, -2, 2) == -1);
	assert(intersections(0, 0, 0, 0, 0, 0) == -1);
	assert(intersections(3, 3, 3, 3, 3, 3) == -1);
	assert(intersections(2, 4, 6, 4, 8, 6) == 0);
	assert(intersections(2, -1, 1, 2, -1, 3) == 0);
	assert(intersections(0, 5, -2, 0, 6, -3) == 0);
	assert(intersections(5, 0, -2, 6, 0, -3) == 0);
	assert(intersections(3, -1, 2, 2, -1, 2) == 1);
	assert(intersections(9, 3, 3, 4, 5, 6) == 1);

	return 0;
}
