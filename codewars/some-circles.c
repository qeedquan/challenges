/*

Write a function that takes as its parameters one or more numbers which are the diameters of circles.

The function should return the total area of all the circles, rounded to the nearest integer in a string that says "We have this much circle: xyz".

You don't know how many circles you will be given, but you can assume it will be at least one.

So:

sumCircles(2) == "We have this much circle: 3"
sumCircles(2, 3, 4) == "We have this much circle: 23"
Translations and comments (and upvotes!) welcome!

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
area(double d)
{
	return d * d * 0.25 * M_PI;
}

int
circles(int *d, size_t n)
{
	double r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++)
		r += area(d[i]);
	return round(r);
}

int
main()
{
	int d1[] = {2};
	int d2[] = {2, 3, 4};

	assert(circles(d1, nelem(d1)) == 3);
	assert(circles(d2, nelem(d2)) == 23);

	return 0;
}
