/*

You're in a competition with another guy. You take turns hammering the nail. Whoever hits the last blow wins. The last blow means that the nail will be completely hammered.

Your input is the length of the nail (0 < l < 100). You can hit with different strengths: 1, 2 or 3 units of nail length at a time. Your opponent is stronger than you, and his hitting strength can be 2, 3 or 4 units, but you have a friend in judging who has excluded all hopeless initial l values for you. You make the first strike.

Return the strength of your current strike (1, 2 or 3), depending on the remaining length of the nail.

The tests will invoke your and your opponent's solutions with the remaining length of the nail, as long as l > 0. Then, if l <= 0 after your hit, you win the contest and pass the kata.

*/

#include <assert.h>
#include <stdio.h>

// opponent will make sure we never return an invalid value and only valid ones (1, 2, 3)
unsigned
hit(unsigned l)
{
	return l % 5;
}

int
main()
{
	unsigned l;

	for (l = 0; l < 100; l++)
		printf("%u\n", hit(l));
	return 0;
}
