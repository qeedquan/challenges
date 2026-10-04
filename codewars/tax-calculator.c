/*

Write a function to calculate compound tax using the following table:

For $10 and under, the tax rate should be 10%.
For $20 and under, the tax rate on the first $10 is %10, and the tax on the rest is 7%.
For $30 and under, the tax rate on the first $10 is still %10, the rate for the next $10 is still 7%, and everything else is 5%.
Tack on an additional 3% for the portion of the total above $30.
Return 0 for invalid input(anything that's not a positive real number).

Examples:
An input of 10, should return 1 (1 is 10% of 10)
An input of 21, should return 1.75 (10% of 10 + 7% of 10 + 5% of 1)
* Note that the returned value should be rounded to the nearest penny.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
tax(double total)
{
	static const struct rate {
		double bracket;
		double percent;
	} rates[] = {
		{ 0, 0.10 },
		{ 10, 0.07 },
		{ 20, 0.05 },
		{ 30, 0.03 },
	};

	const struct rate *rate;
	double value;
	size_t i;

	value = 0;
	for (i = nelem(rates); i > 0; i--) {
		rate = rates + i - 1;
		if (total >= rate->bracket) {
			value += (total - rate->bracket) * rate->percent;
			total = rate->bracket;
		}
	}

	return value;
}

void
test(double total, double expected)
{
	double value;

	value = tax(total);
	printf("%f\n", value);
	assert(fabs(value - expected) < 1e-3);
}

int
main()
{
	test(10, 1);
	test(15, 1.35);
	test(21, 1.75);
	test(25, 1.95);

	return 0;
}
