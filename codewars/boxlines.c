/*

Boxlines
Given a X*Y*Z box built by arranging 1*1*1 unit boxes, write a function f(X,Y,Z) that returns the number of edges (hence, boxlines) of length 1 (both inside and outside of the box)

Notes
Adjacent unit boxes share the same edges, so a 2*1*1 box will have 20 edges, not 24 edges
X,Y and Z are strictly positive, and can go as large as 2^16 - 1

Interactive Example
The following is a diagram of a 2*1*1 box. Mouse over the line segments to see what should be counted!

Interactive diagram made by @awesomead

This is my first kata, so I hope every one will enjoy it <3

*/

#include <assert.h>

int
boxline(int x, int y, int z)
{
	int x1, y1, z1;

	x1 = x + 1;
	y1 = y + 1;
	z1 = z + 1;
	return (x * y1 * z1) + (y * x1 * z1) + (z * x1 * y1);
}

int
main()
{
	assert(boxline(2, 1, 1) == 20);
	assert(boxline(1, 1, 1) == 12);

	return 0;
}
