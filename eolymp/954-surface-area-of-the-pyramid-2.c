/*

Determine the lateral surface area of a right truncated square pyramid with base sides a, b and height h.

Input
A single line contains the integers a, b, and h (1≤a,b,h≤100), separated by spaces.

Output
Output the lateral surface area, rounded to two decimal places.

Examples

Input #1
20 10 10

Answer #1
670.82

*/

#include <stdio.h>
#include <math.h>

double
sqr(double x)
{
	return x * x;
}

double
solve(double a, double b, double h)
{
	return (a + b) * sqrt((4 * h * h) + sqr(a - b));
}

int
main()
{
	printf("%.3f\n", solve(20, 10, 10));

	return 0;
}
