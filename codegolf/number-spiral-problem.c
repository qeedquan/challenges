/*

A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

1 2 9 10 25
4 3 8 11 24
5 6 7 12 23
16 15 14 13 22
17 18 19 20 21

Your task is to find out the number in row y and column x.

Example:

Input: 2 3
Out  : 8
Input: 1 1
Out  : 1
Input: 4 2
Out  : 15
Note:

Any programming language is allowed.
This is a code-golf challenge so shortest code wins.
Best of Luck!
Source: https://cses.fi/problemset/task/1071

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

@Doorknob

The spiral has several "arms":

12345
22345
33345
44445
55555

The position (x, y) is located on arm max(x, y) (assigned to variable z). Then, the largest number on arm n is n^2, which alternates between being in the bottom left and top right position on the arm.
Subtracting x from y gives the sequence -n+1,-n+2,…,-1,0,1,…,n-1,n-2 moving along arm n, so we choose the appropriate sign based on the parity of n, adjust by n-1 to get a sequence starting at 0, and subtract this value from n^2.

*/

int
spiral(int x, int y)
{
	int z, w;

	z = max(x, y);
	w = (z & 1) ? y - x : x - y;
	return (z * z) - z + w + 1;
}

int
main(void)
{
	assert(spiral(2, 3) == 8);
	assert(spiral(1, 1) == 1);
	assert(spiral(4, 2) == 15);
	assert(spiral(1, 5) == 25);

	return 0;
}
