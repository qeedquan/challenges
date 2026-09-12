/*

Introduction
Adam (A) and Bubbler (B) are playing coin toss, where the one who wins 5 times first would win the prize of $32. If the game is aborted when the scores are A:B = 4:3, how should they distribute the prize? Assume the coin toss is fair, so the winning chance of either player is 1/2 for each game.

The answer is:

Adam should take $24 and Bubbler should take $8. Possible cases are as follows:

A wins (score 5:3, chance 1/2): A wins the prize
B wins (score 4:4) then A wins (score 5:4, chance 1/4): A wins the prize
B wins (score 4:4) then B wins (score 4:5, chance 1/4): B wins the prize
Therefore, the chance of A winning is 3/4 and that of B is 1/4.

Challenge
In order to do the fair splitting of prizes, we should compute the chance of winning the prize for each player. Given the following information,

X, how many times a player should win coin toss to win the prize
Wa, how many times player A has already won
Wb, how many times player B has already won
compute the chance of player A winning the prize.

Input and output
You can assume the three input numbers X, Wa, Wb satisfy the following:

All numbers are non-negative integers.
X > max(Wa, Wb), i.e. the game hasn't finished already.
You can choose to output a fraction or a floating-point number.

Scoring and winning criterion
Standard code-golf rules apply. Shortest code in bytes wins.

Test cases
X Wa Wb => Expected output
--------------------------
5  4  3 =>  3/4  = 0.75
5  3  4 =>  1/4  = 0.25
1  0  0 =>  1/2  = 0.5
4  3  1 =>  7/8  = 0.875
4  2  1 => 11/16 = 0.6875
6  4  2 => 13/16 = 0.8125

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

@Giuseppe
R: function(X,A,B) pbeta(.5,X-A,X-B)

The closed formula from this answer suggested a natural probability distribution to use -- this is a Negative Binomial with X-Wb-1 failures and X-Wa successes, i.e.,
the probability that there are X-Wa "successes" before there are X-Wb "failures".

Further identities reduce the CDF of the negative binomial to the CDF of a beta distribution or in terms of the (regularized) incomplete beta function.

@Greg Martin
https://i.stack.imgur.com/b3AiL.png

Ported from @Chas Brown solution

*/

double
chance(int n, int wa, int wb)
{
	if (wa == n)
		return 1;
	if (wa >= n || wb >= n)
		return 0;
	return (chance(n, wa + 1, wb) + chance(n, wa, wb + 1)) / 2.0;
}

void
test(int n, int wa, int wb, double r)
{
	double p;

	p = chance(n, wa, wb);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-10);
}

int
main(void)
{
	test(5, 4, 3, 3.0 / 4);
	test(5, 3, 4, 1.0 / 4);
	test(1, 0, 0, 1.0 / 2);
	test(4, 3, 1, 7.0 / 8);
	test(4, 2, 1, 11.0 / 16);
	test(6, 4, 2, 13.0 / 16);

	return 0;
}
