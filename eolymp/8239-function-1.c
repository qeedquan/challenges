/*

Implement the function f(x) = x^3 + 2*x^2 - 3.

Input
Each line contains one real number x.

Output
For each value of x, print the value of the function f(x) on a separate line with four decimal places.

Examples

Input #1
2.234
1
56
23.2

Answer #1
18.1309
0.0000
181885.0000
13560.6480

*/

#include <stdio.h>

double
solve(double x)
{
	return (x * x * x) + (2 * x * x) - 3;
}

int
main()
{
	printf("%.4f\n", solve(2.234));
	printf("%.4f\n", solve(1));
	printf("%.4f\n", solve(56));
	printf("%.4f\n", solve(23.2));

	return 0;
}
