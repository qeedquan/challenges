/*

Write a function cube_matrix_sum that calculates the sum of the elements of a 3-dimensional array.

The function should be one line long and less than 48 characters long.

Imports are prohibited

Example

cube_matrix = [
  [[1, 2, 3], [4, 5, 6], [7, 8, 9]],
  [[10,11,12],[13,14,15],[16,17,18]],
  [[19,20,21],[22,23,24],[25,26,27]]
]
cube_matrix_sum(cube_matrix) == 378
All elements of an array of type int or float. There may be negative elements.

This is my first kata and I hope you'll enjoy it :).

Best of luck!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
cube_matrix_sum(double m[][3], size_t n)
{
	size_t i;
	double r;

	r = 0;
	for (i = 0; i < n; i++)
		r += m[i][0] + m[i][1] + m[i][2];
	return r;
}

int
main()
{
	double m1[][3] = {
		{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 },
		{ 10, 11, 12 }, { 13, 14, 15 }, { 16, 17, 18 },
		{ 19, 20, 21 }, { 22, 23, 24 }, { 25, 26, 27 }
	};

	double m2[][3] = {
		{ 0, 1, 0 }, { -1, 0, 0 }, { 0, 0, 0 },
		{ -1, 0, 0 }, { 0, 0, 0 }, { 1, 0, 0 },
		{ 0, 0, 0 }, { 1.1, 0, 0 }, { -1.1, 0, 0 }
	};

	assert(cube_matrix_sum(m1, nelem(m1)) == 378);
	assert(cube_matrix_sum(m2, nelem(m2)) == 0);

	return 0;
}
