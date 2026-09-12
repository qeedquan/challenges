/*

The point is given with its x and y coordinates: (x,y).

Two points (a,b), (c,d) and an integer n are given. Add them.

- Adding two points means to add the corresponding coordinates: (1,2)+(3,4)=(4,6).

- Adding point and a number means to add a number to both point coordinates: (1,2)+10=(11,12).

Write the code according to the next interface:

class Point
public:
int *x, *y;
Point(int x = 0, int y = 0); // Constructor
void Read(void); // Read the point coordinates
void Print(void); // Print the point coordinates
Point operator +(const Point a); // Overload operator +: return the sum of two points
Point operator +(int value); // Overload operator +: return the sum of point and an integer ;

Input
The first line contains the coordinates a and b of the first point.
The second line contains the coordinates c and d of the second point.
The third line contains an integer n. All values do not exceed 10000 by the absolute value.

Output
Print the sum of two points and a number.

Examples
Input #1
1 2
3 4
10

Answer #1
14 16

*/

#include <stdio.h>

typedef struct {
	int x, y;
} Point;

Point
addp(Point a, Point b)
{
	return (Point){ a.x + b.x, a.y + b.y };
}

Point
adds(Point a, int s)
{
	return (Point){ a.x + s, a.y + s };
}

void
solve(Point a, Point b, int n)
{
	Point p;

	p = addp(a, b);
	p = adds(p, n);
	printf("%d %d\n", p.x, p.y);
}

int
main()
{
	Point a = { 1, 2 };
	Point b = { 3, 4 };

	solve(a, b, 10);

	return 0;
}
