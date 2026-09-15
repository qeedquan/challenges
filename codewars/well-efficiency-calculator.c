/*

In this kata you have a 20 x 20 preloaded array of oil saturation in some region.
Your task is to answer whether it is efficient to place the well at the given point.
A well is efficient if its efficiency is bigger or equal to given threshold.

Input parameters in that function are:

x and y integer coordinates of the well (indexes of 2D array, using x for rows, y for columns)
efficiency threshold (float or integer)

The preloaded FIELD contains values from 0.00 to 0.99 inclusive, such as:

0.98, 0.65, 0.23, 0.39, 0.99...

(In Python and Ruby each value is stored as a string. In C each value is stored as a double)

Examples of usage:

x = 10
y = 10
threshold = 3.5
expected result => true / true

x = 7
y = 3
threshold = 4.5
expected result => False / false

To calculate the current efficiency of a well, you should sum up all saturations of cells adjacent to the specified cell plus the saturation of the specified cell itself.

The efficiency of the marked point with 0.43 is 5.3 (sum of all cells in square).

If you need to calculate the efficiency at the edge of the field, you should just take in account only cells in the field.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
efficient(double field[20][20], int x, int y, double threshold)
{
	int i0, i1;
	int j0, j1;
	int i, j;
	double sum;

	i0 = max(0, x - 1);
	i1 = min(20, x + 2);
	j0 = max(0, y - 1);
	j1 = min(20, y + 2);

	sum = 0;
	for (i = i0; i < i1; i++) {
		for (j = j0; j < j1; j++)
			sum += field[i][j];
	}
	return sum >= threshold;
}

int
main()
{
	double field[20][20] = {
		{ 0.10, 0.77, 0.18, 0.31, 0.79, 0.11, 0.01, 0.46, 0.76, 0.52, 0.22, 0.74, 0.79, 0.57, 0.49, 0.93, 0.33, 0.79, 0.91, 0.24 },
		{ 0.47, 0.86, 0.18, 0.55, 0.32, 0.70, 0.36, 0.84, 0.23, 0.21, 0.17, 0.18, 0.70, 0.54, 0.29, 0.18, 0.11, 0.57, 0.15, 0.11 },
		{ 0.17, 0.35, 0.35, 0.81, 0.03, 0.04, 0.14, 0.92, 0.85, 0.41, 0.37, 0.52, 0.12, 0.87, 0.84, 0.43, 0.82, 0.39, 0.87, 0.20 },
		{ 0.09, 0.55, 0.14, 0.89, 0.22, 0.05, 0.45, 0.78, 0.06, 0.71, 0.39, 0.09, 0.38, 0.76, 0.71, 0.38, 0.55, 0.26, 0.58, 0.62 },
		{ 0.50, 0.88, 0.06, 0.77, 0.56, 0.97, 0.09, 0.93, 0.03, 0.80, 0.82, 0.18, 0.80, 0.95, 0.86, 0.33, 0.36, 0.57, 0.91, 0.07 },
		{ 0.56, 0.67, 0.07, 0.79, 0.53, 0.04, 0.68, 0.17, 0.11, 0.20, 0.58, 0.36, 0.69, 0.01, 0.39, 0.53, 0.57, 0.40, 0.56, 0.03 },
		{ 0.60, 0.77, 0.89, 0.71, 0.25, 0.22, 0.69, 0.32, 0.82, 0.90, 0.22, 0.82, 0.23, 0.84, 0.60, 0.80, 0.38, 0.66, 0.76, 0.15 },
		{ 0.71, 0.16, 0.86, 0.48, 0.95, 0.82, 0.45, 0.21, 0.51, 0.68, 0.27, 0.60, 0.45, 0.86, 0.68, 0.64, 0.47, 0.15, 0.76, 0.18 },
		{ 0.12, 0.33, 0.27, 0.85, 0.87, 0.93, 0.37, 0.36, 0.86, 0.14, 0.95, 0.95, 0.55, 0.39, 0.64, 0.51, 0.43, 0.40, 0.99, 0.09 },
		{ 0.33, 0.94, 0.46, 0.68, 0.32, 0.95, 0.03, 0.31, 0.95, 0.79, 0.67, 0.77, 0.56, 0.82, 0.60, 0.02, 0.04, 0.97, 0.74, 0.27 },
		{ 0.53, 0.55, 0.27, 0.97, 0.34, 0.45, 0.31, 0.47, 0.65, 0.79, 1.00, 0.81, 0.29, 0.70, 0.78, 0.31, 0.57, 0.45, 0.70, 0.03 },
		{ 0.88, 0.85, 0.08, 0.31, 0.91, 0.72, 0.74, 0.38, 0.62, 0.96, 0.59, 0.39, 0.04, 0.75, 0.94, 0.46, 0.70, 0.10, 0.90, 0.66 },
		{ 0.65, 0.82, 0.57, 0.16, 0.55, 0.55, 0.65, 0.14, 0.48, 0.44, 0.23, 0.99, 0.48, 0.99, 0.59, 0.34, 0.35, 0.03, 0.85, 0.13 },
		{ 0.30, 0.73, 0.37, 0.53, 0.45, 0.50, 0.51, 0.11, 0.42, 0.59, 0.98, 0.36, 0.32, 0.92, 0.47, 0.18, 0.30, 0.71, 0.36, 0.56 },
		{ 0.18, 0.31, 0.97, 0.33, 0.04, 0.72, 0.11, 0.98, 0.38, 0.23, 0.15, 0.57, 0.48, 0.13, 0.81, 0.98, 0.33, 0.71, 0.88, 0.82 },
		{ 0.40, 0.76, 0.42, 0.87, 0.77, 0.04, 0.49, 0.24, 0.60, 0.86, 0.04, 0.61, 0.13, 0.72, 0.73, 0.29, 0.78, 0.73, 0.64, 0.16 },
		{ 0.63, 0.54, 0.64, 0.77, 0.28, 0.00, 0.70, 0.17, 0.90, 0.48, 0.89, 0.28, 0.20, 0.98, 0.26, 0.54, 0.83, 0.44, 0.69, 0.29 },
		{ 0.36, 0.95, 0.94, 0.22, 0.85, 0.30, 0.67, 0.19, 0.44, 0.79, 0.03, 0.64, 0.90, 0.27, 0.92, 0.53, 0.69, 1.00, 0.79, 0.22 },
		{ 0.17, 0.30, 0.94, 0.96, 0.57, 0.99, 0.73, 0.35, 0.52, 0.65, 0.48, 0.89, 0.50, 0.88, 0.54, 0.46, 0.69, 0.35, 0.98, 0.14 },
		{ 0.94, 0.11, 0.67, 0.85, 0.38, 0.20, 0.51, 0.99, 0.48, 0.10, 0.17, 0.76, 0.06, 0.30, 0.94, 0.64, 0.21, 0.45, 0.72, 0.57 },
	};

	assert(efficient(field, 10, 10, 2.5) == true);
	assert(efficient(field, 12, 3, 1.5) == true);
	assert(efficient(field, 12, 3, 7.5) == false);
	assert(efficient(field, 17, 11, 3) == true);
	assert(efficient(field, 8, 9, 6) == false);

	return 0;
}
