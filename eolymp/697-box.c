/*

A confectionery factory needs boxes for chocolates made from square cardboard sheets of size a×a.
The box should be open from the top and have a square base.
The box is created in two steps.
In the first step, square pieces of size b×b are cut from each corner of the cardboard sheet.
In the second step, the rectangular sides are folded up at a 90∘ angle to form the box.
Given the length of the cardboard sheet's side a, find the height b that maximizes the volume of the box.

https://static.e-olymp.com/content/2d/2d45c6ac57142a01982e751d19377ccb8ea0b383.jpg

Input
The first line contains the number of tests n (1≤n≤10). Each of the next n lines contains a real number a (1≤a≤10^14).

Output
For each test, print the optimal height b with 10 decimal digits after the decimal point.

Examples

Input #1
1
34

Answer #1
5.6666666667

*/

#include <stdio.h>
#include <math.h>

double
solve(double a)
{
	return a / 6;
}

int
main()
{
	printf("%.10f\n", solve(34));

	return 0;
}
