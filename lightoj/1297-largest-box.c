/*

In the following figure, you can see a rectangular card. The width of the card is W, length of the card is L and thickness is zero. Four (x*x) squares are cut from the four corners of the card shown by the black dotted lines. Then the card is folded along the red lines to make a box without a cover.

https://static.lightoj.com/images/problem-1297/largest_box-1605685659204.png?style=centerme,haveborder

Given the width and height of the box, you will have to find the maximum volume of the box you can make for any value of x.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case starts with a line containing two real numbers L and W (0 < L, W < 100).

Output
For each case, print the case number and the maximum volume of the box that can be made. Errors less than 10^-6 will be ignored.

Sample
Input	Output
3
2 10
3.590 2.719
8.1991 7.189

Case 1: 4.513804324
Case 2: 2.2268848896
Case 3: 33.412886

*/

#include <stdio.h>
#include <math.h>

/*

volume(x) = (w - 2x) * (l - 2x) * x

Expand:
volume(x) = wlx - 2 wx^2 - 2 lx^2 + 4 x^3

Use calculus to maximize the function, get the following:

x = (w + l) - sqrt(w^2 + l^2 - wl) / 6

*/

double
solve(double l, double w)
{
	double x;

	x = ((w + l) - sqrt((w * w) + (l * l) - (w * l))) / 6;
	return (w - (2 * x)) * (l - (2 * x)) * x;
}

int
main()
{
	printf("%f\n", solve(2, 10));
	printf("%f\n", solve(3.590, 2.719));
	printf("%f\n", solve(8.1991, 7.189));

	return 0;
}
