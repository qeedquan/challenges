/*

Determine the height of a triangle with area S if its base exceeds its height by a.

Input
Two integers S (0<S≤100) and a (∣a∣≤100).

Output
Print the height of the triangle with an accuracy of two decimal places.

Examples

Input #1
15 1

Answer #1
5.00

*/

#include <cstdio>
#include <cmath>

double solve(double S, double a)
{
	auto D = (a * a) + (8 * S);
	auto h = (-a + sqrt(D)) / 2;
	return h;
}

int main()
{
	printf("%.2f\n", solve(15, 1));

	return 0;
}
