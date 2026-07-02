/*

You have an array or list of coordinates or points (e.g. [ [1, 1], [3, 4], ... , [5, 2] ]), and your task is to find the area under the graph defined by these points (limited by x of the first and last coordinates as left and right borders, y = 0 as the bottom border and the graph as top border).

Notes:

x can be negative;
x of the next pair of coordinates will always be greater then previous one;
y >= 0;
the array will contain more than 2 coordinates.

Example

x=1 (left border)               x=5 (right border)
|                      x,y      |
|                    /\         |
|                   /  \        |
|    x,y           /    \       |
|   /\            /      \      |
|  /  \    x,y   /        \     |
| /    \  /\    /          \    |
|/      \/  \  /            \   |
|x,y    x,y  \/              \  |
|            x,y              \ |
|_____________________________ \x,y_____ y=0 (bottom border)

The required area:


|                               |
|                    /\         |
|                   /\\\        |
|                  /\\\\\       |
|   /\            /\\\\\\\      |
|  /\\\          /\\\\\\\\\     |
| /\\\\\  /\    /\\\\\\\\\\\    |
|/\\\\\\\/\\\  /\\\\\\\\\\\\\   |
|\\\\\\\\\\\\\/\\\\\\\\\\\\\\\  |
|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ |
|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\|

Definition of points

var Point = function (x,y) {
  this.X = x;
  this.Y = y;
}

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

double
findarea(Point *p, size_t n)
{
	size_t i;
	double r;

	r = 0;
	for (i = 1; i < n; i++)
		r += ((p[i - 1].y + p[i].y) * 0.5) * (p[i].x - p[i - 1].x);
	return r;
}

int
main()
{
	Point p[] = {{1, 1}, {3, 4}, {5, 2}};

	printf("%f\n", findarea(p, nelem(p)));
	return 0;
}
