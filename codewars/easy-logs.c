/*

Add two logs with base X, with the value of A and B.
Example log A + log B where the base is X.

*/

#include <assert.h>
#include <math.h>

double
logs(double x, double a, double b)
{
	return log(a * b) / log(x);
}

void
test(double v, double r)
{
	assert(fabs(v - r) < 1e-12);
}

int
main()
{
	test(logs(10, 2, 3), 0.7781512503836435);
	test(logs(5, 2, 3), 1.1132827525593785);
	test(logs(1000, 2, 3), 0.25938375012788123);
	return 0;
}
