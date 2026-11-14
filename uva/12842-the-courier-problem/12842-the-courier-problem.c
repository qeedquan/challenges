#include <stdio.h>
#include <math.h>

/*

army = v
courier = u

solve for time:
L/v = L/(u-v) + L/(u+v) =>
u^2 - v^2 = 2v
result = L/v * u

Let
u = 1 =>
v = (-2 + sqrt(8)) / 2

*/

double
solve(double L)
{
	double u, v;

	u = 1;
	v = (-2 + sqrt(8)) / 2.0;
	return (L / v) * u;
}

int
main()
{
	printf("%.2f\n", solve(50));

	return 0;
}
