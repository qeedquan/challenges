/*

Find the total surface area of a regular square pyramid given its base length a and height h.

Input
The input consists of a single line containing two integers: the base length a and the height h of the pyramid. All input values are integers not exceeding 100.

Output
Print the total surface area of the regular square pyramid, rounded to one decimal place.

Examples

Input #1
20 10

Answer #1
965.7

*/

#include <stdio.h>
#include <math.h>

double
solve(double a, double h)
{
	return a * (a + sqrt((a * a) + (4 * h * h)));
}

int
main()
{
	printf("%.1f\n", solve(20, 10));

	return 0;
}
