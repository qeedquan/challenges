/*

Baccarat is a casino game where gamblers bet on whether one of two hands, the player or the banker, will have a sum closer to 9 (mod 10) or whether they will tie. It is played with four to eight standard decks of cards, without the jokers, shuffled together. Numbered cards count as their value, aces count as 1, and all face cards count as 10. A hand's total is the sum of the two or three cards within it, modulo ten. (So, a hand of [9 9 9] would have a total of 7, while a hand of [10 J Q] would have a total of 0.)

First the dealer deals two cards to each hand. Then play proceeds as follows:

If the player has a total less than or equal to 5, they hit (draw a third card). Otherwise, they stand.
If the player didn't draw a third card, the banker acts the same as the player: if the banker's total is less than or equal to 5, they hit. Otherwise, the banker stands.
If the player did draw a third card, the banker acts according to the following table, based on their total and the card the player drew:

https://i.stack.imgur.com/oJq5G.png

Your task is to write a program or function that implements that final step of the banker's logic in as few characters as possible.

You will be given two integers in the interval [0, 9] or [1, 10], whichever is more convenient for your language: the player's third card and the total of the banker's first two cards. If the entry in the above table says H, meaning that the banker should hit, output TRUE or equivalent. If the table says S, meaning that the banker should stand, output FALSE or equivalent.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
bankhit(unsigned b, unsigned p)
{
	static const int tab[10][10] = {
	    {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	    {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	    {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	    {'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'S', 'H'},
	    {'S', 'S', 'H', 'H', 'H', 'H', 'H', 'H', 'S', 'S'},
	    {'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'S', 'S'},
	    {'S', 'S', 'S', 'S', 'S', 'S', 'H', 'H', 'S', 'S'},
	    {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	    {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	    {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	};

	if (b >= nelem(tab) || p >= nelem(tab[b]))
		return -1;
	return tab[b][p];
}

int
main(void)
{
	unsigned b, p;

	for (b = 0; b <= 9; b++) {
		for (p = 0; p <= 9; p++)
			printf("%c ", bankhit(b, p));
		printf("\n");
	}

	return 0;
}
