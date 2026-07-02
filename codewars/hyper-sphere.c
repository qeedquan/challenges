/*

To pass this kata you are required to complete the function in_sphere?. You will be given an array of cordinates and a radius. The function should return true if the coordinates describe a point within the given radius of the origin ([0,0...0]). A point with no co-ordinates should return true. (In zero dimensions all points are the same point)

In two dimensions the condition that any [x,y] co-ordinate lies in a circle is:-

x^2 + y^2 <= radius^2

This generalises to higer dimensions as follows.

x1^2 + x2^2 + ... xn^2 <= radius^2

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
insphere(double *x, size_t n, double r)
{
	double v;
	size_t i;

	v = 0;
	for (i = 0; i < n; i++)
		v += x[i] * x[i];
	return v <= r * r;
}

int
main()
{
	double x1[] = {1, 2, 3, 4};

	assert(insphere(x1, nelem(x1), 1000) == true);
	assert(insphere(x1, nelem(x1), 1) == false);
	return 0;
}
