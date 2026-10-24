/*

See the picture below.

https://static.lightoj.com/images/problem-1043/triangle-1656822486325.png?centerme,haveborder,smallme

You are given AB, AC and BC. DE is parallel to BC. You are also given the area ratio between ADE and BDEC. You have to find the value of AD.

Input
Input starts with an integer T (≤ 25), denoting the number of test cases.

Each case begins with four real numbers denoting AB, AC, BC and the ratio of ADE and BDEC (ADE / BDEC). You can safely assume that the given triangle is a valid triangle with positive area.

Output
For each case of input you have to print the case number and AD. Errors less than 10-6 will be ignored.

Sample
Input	Output
4
100 100 100 2
10 12 14 1
7 8 9 10
8.134 9.098 7.123 5.10

Case 1: 81.6496580
Case 2: 7.07106781
Case 3: 6.6742381247
Case 4: 7.437454786

*/

#include <stdio.h>
#include <math.h>

double
solve(double ab, double, double, double r)
{
	return ab * sqrt(r / (r + 1));
}

int
main()
{
	printf("%f\n", solve(100, 100, 100, 2));
	printf("%f\n", solve(10, 12, 14, 1));
	printf("%f\n", solve(7, 8, 9, 10));
	printf("%f\n", solve(8.134, 9.098, 7.123, 5.10));

	return 0;
}
