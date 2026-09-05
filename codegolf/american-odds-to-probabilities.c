/*

American odds (aka moneyline odds) are numbers like +150 or -400 used to express how much a winning bet would pay out. Convert odds to a fair win probability like this:

Positive odds +n with n≥100 correspond to
p = 100 / (100+n), producing a probability with 0 < p <= 1/2.
Negative odds -n with n>100 correspond to
p = n / (100+n),
producing a probability with 1/2 < p < 1.

Note that in both formulas above, n is the absolute value of the input. Inputs with absolute value under 100 are invalid, and so is -100 (since +100 is used for p=1/2), so you don't need to handle these.

The input will be a whole number. If you take it as a string, expecting a leading + for positive values is optional.

Your output can be a decimal to some reasonable precision or a reduced fraction.

Test cases

+1500   0.0625
 +256   0.2808988764044944
 +100   0.5
 -200   0.6666666666666666
 -300   0.75

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double
odds(int n)
{
	int s;

	s = (n > 0);
	n = abs(n);

	if (n < 100)
		return -1;

	if (s)
		return 100.0 / (100 + n);

	return n / (100.0 + n);
}

void
test(int n, double r)
{
	double p;

	p = odds(n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-8);
}

int
main(void)
{
	test(1500, 0.0625);
	test(256, 0.2808988764044944);
	test(100, 0.5);
	test(-200, 0.6666666666666666);
	test(-300, 0.75);

	return 0;
}
