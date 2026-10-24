/*

Given a list of coordinate pairs, output the Trapezoidal Riemann Sum of the values given between the first and last x-coordinates.

You will be given a sorted list of coordinate pairs, like this:

[
  [1,2],
  [3,5],
  [5,11]
]
Note that x-coordinates will always be in increasing order, ys may not.

My way to do this is (you might find a different way):

Get pairs of coordinates:

[1,2],[3,5] and [3,5],[5,11]
For each pair (let's start with the first):

Take the average of the y-values: (2 + 5) / 2 = 7/2

Take the difference of the x-values: 3 - 1 = 2

Multiply the two together to get the area of that section, which is 7/2 * 2 = 7.

Do this for all pairs. Let's quickly go through the next, [3,5],[5,11].

Average of y values = (5 + 11) / 2 = 8 Difference of x values = (5 - 3) = 2 Product of the two = 2 * 8 = 16

Now take the sum of all the values, resulting in 16+7 = 23.

Scoring
This is code-golf, shortest wins!

Testcases
[ [1,2], [3,5], [5,11] ] => 23
[ [3,4], [4,1], [7,5] ] => 11.5
[ [0,0], [9,9] ] => 40.5
[ [1,1], [2,3], [3,1], [4,3] ] => 6
Note that input will always contain non-negative integers. Tell me if any of the testcases are wrong as I worked them out by hand.

You may take a flat list, or the list with x and y swapped.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
trapz(double a[][2], size_t n)
{
	double dx, dy, r;
	size_t i;

	r = 0;
	for (i = 1; i < n; i++) {
		dx = a[i][0] - a[i - 1][0];
		dy = a[i][1] + a[i - 1][1];
		r += dx * dy;
	}
	return r * 0.5;
}

void
test(double a[][2], size_t n, double r)
{
	double v;

	v = trapz(a, n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-6);
}

int
main(void)
{
	double a1[][2] = {
	    {1, 2},
	    {3, 5},
	    {5, 11},
	};

	double a2[][2] = {
	    {3, 4},
	    {4, 1},
	    {7, 5},
	};

	double a3[][2] = {
	    {0, 0},
	    {9, 9},
	};

	double a4[][2] = {
	    {1, 1},
	    {2, 3},
	    {3, 1},
	    {4, 3},
	};

	test(a1, nelem(a1), 23);
	test(a2, nelem(a2), 11.5);
	test(a3, nelem(a3), 40.5);
	test(a4, nelem(a4), 6);

	return 0;
}
