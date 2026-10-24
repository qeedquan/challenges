/*

Implement the function f(x, y) = x^2 + sin(x*y) - y^2.

Input
Each line contains two real numbers x and y.

Output
For each test case, print on a separate line the value of the function f(x,y) with four decimal places.

Examples
Input #1
2.234 2.12
10 23
56.1 0.012
23.26 5.1

Answer #1
-0.5034
-429.6161
3147.8333
514.3327

*/

#include <stdio.h>
#include <math.h>

double
f(double x, double y)
{
	return (x * x) + sin(x * y) - (y * y);
}

int
main()
{
	printf("%.4f\n", f(2.234, 2.12));
	printf("%.4f\n", f(10, 23));
	printf("%.4f\n", f(56.1, 0.012));
	printf("%.4f\n", f(23.26, 5.1));

	return 0;
}
