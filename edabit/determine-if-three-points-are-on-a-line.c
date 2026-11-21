/*

Create a function that returns True if three points belong to the same line, and False otherwise. Each point is represented by a list consisting of an x- and y-coordinate.

Examples

same_line([[0, 0], [1, 1], [3, 3]]) ➞ True

same_line([[-2, -1], [2, 1], [0, 0]]) ➞ True

same_line([[-2, 0], [-10, 0], [-8, 0]]) ➞ True

same_line([[0, 0], [1, 1], [1, 2]]) ➞ False

same_line([[3, 4], [3, 5], [6, 6]]) ➞ False

Notes

Note the special case of a vertical line.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
det3x3(int m[3][3])
{
	int c00, c01, c02;

	c00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	c01 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
	c02 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	return (m[0][0] * c00) + (m[0][1] * c01) + (m[0][2] * c02);
}

int
collinear(Point p[3])
{
	int m[3][3] = {
	    {p[0].x, p[0].y, 1},
	    {p[1].x, p[1].y, 1},
	    {p[2].x, p[2].y, 1},
	};
	return det3x3(m) == 0;
}

int
main(void)
{
	Point p1[] = {{0, 0}, {1, 1}, {3, 3}};
	Point p2[] = {{-2, -1}, {2, 1}, {0, 0}};
	Point p3[] = {{-2, 0}, {-10, 0}, {-8, 0}};
	Point p4[] = {{0, 0}, {0, 5}, {0, 7}};
	Point p5[] = {{9, 9}, {8, 8}, {6, 6}};
	Point p6[] = {{0, 0}, {1, 1}, {1, 2}};
	Point p7[] = {{3, 4}, {3, 5}, {6, 6}};
	Point p8[] = {{9, 8}, {8, 8}, {6, 6}};

	assert(collinear(p1) == true);
	assert(collinear(p2) == true);
	assert(collinear(p3) == true);
	assert(collinear(p4) == true);
	assert(collinear(p5) == true);
	assert(collinear(p6) == false);
	assert(collinear(p7) == false);
	assert(collinear(p8) == false);

	return 0;
}
