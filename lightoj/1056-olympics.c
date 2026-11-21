/*

The next Olympic is approaching very shortly. It's a hard job for the organizers. There are so many things to do - preparing the venues, building the Olympic village for accommodating athletes and officials, improving the transportation of the entire city as the venues are located all over the city and also there will be great number of tourists/spectators during the Olympics.

https://static.lightoj.com/images/problem-1056/1-1604093152408.jpg?style=centerme,haveborder

One of the most important tasks is to build the stadium. You are appointed as a programmer to help things out in certain matters - more specifically in designing and building the athletics tracks. After some study, you find out that athletics tracks have a general shape of a rectangle with two sliced circles on two ends. Now the turf that is placed inside this rectangle is prepared elsewhere and comes in different shapes - different length to width ratios. You know one thing for certain - your track should have a perimeter of 400 meters. That's the standard length for athletics tracks. You are supplied with the design parameter - length to width ratio. You are also told that the sliced circles will be such that they are part of the same circle. You have to find the length and width of the rectangle.

Input
Input starts with an integer T (≤ 1000), denoting the number of test cases.

Each case starts with the ratio of the length and width of the rectangle in the format: "a : b". Here, a and b will be integers and both will be between 1 and 1000 (inclusive).

Output
For each case, print the case number, the length and the width. Errors less than 10-6 will be ignored.

Sample
Input	Output
2
3 : 2
5 : 4

Case 1: 117.1858168 78.12387792
Case 2: 107.29095604 85.8327648

*/

#include <stdio.h>
#include <math.h>

void
solve(double a, double b, double *l, double *w)
{
	double r, t, s, x;

	r = sqrt(a * a + b * b) / 2.0;
	t = acos((2.0 * r * r - b * b) / (2.0 * r * r));
	s = r * t;
	x = 400.0 / (2 * (a + s));
	*l = x * a;
	*w = x * b;
}

void
test(double a, double b)
{
	double l, w;

	solve(a, b, &l, &w);
	printf("%f %f\n", l, w);
}

int
main()
{
	test(3, 2);
	test(5, 4);
	return 0;
}
