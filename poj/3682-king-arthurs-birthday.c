/*

Description

King Arthur is an narcissist who intends to spare no coins to celebrate his coming K-th birthday. The luxurious celebration will start on his birthday and King Arthur decides to let fate tell when to stop it. Every day he will toss a coin which has probability p that it comes up heads and 1-p up tails. The celebration will be on going until the coin has come up heads for K times. Moreover, the king also decides to spend 1 thousand coins on the first day's celebration, 3 thousand coins on the second day's, 5 thousand coins on the third day's ... The cost of next day will always be 2 thousand coins more than the previous one's. Can you tell the minister how many days the celebration is expected to last and how many coins the celebration is expected to cost?

Input

The input consists of several test cases.
For every case, there is a line with an integer K ( 0 < K ≤ 1000 ) and a real number p (0.1 ≤ p ≤ 1).
Input ends with a single zero.

Output

For each case, print two number -- the expected number of days and the expected number of coins (in thousand), with the fraction rounded to 3 decimal places.

Sample Input

1 1
1 0.5
0

Sample Output

1.000 1.000
2.000 6.000

Source

POJ Founder Monthly Contest – 2008.08.31, Soduku@POJ

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
dayncoins(int k, double p, double *d, double *c)
{
	*d = k / p;
	*c = k * (k + 1) / (p * p) - *d;
}

void
test(int k, double p, double rd, double rc)
{
	static const double eps = 1e-3;

	double d, c;

	dayncoins(k, p, &d, &c);
	printf("%f %f\n", d, c);
	assert(fabs(d - rd) < eps);
	assert(fabs(c - rc) < eps);
}

int
main(void)
{
	test(1, 1, 1, 1);
	test(1, 0.5, 2, 6);

	return 0;
}
