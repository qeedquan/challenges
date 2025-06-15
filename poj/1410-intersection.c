/*

Description

You are to write a program that has to decide whether a given line segment intersects a given rectangle.

An example:
line: start point: (4,9)
end point: (11,2)
rectangle: left-top: (1,5)
right-bottom: (7,1)

Figure 1: Line segment does not intersect rectangle
http://poj.org/images/1410_1.jpg

The line is said to intersect the rectangle if the line and the rectangle have at least one point in common. The rectangle consists of four straight lines and the area in between. Although all input values are integer numbers, valid intersection points do not have to lay on the integer grid.

Input

The input consists of n test cases. The first line of the input file contains the number n. Each following line contains one test case of the format:
xstart ystart xend yend xleft ytop xright ybottom

where (xstart, ystart) is the start and (xend, yend) the end point of the line and (xleft, ytop) the top left and (xright, ybottom) the bottom right corner of the rectangle. The eight numbers are separated by a blank. The terms top left and bottom right do not imply any ordering of coordinates.

Output

For each test case in the input file, the output file should contain a line consisting either of the letter "T" if the line segment intersects the rectangle or the letter "F" if the line segment does not intersect the rectangle.

Sample Input

1
4 9 11 2 1 5 7 1

Sample Output

F

Source

Southwestern European Regional Contest 1995

*/

#include <assert.h>
#include <stdbool.h>

bool
lineline(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	float a, b;

	a = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	b = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	return (a >= 0 && a <= 1) && (b >= 0 && b <= 1);
}

// https://www.jeffreythompson.org/collision-detection/line-rect.php
bool
linerect(float x1, float y1, float x2, float y2, float rx1, float ry1, float rx2, float ry2)
{
	bool left, right, top, bottom;
	float rx, ry, rw, rh;

	rx = rx1;
	ry = ry1;
	rw = rx2 - rx1;
	rh = ry2 - ry1;

	left = lineline(x1, y1, x2, y2, rx, ry, rx, ry + rh);
	right = lineline(x1, y1, x2, y2, rx + rw, ry, rx + rw, ry + rh);
	top = lineline(x1, y1, x2, y2, rx, ry, rx + rw, ry);
	bottom = lineline(x1, y1, x2, y2, rx, ry + rh, rx + rw, ry + rh);

	return left || right || top || bottom;
}

int
main(void)
{
	assert(linerect(4, 9, 11, 2, 1, 5, 7, 1) == false);

	return 0;
}
