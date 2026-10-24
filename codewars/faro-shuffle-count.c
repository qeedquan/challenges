/*

A faro shuffle of a deck of playing cards is a shuffle in which the deck is split exactly in half and then the cards in the two halves are perfectly interwoven, such that the original bottom card is still on the bottom and the original top card is still on top.

For example, faro shuffling the list

['ace', 'two', 'three', 'four', 'five', 'six']
gives

['ace', 'four', 'two', 'five', 'three', 'six' ]
If 8 perfect faro shuffles are performed on a deck of 52 playing cards, the deck is restored to its original order.

Write a function that takes an integer n and returns an integer representing the number of faro shuffles it takes to restore a deck of n cards to its original order.

Assume n is an even number between 2 and 2000.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A024222
int
farocount(int n)
{
	int p, s;

	if (n < 1)
		return 0;

	p = 1;
	s = 0;
	do {
		s += 1;
		p = (n * (p % 2) + p) / 2;
	} while (p > 1);

	return s;
}

int
main()
{
	static const int tab[] = {
		1, 2, 2, 4, 4, 3, 3, 6, 6, 10, 10, 12, 12, 4, 4, 8, 8, 18, 18, 6, 6,
		11, 11, 20, 20, 18, 18, 28, 28, 5, 5, 10, 10, 12, 12, 36, 36, 12, 12,
		20, 20, 14, 14, 12, 12, 23, 23, 21, 21, 8, 8, 52, 52, 20, 20, 18, 18,
		58, 58, 60, 60, 6, 6, 12, 12, 66, 66, 22, 22, 35, 35, 9, 9, 20, 20
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(farocount(i + 2) == tab[i]);

	assert(farocount(2) == 1);
	assert(farocount(52) == 8);
	assert(farocount(542) == 540);
	assert(farocount(1250) == 156);
	assert(farocount(1954) == 30);

	return 0;
}
