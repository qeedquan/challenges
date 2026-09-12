/*

Write a program that outputs a table of values for the function

y=3⋅sin(x)
over the interval from a to b inclusive, with a step size of h.

Input
Three real numbers a, b, and h.

Output
For each value of x in the given interval, output two numbers x and y on a separate line, in ascending order of x.
Both numbers must be output with three decimal places.

Examples

Input #1
1 2 0.5

Answer #1
1.000 2.524
1.500 2.992
2.000 2.728

*/

#include <stdio.h>
#include <math.h>

void
solve(double x0, double x1, double dx)
{
	double x;

	for (x = x0; x <= x1; x += dx)
		printf("%.3f %.3f\n", x, 3 * sin(x));
}

int
main()
{
	solve(1, 2, 0.5);

	return 0;
}
