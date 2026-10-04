/*

Rybka wants to know Watson's magic number.
Watson's magic number is a determinant of Watson's magic matrix.
Watson's magic matrix is some known matrix with dimensions 3×3.

Input
Input contains three lines, each line contains three integers less than 100 in absolute value, which define Watson's magic matrix.

Output
You need to print Watson's magic number.

Examples
Input #1
1 2 3
2 3 4
2 1 1

Answer #1
-1

*/

#include <assert.h>

int
det3x3(int m[3][3])
{
	int c00, c01, c02;

	c00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	c01 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
	c02 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	return (m[0][0] * c00) + (m[0][1] * c01) + (m[0][2] * c02);
}

int
solve(int m[3][3])
{
	return det3x3(m);
}

int
main()
{
	int m[3][3] = {
		{ 1, 2, 3 },
		{ 2, 3, 4 },
		{ 2, 1, 1 },
	};

	assert(solve(m) == -1);

	return 0;
}
