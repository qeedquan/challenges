/*

You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

Example 1:
https://assets.leetcode.com/uploads/2020/02/20/sample_4_1728.png
Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).

Example 2:

Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false

Example 3:
https://assets.leetcode.com/uploads/2020/02/20/sample_2_1728.png
Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true

Constraints:

1 <= radius <= 2000
-10^4 <= xCenter, yCenter <= 10^4
-10^4 <= x1 < x2 <= 10^4
-10^4 <= y1 < y2 <= 10^4

*/

#include <assert.h>

bool
overlap(int r, int xc, int yc, int x1, int y1, int x2, int y2)
{
	int dx, dy;

	x1 -= xc;
	y1 -= yc;
	x2 -= xc;
	y2 -= yc;

	dx = dy = 0;
	if (x1 > 0)
		dx = x1;
	else if (x2 < 0)
		dx = x2;

	if (y1 > 0)
		dy = y1;
	else if (y2 < 0)
		dy = y2;

	return (dx * dx) + (dy * dy) <= (r * r);
}

int
main()
{
	assert(overlap(1, 0, 0, 1, -1, 3, 1) == true);
	assert(overlap(1, 1, 1, 1, -3, 2, -1) == false);
	assert(overlap(1, 0, 0, -1, 0, 0, 1) == true);

	return 0;
}
