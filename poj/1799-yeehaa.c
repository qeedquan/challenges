/*

Description

Background
George B. wants to be more than just a good American. He wants to make his daddy proud and become a western hero. You know, like John Wayne.
But sneaky as he is, he wants a special revolver that will allow him to shoot more often than just the usual six times. This way he can fool and kill the enemy easily (at least that's what he thinks).
Problem
George has kidnapped ... uh, I mean ... "invited" you and will only let you go if you help him with the math. The piece of the revolver that contains the bullets looks like this (examples for 6 and 17 bullets):

http://poj.org/images/1799_1.jpg

There is a large circle with radius R and n little circles with radius r that are placed inside on the border of the large circle. George wants his bullets to be as large as possible, so there should be no space between the circles. George will decide how large the whole revolver will be and how many bullets it shall contain.Your job is, given R and n, to compute r.
Input

The first line contains the number of scenarios. For each scenario follows a line containing a real number R and an integer n, with 1 <= R <= 100 and 2 <= n <= 100.
Output

The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print the value for r, rounded to three decimal places. Terminate the output for the scenario with a blank line.
Sample Input

4
4.0 6
4.0 17
3.14159 100
42 2
Sample Output

Scenario #1:
1.333

Scenario #2:
0.621

Scenario #3:
0.096

Scenario #4:
21.000
Source

TUD Programming Contest 2004, Darmstadt, Germany

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
revolver(double R, int n)
{
	double s;

	s = sin(M_PI / n);
	return (R * s) / (1.0 + s);
}

void
test(double R, int n, double r)
{
	double v;

	v = revolver(R, n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	test(4.0, 6, 1.333);
	test(4.0, 17, 0.621);
	test(3.14159, 100, 0.096);
	test(42, 2, 21.000);

	return 0;
}
