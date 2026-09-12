/*

Write a function that takes an integer n and returns the nth iteration of the fractal known as Sierpinski's Gasket.

Here are the first few iterations. The fractal is composed entirely of L and white-space characters; each character has one space between it and the next (or a newline).

0
L

1
L
L L

2
L
L L
L   L
L L L L

3
L
L L
L   L
L L L L
L       L
L L     L L
L   L   L   L
L L L L L L L L

*/

#include <stdio.h>

// https://spanishplus.tripod.com/maths/FractalSierpinski.htm
void
gasket(int n)
{
	int s, x, y;

	printf("n=%d\n", n);
	s = 1 << n;
	for (y = s - 1; y >= 0; y--) {
		for (x = 0; x < s; x++) {
			if (!(x & y))
				printf("L ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 0; i <= 3; i++)
		gasket(i);
	return 0;
}
