/*

Aim
Consider this infinite array of numbers:

 | 0  1  2  3  4  5  6  7
−+−−−−−−−−−−−−−−−−−−−−−−−
0| 0  2  5  9 14 20 27 35
1| 1  4  8 13 19 26 34
2| 3  7 12 18 25 33
3| 6 11 17 24 32
4|10 16 23 31
5|15 22 30
6|21 29
7|28
(The numbers from 0-7 at the left are row numbers; The numbers from 0-7 at the top are column numbers

Input: 4 non-negative integers specifying the size of the box (row number of top, column number of left, row number of bottom, column number of right)

Output: Sum of all integers in the box

Test cases:

a,b,c,d -> sum
0,0,1,2 -> 20 #0+2+5+1+4+8
2,0,6,1 -> 140 #3+7+6+11+10+16+15+22+21+29
1,2,2,3 -> 51 #8+13+12+18
0,0,0,0 -> 0 #0
You can assume a≤c and b≤d.

Other options:
The four integers can be taken in any order
You can take the coordinates of one specified corner as well as the width and height. In that case, you can assume width and height are positive integers.
Coordinates can be 0-indexed or 1-indexed
Ranges can be inclusive at both ends, exclusive at both ends or inclusive at one end and exclusive at the other. In that case, you can assume the rectangle has at least 1 row and at least 1 column.
These choices must be specified in the answer.

Shortest code wins.

*/

#include <assert.h>
#include <stdio.h>

int
interior(int a, int b, int c, int d)
{
	int x, y, r;

	r = 0;
	for (x = b; x <= d; x++) {
		for (y = a; y <= c; y++)
			r += (x + (x + y) * (x + y + 1) / 2);
	}
	return r;
}

int
main()
{
	assert(interior(0, 0, 1, 2) == 20);
	assert(interior(2, 0, 6, 1) == 140);
	assert(interior(1, 2, 2, 3) == 51);
	assert(interior(0, 0, 0, 0) == 0);

	return 0;
}
