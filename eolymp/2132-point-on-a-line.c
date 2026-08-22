/*

Determine whether a point belongs to the line given by the equation Ax+By+C=0.

Input
Five integers are given: the coordinates of the point x, y and the coefficients A, B, C of the line equation.
It is guaranteed that A and B are not both equal to 0 simultaneously.

Output
Print YES if the point belongs to the line, or NO otherwise.

Examples
Input #1
3 7 -2 1 -1

Answer #1
YES

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
solve(int x, int y, int a, int b, int c)
{
	if ((a * x) + (b * y) + c == 0)
		return "YES";
	return "NO";
}

int
main()
{
	assert(!strcmp(solve(3, 7, -2, 1, -1), "YES"));

	return 0;
}
