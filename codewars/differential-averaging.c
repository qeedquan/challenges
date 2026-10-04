/*

Say you have a ratings system. People can rate a page, and the average is displayed on the page for everyone to see.

One way of storing such a running average is to keep the the current average as well as the total rating that all users have submitted and with how many people rated it, so that the average can be calculated and updated when a new rating has been made.

There are a couple of minor problems with this: first, you're keeping 3 columns instead of 1, which isn't ideal. Second is, if you're not careful, the number could get too large and get less and less accurate as the data format tries to keep up.

So what you need to do is this: write a function that takes the current average, the current number of ratings (data points) made, and a new value to add to the average; then return the new value. That way, you only need 2 columns in your database, and the number will not get crazy large over time.

To be clear:

current = 0.5
points = 2
add = 1

--> 0.6666666666666666666666666666666666 // (2/3)
There are also plenty of examples in the example tests.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
next(double x, double p, double a)
{
	return ((x * p) + a) / (p + 1);
}

void
test(double x, double p, double a, double r)
{
	double v;

	v = next(x, p, a);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-6);
}

int
main()
{
	test(0.5, 2, 1, 2.0 / 3);

	test(0, 0, 1, 1);
	test(1, 1, 2, 1.5);
	test(1.5, 2, 3, 2);

	test(0, 0, 123, 123);
	test(123, 1, 456, 289.5);
	test(289.5, 2, 789, 456);

	return 0;
}
