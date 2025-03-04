/*

You and your best friend Stripes have just landed your first high school jobs! You'll be delivering newspapers to your neighbourhood on weekends. For your services you'll be charging a set price depending on the quantity of the newspaper bundles.

The cost of deliveries is:

$3.85 for 40 newspapers
$1.93 for 20
$0.97 for 10
$0.49 for 5
$0.10 for 1
Stripes is taking care of the footwork doing door-to-door drops and your job is to take care of the finances. What you'll be doing is providing the cheapest possible quotes for your services.

Write a function that's passed an integer representing the amount of newspapers and returns the cheapest price. The returned number must be rounded to two decimal places.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
quote(int n)
{
	static const int unit[] = { 40, 20, 10, 5, 1 };
	static const double cost[] = { 3.85, 1.93, 0.97, 0.49, 0.10 };

	double r;
	size_t i;
	int d;

	r = 0;
	for (i = 0; i < nelem(unit); i++) {
		d = n / unit[i];
		r += d * cost[i];
		n -= d * unit[i];
	}
	return r;
}

int
main()
{
	assert(quote(40) == 3.85);
	assert(quote(20) == 1.93);
	assert(quote(10) == 0.97);
	assert(quote(5) == 0.49);
	assert(quote(1) == 0.10);

	assert(quote(41) == 3.95);
	assert(quote(80) == 7.70);
	assert(quote(26) == 2.52);

	return 0;
}
