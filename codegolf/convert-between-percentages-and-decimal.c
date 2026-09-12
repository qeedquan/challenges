/*

I, uh....honestly can't believe we don't have this one yet.

Challenge
Write two functions or programs that:

Convert from decimal to percentage
Convert from percentage to decimal
You may also write a single program that does both of the above.

Format
Percentages must be taken and returned with a percent sign. (In many languages, this means they will be strings.) They may be integers or floating point numbers.

Decimals are just floating point numbers.

You do not need to handle rounding errors involving very large or very small floating point numbers.

In cases where the numbers are integers (such as 56.0) you may return 56, 56., or 56.0. (This is intended to make I/O more flexible.)

Test Cases
    0.0% <-> 0.0
  100.0% <-> 1.0
   56.0% <-> 0.56
  123.0% <-> 1.23
  -11.0% <-> -0.11
-214.91% <-> -2.1491

Scoring
This is code-golf, so the shortest answer in each language wins. If you write two separate programs, add their sizes for your score.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
per2dec(double x)
{
	return x / 100;
}

double
dec2per(double x)
{
	return x * 100;
}

void
test(double rp, double rd)
{
	static const double eps = 1e-8;
	double p, d;

	d = per2dec(rp);
	p = dec2per(d);
	printf("%f %f\n", p, d);
	assert(fabs(p - rp) < eps);
	assert(fabs(d - rd) < eps);
}

int
main()
{
	test(0, 0);
	test(100, 1.0);
	test(56, 0.56);
	test(123, 1.23);
	test(-11, -0.11);
	test(-214.91, -2.1491);

	return 0;
}
