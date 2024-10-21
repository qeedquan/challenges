/*

Task
Suppose a family has 2 children, one of which is a boy. What is the probability that both children are boys?

*/

#include <stdio.h>

/*

The probability space for 2 children gender is:

BB, BG, GB, GG

We are given the information that one of them is a boy so the probability space becomes:

BB, BG, GB

Out of that only BB is a both boys so the solution is 1/3

More generally we can use Baye's rule for conditional probability

P(A|B)= P(B|A)*P(A)/P(B)

Probability of two boys given one of them is a boy:
P(2B | B) = P(B|2B)*P(2B)/P(B)

P(B)    - (3/4) BB, BG, GB
P(B|2B) - (1)   BB
P(2B)   - (1/4) BB

(1 * 1/4) / (3/4) = 1/3

*/

double
solve(void)
{
	int i, j, x, y;

	x = y = 0;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			if (i == 0 && j == 0)
				x += 1;
			if (i == 0 || j == 0)
				y += 1;
		}
	}
	return (x * 1.0) / y;
}

int
main(void)
{
	printf("%f\n", solve());
	return 0;
}
