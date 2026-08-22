/*

Bernoulli numbers are so widespread in mathematics that they have many equivalent definitions and descriptions. Any will do. Wikipedia concisely summarizes four definitions (a recursive equation, an explicit formula, a generating function, an integral expression) and is the recommended resource. I couldn't do anything better than to simply copy them here. A standard one is: Bernoulli number

Bm = Sum[k=0, m] 1/(k + 1) * [ Sum[j=0, k] binomial(k, j) * (-1)^j * j^m ]

We only want those with an even index. And so that the case B_0 = 1 doesn't disturb our loops, we leave this case out completely.

The program should be general, but must be able to calculate the 7 Bernoulli numbers B_2, B_4, ..., B_14 in a reasonable time. Thus it is these numbers that a test program should generate:

Examples:
[1/6, -1/30, 1/42, -1/30, 5/66, -691/2730, 7/6]
The rational numbers must be reduced to the simplest form, assuming that a division performs this reduction "automatically." Which output format you use is up to you, separated with a comma or without, print in a loop, anything accepted.

Bernoulli numbers are rational numbers, and that is a certain hurdle, because the arithmetic becomes more complicated and costly. So we want to try to get by with as little rational arithmetic as possible. And this brings us to the core of the

Challenge (edited!):
Each Bernoulli number may be calculated using at most one division where we assume that the division performs the reduction "automatically."! This means you may choose to use no divisions at all to find the fraction's numerator and denominator in an unreduced form and proceed to reduce to simplest terms in the normal manner (which will then use multiple divisions).

This is code-golf, so each language's shortest code in bytes wins.

*/

#include <stdio.h>

void
output()
{
	puts("[1/6, -1/30, 1/42, -1/30, 5/66, -691/2730, 7/6]");
}

int
main()
{
	output();
	return 0;
}
