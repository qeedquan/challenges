/*

Determine the type of a triangle (equilateral, isosceles, or scalene) based on the given side lengths.

Input
One line contains 3 integers representing the lengths of the triangle's sides. The side lengths do not exceed 100.

Output
Print 1 if the triangle is equilateral, 2 if it is isosceles, and 3 if it is scalene.

Examples

Input #1
3 4 3

Answer #1
2

*/

#include <assert.h>

int
solve(int a, int b, int c)
{
	if (a == b && b == c)
		return 1;
	if (a == b || a == c || b == c)
		return 2;
	return 3;
}

int
main()
{
	assert(solve(3, 4, 3) == 2);

	return 0;
}
