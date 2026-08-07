/*

Task
Fred Mapper is considering purchasing some land in Louisiana to build his house on. In the process of investigating the land, he learned that the state of Louisiana is actually shrinking by 50 square miles each year, due to erosion caused by the Mississippi River. Since Fred is hoping to live in this house the rest of his life, he needs to know if his land is going to be lost to erosion.

After doing more research, Fred has learned that the land that is being lost forms a semicircle. This semicircle is part of a circle centered at (0,0), with the line that bisects the circle being the x axis. Locations below the x axis are in the water. The semicircle has an area of 0 at the beginning of year 1. (Semicircle illustrated in the Figure.)

https://i.ibb.co/tYhJSKw/semicircle.gif

Given two coordinates x and y, your task is to calculate that Fred Mapper's house will begin eroding in how many years.

Note:

No property will appear exactly on the semicircle boundary: it will either be inside or outside.

All locations are given in miles.

(0,0) will not be given.

Example
For x = 1, y = 1, the result should be 1.

After 1 year, Fred Mapper's house will begin eroding.

For x = 25, y = 0, the result should be 20.

After 20 year, Fred Mapper's house will begin eroding.

Input/Output
[input] integer x
The X coordinates of the land Fred is considering. It will be an integer point numbers measured in miles.

-100 <= x <= 100

[input] integer y
The Y coordinates of the land Fred is considering. It will be an integer point numbers measured in miles.

0 <= y <= 100

[output] an integer
The first year (start from 1) this point will be within the semicircle AT THE END OF YEAR.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <math.h>

int
square(int x, int y)
{
	return (x * x) + (y * y);
}

double
needhouseboat(double x, double y)
{
	double r;

	r = 1;
	while (square(x, y) > (100 * r / M_PI))
		r += 1;
	return r;
}

int
main()
{
	assert(needhouseboat(1, 1) == 1);
	assert(needhouseboat(25, 0) == 20);

	return 0;
}
