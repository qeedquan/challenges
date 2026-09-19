/*

Write a function that calculates your score for an expedition in the card game "Lost Cities". The score depends on the values of the expedition cards you've played (received as an array of integers), as well as the number of handshake cards played. The scoring rules are as follows:

A penalty of -20 is applied right at the beginning if any kind of card will be played during the game. Then, the total value of the expedition cards is added and the final score is finally obtained by multiplying by a value depending on the number of handshake cards used, in the following manner:

1 handshake card = score * 2
2 handshake cards = score * 3
3 handshake cards = score * 4

Example:

expedition cards: [2, 4, 6, 7, 8]
2 handshake cards played

=> Expected score: 21

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
score(int *cards, size_t ncards, int wager)
{
	size_t i;
	int total;

	if (ncards == 0 || wager < 1)
		return 0;

	total = -20;
	for (i = 0; i < ncards; i++)
		total += cards[i];
	return total * (wager + 1);
}

int
main()
{
	int cards1[] = { 2, 4, 6, 7, 8 };

	assert(score(cards1, nelem(cards1), 2) == 21);

	return 0;
}
