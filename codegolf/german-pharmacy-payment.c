/*

Your task is to calculate the amount you have to pay for prescribed medication at a pharmacy in Germany. The amount is simply based on the full price of the item, which will be your input. It is a decimal number with exactly two fractional digits (ex. 5.43). You can assume it's strictly positive. Your task is to calculate the amount a customer has to pay, according to this function:

A(x) = x    if x <= 5
       5    if 5 <= x <= 50
       0.1x if 50 <= x <= 100
       10   if 100 <= x

or equivalently

A(x) = min(x, min(max(0.1x, 5), 10))

The result must be rounded to two decimal places (half up). You can take numbers as input and output, bu be aware of inexact floating point representations. Use a comma or a point as the decimal separator.
Test cases

(Whitespace just for readability)

  0.00  ->  0.00
  4.99  ->  4.99
  5.00  ->  5.00
  50.00 ->  5.00
  50.04 ->  5.00
  50.05 ->  5.01
  50.14 ->  5.01
  50.15 ->  5.02
  99.84 ->  9.98
  99.85 ->  9.99
  99.94 ->  9.99
  99.95 -> 10.00
 100.00 -> 10.00
1000.00 -> 10.00

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
cost(double x)
{
	return fmin(x, fmin(fmax(0.1 * x, 5), 10));
}

void
test(double x, double r)
{
	double v;

	v = cost(x);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-2);
}

int
main(void)
{
	test(0.00, 0.00);
	test(4.99, 4.99);
	test(5.00, 5.00);
	test(50.00, 5.00);
	test(50.04, 5.00);
	test(50.05, 5.01);
	test(50.14, 5.01);
	test(50.15, 5.02);
	test(99.84, 9.98);
	test(99.85, 9.99);
	test(99.94, 9.99);
	test(99.95, 10.00);
	test(100.00, 10.00);
	test(1000.00, 10.00);

	return 0;
}
