/*

 Brick "pyramid".

"Pyramid" is infinite.
"Pyramid" is two-dimensional (triangle).

(row, pos) - function parameters.
row - top row number ranging from zero,
pos - brick number from left to right ranging from zero.

Brick weight - 1 kg.

Every brick equally presses the bricks underneath.
1/2 to the left brick and 1/2 to the right.

If the brick pressed above with the total mass of 100 kg than the pressure is distributed evenly on the bottom bricks.

Required: implement function weight that calculates the pressure on the brick on the row, pos position.

Testing values:

weight(0, 0) => 0

weight(1, 0) => 0.5
weight(1, 1) => 0.5

weight(2, 0) => 0.75
weight(2, 1) => 1.5
weight(2, 2) => 0.75

weight(3, 0) => 0.875
weight(3, 1) => 2.125
weight(3, 2) => 2.125
weight(3, 3) => 0.875

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
triangular(double n)
{
	return n * (n + 1) / 2;
}

double
weight(int row, int pos)
{
	double sum, half;
	int i;

	sum = 0;
	half = 1;
	for (i = 0; i < row; i++) {
		half *= 0.5;
		sum += half;
	}
	if (pos > 0 && pos != row)
		return (triangular(row) - (2 * sum)) / (row - 1);
	return sum;
}

void
test(double val, double res)
{
	printf("%f %f\n", val, res);
	assert(fabs(val - res) < 1e-12);
}

int
main()
{
	test(weight(0, 0), 0);
	test(weight(1, 0), 0.5);
	test(weight(1, 1), 0.5);
	test(weight(2, 0), 0.75);
	test(weight(2, 1), 1.5);
	test(weight(2, 2), 0.75);

	test(weight(3, 0), 0.875);
	test(weight(3, 1), 2.125);
	test(weight(3, 2), 2.125);
	test(weight(3, 3), 0.875);

	return 0;
}
