/*

You are given the length of the four sides of a trapezium; you have to calculate the area. In geometry a 4-sided figure with exactly one pair of parallel sides is called a trapezium.

https://static.lightoj.com/images/problem-1178/trapezium2-1605696949900.png?style=centerme,haveborder

Input
Input starts with an integer T (≤ 20), denoting the number of test cases.

Each case contains four real numbers a b c d denoting the sides of the trapezium. Here a and c denote the parallel sides. You can safely assume that the given trapezium is valid. Each of the numbers will be positive and not more than 200. And no number contains more than 4 digits after the decimal point.

Output
For each case, print the case number and the area. Errors less than 10-6 will be ignored.

Sample
Input	Output
2
6 5 12 5.0
9 5 6 4

Case 1: 36
Case 2: 30.0000000

*/

#include <stdio.h>
#include <math.h>

void
swap(double *a, double *b)
{
	double t;

	t = *a;
	*a = *b;
	*b = t;
}

double
solve(double a, double b, double c, double d)
{
	double ac, s, t, h, r;

	if (a < c)
		swap(&a, &c);

	ac = a - c;
	s = (b + d + ac) / 2.0;
	t = sqrt(s * (s - b) * (s - d) * (s - ac));
	h = (2.0 * t) / ac;
	r = 0.5 * (a + c) * h;
	return r;
}

int
main()
{
	printf("%.3f\n", solve(6, 5, 12, 5));
	printf("%.3f\n", solve(9, 5, 6, 4));
	return 0;
}
