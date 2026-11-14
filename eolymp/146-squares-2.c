/*

Starting with a white square, perform the following operation n times: at each step, take one of the smallest remaining white squares, divide it into 4 equal squares, and paint 2 of them black.
Given n, calculate what percentage of the total area is black after all operations.

Input
The input contains one integer n (1≤n≤100).

Output
Print the percentage of the area that is black, rounded to 5 decimal places.

Examples

Input #1
1

Answer #1
50.00000

*/

#include <stdio.h>

double
solve(int n)
{
	double k, p;
	int i;

	k = 1;
	p = 0;
	for (i = 0; i < n; i++) {
		p = p + (k / 2) * 100;
		k = k / 4;
	}
	return p;
}

int
main()
{
	int i;

	for (i = 0; i <= 50; i++)
		printf("%f\n", solve(i));
	return 0;
}
