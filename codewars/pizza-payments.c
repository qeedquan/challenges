/*

Kate and Michael want to buy a pizza and share it. Depending on the price of the pizza, they are going to divide the costs:

If the pizza is less than €5,- Michael invites Kate, so Michael pays the full price.
Otherwise Kate will contribute 1/3 of the price, but no more than €10 (she's broke :-) and Michael pays the rest.
How much is Michael going to pay? Calculate the amount with two decimals, if necessary.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
pays(double cost)
{
	double part;

	part = 0;
	if (cost >= 5)
		part = fmin(cost / 3, 10);
	return cost - part;
}

void
test(double cost, double expected)
{
	double value;

	value = pays(cost);
	printf("%.2f\n", value);
	assert(fabs(value - expected) < 1e-2);
}

int
main()
{
	test(15, 10);
	test(4, 4);
	test(30, 20);
	test(80, 70);
	test(22, 14.67);
	test(5.9181, 3.95);
	test(28.789, 19.19);
	test(4.325, 4.33);

	return 0;
}
