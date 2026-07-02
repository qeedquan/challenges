/*

Corner circle
A circle with radius r is placed in a right angled corner, where r is an integer and ≥ 1.

circles https://i.imgur.com/9HWl86o.png

What is the radius of the smaller circle, rounded to two decimal places?

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
cornercircle(double r)
{
	return (3 * r) - (2 * r * M_SQRT2);
}

int
main()
{
	printf("%f\n", cornercircle(1));
	printf("%f\n", cornercircle(2));
	return 0;
}
