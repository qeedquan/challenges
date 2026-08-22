/*

Given two positive numbers N >= 2 and N <= 100 create a matrix which follows the following rules:

First Number starts at position [0,0]
Second Number starts at position [0,1]
Third number goes below First Number (position [1,0])
Following numbers goes in "slash" direction
Range of numbers used is [1, N1 * N2]. So, numbers goes from starting 1 to the result of the multiplication of both inputs.
Input

Two numbers N >= 2 and N <= 100. First number is the amount of rows, Second number the amount of columns.
Output

Matrix. (Can be outputted as a multidimensional array or a string with line breaks)
Example:

Given numbers 3 and 5 output:

1   2   4   7   10
3   5   8   11  13
6   9   12  14  15
Given numbers 2 and 2

1   2
3   4
Given Numbers 5 and 5

1   2   4   7   11
3   5   8   12  16
6   9   13  17  20
10  14  18  21  23
15  19  22  24  25

The shortest code in bytes wins.

*/

#include <stdio.h>

void
output(int *m, int r, int c)
{
	int x, y;

	printf("[%d, %d]\n", r, c);
	for (y = 0; y < r; y++) {
		for (x = 0; x < c; x++)
			printf("% 3d", m[(y * c) + x]);
		printf("\n");
	}
	printf("\n");
}

void
slash(int *m, int r, int c)
{
	int x, y, n;

	n = 1;
	for (y = 0; y < r + c - 1; y++) {
		for (x = 0; x < r; x++) {
			if ((y - x < 0) || (y - x > c - 1))
				continue;

			m[(x * c) + (y - x)] = n++;
		}
	}
}

void
test(int r, int c)
{
	int m[128];

	slash(m, r, c);
	output(m, r, c);
}

int
main()
{
	test(3, 5);
	test(2, 2);
	test(5, 5);
	test(10, 10);

	return 0;
}
