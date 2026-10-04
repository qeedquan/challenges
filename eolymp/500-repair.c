/*

Your uncle is the director of a company that renovates offices. Due to the financial and economic crisis, he decided to optimize his business.

There have been rumors that the team leader of the company purchases extra building materials, using the remainder for his own needs.
Your uncle is interested in how many cans of paint are actually needed to paint the walls of an office with length l meters, width w meters, and height h meters.
One can of paint covers 16m^2, and you can ignore the sizes of doors and windows.
Since there are many orders, your uncle has asked you to write a program to perform these calculations.

Input
The first line contains the number of orders.
Each order is described by three positive integers l, w, h — the length, width, and height of the office in meters, respectively. Each value does not exceed 1000.

Output
For each order, output on a separate line the number of paint cans required to paint the office walls.

Examples

Input #1
2
8 8 2
1 1 3

Answer #1
4
1

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
solve(int l, int w, int h)
{
	double r;

	r = (l * h * 2) + (w * h * 2);
	return ceil(r / 16);
}

int
main()
{
	assert(solve(8, 8, 2) == 4);
	assert(solve(1, 1, 3) == 1);

	return 0;
}
