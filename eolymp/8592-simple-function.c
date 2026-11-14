/*

Implement the function f(x)=x+sin(x).

Input
One real number x.

Output
Print the value of the function f(x) with 4 decimal digits.

Examples

Input #1
1.1234

Answer #1
2.0250

Input #2
-3.1415

Answer #2
-3.1416

*/

#include <stdio.h>
#include <math.h>

double
f(double x)
{
	return x + sin(x);
}

int
main()
{
	printf("%.4f\n", f(1.1234));
	printf("%.4f\n", f(-3.1415));

	return 0;
}
