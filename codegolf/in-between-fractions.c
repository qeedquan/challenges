/*

Given two positive integer fractions x and y such that x<y, give the fraction z with the smallest positive integer denominator such that it is between x and y.

For example x=2/5, y=4/5, the answer is 1/2.
Other fractions such as 3/5 are also in between the two, but 1/2
has a denominator of 2 which is smaller.

As input you will receive 4 positive integers, the numerators and the denominators of x and y, you may assume these fractions are fully reduced. You should output the numerator and the denominator of z.

If there are multiple valid numerators, you may output any or all of them.

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
2/5 4/5 -> 1/2
1/1 2/1 -> 3/2
3/5 1/1 -> 2/3
5/13 7/18 -> 12/31
12/31 7/18 -> 19/49

Sample implementation in Haskell

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int n, d;
} Fraction;

Fraction
between(Fraction a, Fraction b)
{
	int n, d;

	n = d = 0;
	while (b.n * d <= b.d * n) {
		d = d + 1;
		n = ((d * a.n) / a.d) + 1;
	}
	return (Fraction){n, d};
}

void
test(Fraction a, Fraction b, Fraction r)
{
	Fraction c;

	c = between(a, b);
	printf("%d/%d\n", c.n, c.d);
	assert(!memcmp(&c, &r, sizeof(c)));
}

int
main(void)
{
	Fraction a1 = {2, 5};
	Fraction b1 = {4, 5};
	Fraction r1 = {1, 2};

	Fraction a2 = {1, 1};
	Fraction b2 = {2, 1};
	Fraction r2 = {3, 2};

	Fraction a3 = {3, 5};
	Fraction b3 = {1, 1};
	Fraction r3 = {2, 3};

	Fraction a4 = {5, 13};
	Fraction b4 = {7, 18};
	Fraction r4 = {12, 31};

	Fraction a5 = {12, 31};
	Fraction b5 = {7, 18};
	Fraction r5 = {19, 49};

	test(a1, b1, r1);
	test(a2, b2, r2);
	test(a3, b3, r3);
	test(a4, b4, r4);
	test(a5, b5, r5);

	return 0;
}
