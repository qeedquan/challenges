/*

Area of an arrow
An arrow is formed in a rectangle with sides a and b by joining the bottom corners to the midpoint of the top edge and the centre of the rectangle.

a and b are integers and > 0

Write a function which returns the area of the arrow.

*/

#include <assert.h>

double
area(int a, int b)
{
	return 0.25 * a * b;
}

int
main()
{
	assert(area(4, 2) == 2);
	assert(area(7, 6) == 10.5);
	assert(area(25, 25) == 156.25);
	return 0;
}
