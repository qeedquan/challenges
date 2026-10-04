/*

Find the integer length of the side of the square that can be obtained from two rectangles of sizes a×b and c×d
by cutting them into rectangles and then assembling them to form a square of the largest possible area.

Input
In one line, you are given four real numbers a, b, c, d. The area of each rectangle does not exceed 2×10^9.

Output
Output a single number: the side length of the resulting square.

Examples

Input #1
1 2 3 4

Answer #1
3

*/

#include <assert.h>
#include <math.h>

int
solve(int a, int b, int c, int d)
{
	int r;

	r = (a * b) + (c * d);
	if (r < 0)
		return 0;
	return floor(sqrt(r));
}

int
main()
{
	assert(solve(1, 2, 3, 4) == 3);

	return 0;
}
