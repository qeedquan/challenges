/*

Consider the following numbers (where n! is factorial(n)):

u1 = (1 / 1!) * (1!)
u2 = (1 / 2!) * (1! + 2!)
u3 = (1 / 3!) * (1! + 2! + 3!)
...
un = (1 / n!) * (1! + 2! + 3! + ... + n!)
Which will win: 1 / n! or (1! + 2! + 3! + ... + n!)?

Are these numbers going to 0 because of 1/n! or to infinity due to the sum of factorials or to another number?

Task
Calculate (1 / n!) * (1! + 2! + 3! + ... + n!) for a given n, where n is an integer greater or equal to 1.

Your result should be within 10^-6 of the expected one.

Remark
Keep in mind that factorials grow rather rapidly, and you need to handle large inputs.

Hint
You could try to simplify the expression.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
go(int n)
{
	double s;
	int i;

	s = 1.0;
	for (i = 2; i <= n; i++)
		s = (s / i) + 1;
	return floor(s * 1e6) / 1e6;
}

void
test(int n, double r)
{
	double s;

	s = go(n);
	printf("%f\n", s);
	assert(fabs(s - r) < 1e-6);
}

int
main()
{
	test(5, 1.275);
	test(6, 1.2125);
	test(7, 1.173214);
	test(8, 1.146651);
	test(20, 1.052786);
	test(50, 1.020416);
	test(10110, 1.000098);
	return 0;
}
