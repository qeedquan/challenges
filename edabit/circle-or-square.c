/*

Given the radius of a circle and the area of a square, return true if the circumference of the circle is greater than the square's perimeter and false if the square's perimeter is greater than the circumference of the circle.

Examples
circleOrSquare(16, 625) ➞ true

circleOrSquare(5, 100) ➞ false

circleOrSquare(8, 144) ➞ true

Notes
You can use Pi to 2 decimal places (3.14).
Circumference of a circle equals 2 * Pi * radius.
To find the perimeter of a square using its area, find the square root of area (to get side length) and multiply that by 4.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <math.h>

#define TAU (2 * M_PI)

#define sqr(x) ((x) * (x))

bool
circle_or_square(double r, double a)
{
	return sqr(TAU * r) > (16 * a);
}

int
main()
{
	assert(circle_or_square(16, 625) == true);
	assert(circle_or_square(5, 100) == false);
	assert(circle_or_square(8, 144) == true);

	return 0;
}
