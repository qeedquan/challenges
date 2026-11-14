/*

https://static.e-olymp.com/content/42/42d8c1840d0536ce1d71fc866371251f1a58e518.jpg

Four pairwise distinct points are given in the plane by their coordinates, in the order they are traversed. Determine the type of the resulting quadrilateral.

Input
The first line contains the number of figures n (1≤n≤100).
Each of the next n lines contains 8 integers: the coordinates of the vertices of the next figure.
All tests are correct.
All coordinates do not exceed 1000 by absolute value.

Output
For each figure, output its type in the format shown in the sample output.

Examples
Input #1
4
1 1 3 1 3 3 1 3
5 1 4 3 5 5 6 3
7 1 9 1 9 5 7 5
10 1 11 4 13 4 14 1

Answer #1
Case 1: Square
Case 2: Rhombus
Case 3: Rectangle
Case 4: Other

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
dist2(int x1, int y1, int x2, int y2)
{
	int dx, dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (dx * dx) + (dy * dy);
}

const char *
solve(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int a, b, c, d, e, f;

	a = dist2(x1, y1, x2, y2);
	b = dist2(x2, y2, x3, y3);
	c = dist2(x3, y3, x4, y4);
	d = dist2(x4, y4, x1, y1);
	e = dist2(x1, y1, x3, y3);
	f = dist2(x2, y2, x4, y4);

	if (a == b && b == c && c == d && e == f)
		return "Square";
	if (a == c && b == d && a != d && e == f)
		return "Rectangle";
	if (a == b && b == c && c == d && e != f)
		return "Rhombus";
	return "Other";
}

void
test(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, const char *r)
{
	const char *p;

	p = solve(x1, y1, x2, y2, x3, y3, x4, y4);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	test(1, 1, 3, 1, 3, 3, 1, 3, "Square");
	test(5, 1, 4, 3, 5, 5, 6, 3, "Rhombus");
	test(7, 1, 9, 1, 9, 5, 7, 5, "Rectangle");
	test(10, 1, 11, 4, 13, 4, 14, 1, "Other");

	return 0;
}
