/*

Determine if the point A with coordinates (x, y) is inside, on, or outside a circle with center O(x0, y0) and radius R.

Input
The first line contains the coordinates of point A(x, y).
The second line contains three integers: the circle's radius R (0<R≤200) and the coordinates of its center O(x0, y0).
All coordinates are integers with absolute value not exceeding 200.

Output
Print YES if the point is inside the circle, NO if the point is outside the circle, and ON BORDER if the point is on the circle.

Examples

Input #1
2 3
5 1 2

Answer #1
YES

*/

#include <assert.h>
#include <string.h>

#define sqr(x) ((x) * (x))

const char *
solve(int x, int y, int r, int cx, int cy)
{
	int d;
	int r2;

	d = sqr(x - cx) + sqr(y - cy);
	r2 = r * r;
	if (r2 > d)
		return "YES";
	if (r2 < d)
		return "NO";
	return "ON BORDER";
}

int
main()
{
	assert(!strcmp(solve(2, 3, 5, 1, 2), "YES"));

	return 0;
}
