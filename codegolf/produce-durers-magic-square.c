/*

The challenge

Output an array or string representation of Dürer's famous magic square:

enter image description here

that is,

16  3  2 13
 5 10 11  8
 9  6  7 12
 4 15 14  1
Some properties of this square, which can perhaps be exploited, are:

It contains each integer from 1 to 16 exactly once
The sum of each column or row, as well as the the sum of each of the two diagonals, is the same. This is the defining property of a magic square. The sum is the magic constant of the square.
In addition, for this particular square, the sum of each of the four quadrants also equals the magic constant, as do the sum of the center four squares and the sum of the corner four squares.
Rules
Bultins that generate magic squares are not allowed (such as Matlab's magic or Mathematica's MagicSquare). Any other builtin can be used.

The code can be a program or a function.

There is no input.

The numbers must be in base 10. The output format is flexible as usual. Some possibilities are:

A nested array (either function output, or its string representation, with or without separators, any type of matching brackets):

[[16, 3, 2, 13], [5, 10, 11, 8], [9, 6, 7, 12], [4, 15, 14, 1]]
A 2D array:

{16, 3, 2, 13; 5, 10, 11, 8; 9, 6, 7, 12; 4, 15, 14, 1}
An array of four strings, or a string consisting of four lines. The numbers may be right-aligned

16  3  2 13
 5 10 11  8
 9  6  7 12
 4 15 14  1
or left-aligned

16 3  2  13
5  10 11  8
9  6  7  12
4  15 14  1
A string with two different separators for row and column, such as

16,3,2,13|5,10,11,8|9,6,7,12|4,15,14,1
The output format should clearly differentiate rows and columns. For example, it is not allowed to output a flat array, or a string with all numbers separated by spaces.

Code golf. Shortest wins.

*/

#include <stdio.h>

void
durer(void)
{
	static const int sq[4][4] = {
	    {16, 3, 2, 13},
	    {5, 10, 11, 8},
	    {9, 6, 7, 12},
	    {4, 15, 14, 1},
	};

	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			printf("%3d", sq[i][j]);
		printf("\n");
	}
}

int
main(void)
{
	durer();
	return 0;
}
