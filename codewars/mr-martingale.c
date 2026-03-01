/*

You're in the casino, playing Roulette, going for the "1-18" bets only and desperate to beat the house and so you want to test how effective the Martingale strategy (https://en.wikipedia.org/wiki/Martingale_(betting_system)) is.

You will be given a starting cash balance and an array of binary digits to represent a win (1) or a loss (0). Return your balance after playing all rounds.

The Martingale strategy

You start with a stake of 100 dollars. If you lose a round, you lose the stake placed on that round and you double the stake for your next bet. When you win, you win 100% of the stake and revert back to staking 100 dollars on your next bet.

Example
martingale(1000, [1, 1, 0, 0, 1]) === 1300
Explanation:

you win your 1st round: gain $100, balance = 1100
you win the 2nd round: gain $100, balance = 1200
you lose the 3rd round: lose $100 dollars, balance = 1100
double stake for 4th round and lose: staked $200, lose $200, balance = 900
double stake for 5th round and win: staked $400, won $400, balance = 1300

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
martingale(int bank, int *outcomes, size_t noutcomes)
{
	size_t i;
	int stake;

	stake = 100;
	for (i = 0; i < noutcomes; i++) {
		if (outcomes[i]) {
			bank += stake;
			stake = 100;
		} else {
			bank -= stake;
			stake *= 2;
		}
	}
	return bank;
}

int
main()
{
	int outcomes_1[] = {1, 1, 0, 0, 1};
	int outcomes_2[] = {0, 0, 0, 0, 1, 0, 0};
	int outcomes_3[] = {1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0};
	int outcomes_4[] = {1, 1, 0, 1, 0, 1, 0};

	assert(martingale(500, NULL, 0) == 500);
	assert(martingale(1000, outcomes_1, nelem(outcomes_1)) == 1300);
	assert(martingale(0, outcomes_2, nelem(outcomes_2)) == -200);
	assert(martingale(5100, outcomes_3, nelem(outcomes_3)) == 5600);
	assert(martingale(-500, outcomes_4, nelem(outcomes_4)) == -200);

	return 0;
}
