/*

Task:
You get two sticks of lengths > 0
You can break them into pieces of integer lengths
Your task is to construct the biggest square from those sticks, which means that you need 4 pieces of the same length
The longer the side of the square, the bigger the square

Output:
if square can be constructed --> length of the side of that square
if square can't be constructed --> 0

Examples:
square(0.25, 3.75) -> 0
3 pieces of length 1 -> no square

square(2, 2) -> 1
4 pieces of length 1 -> square, side_length = 1

square(5, 14) -> 4
4 pieces of length 4 -> square, side_length = 4

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
square(double a, double b)
{
	int l, h, m;

	if (a <= 0 || b <= 0)
		return 0;

	l = 0;
	h = floor((a + b) / 4);
	while (l < h) {
		m = (l + h + 1) / 2;
		if (floor(a / m) + floor(b / m) >= 4)
			l = m;
		else
			h = m - 1;
	}
	return l;
}

int
main()
{
	assert(square(0.25, 3.75) == 0);
	assert(square(2, 2) == 1);
	assert(square(5, 14) == 4);

	return 0;
}
