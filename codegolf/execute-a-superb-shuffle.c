/*

For the purposes of this question, a deck of cards is formatted in this way:

[
  "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", 
  "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", 
  "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", 
  "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", 
  "J", "J"
]
Cards are always formatted as value, followed by suits. E.g. AS is the Ace of Spades. The two single J's are Jokers. We want to shuffle this deck of cards, but the shuffle must be Superb™.

A Superb Shuffle™ is one in which:

No two cards (except Jokers) of the same suit are adjacent.
No card (except Jokers) is adjacent to one of the same value.
No card (except Jokers) is adjacent to one of an adjacent value (one higher or one lower in this order, A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A. Notice that Ace can not be adjacent to either a 2 or a King).
The Jokers can be in any position.
The definition of a Superb Shuffle™ does not require the cards to be in a different order each time they are shuffled. Which isn't very superb, but it is Superb™.
Because that's Superb™.

An example might be:

[
  "AS", "5D", "9H", "KC", "2D", "6H", "10C", "QS", "3H", "7C", "9S", 
  "KD", "4C", "6S", "10D", "AC", "3S", "7D", "JH", "J", "4D", "8H", 
  "QC", "AD", "5H", "9C", "JS", "2H", "6C", "8S", "QD", "3C", "5S", 
  "9D", "KH", "2S", "6D", "10H", "J", "3D", "7H", "JC", "KS", "4H", 
  "8C", "10S", "AH", "5C", "7S", "JD", "2C", "4S", "8D", "QH"
]
The challenge:

Write some code to execute a superb shuffle
Use any language.
The input can be either:
a deck of cards as described above in the same order, as an array or other list structure.
No input (the code generates a deck of cards in that order)
The output must be a full deck of cards in a Superb Shuffle™ as described above.
Attempt to perform your Superb Shuffle™ in the smallest number of bytes.
A link to an online interpreter such as Try It Online is preferred, but optional.
Happy shuffling!

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef const char *Deck[54];

/*

@G B

Explanation:
I'm picking one card, then skipping over the next 16 and start from the first card when I reach the last card of the deck. 17 and 54 are mutually prime, so I'm sure to pick all cards.

The 17th position is guaranteed to be a different suit and the difference in value is at least 2: the 13th (or 15th) card has the same value and a different suit, so by skipping other 4 (or 2), the value is right.

*/

void
shuffle(Deck input, Deck output)
{
	size_t index;

	for (index = 0; index < 54; index++)
		output[index] = input[(index * 17) % 54];
}

void
print(Deck deck)
{
	size_t index;

	for (index = 0; index < 54; index++) {
		printf("%-4s", deck[index]);
		if ((index & 7) == 7)
			printf("\n");
	}
	printf("\n");
}

int
main()
{
	Deck deck = {
	    "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S",
	    "JS", "QS", "KS", "AD", "2D", "3D", "4D", "5D", "6D", "7D",
	    "8D", "9D", "10D", "JD", "QD", "KD", "AH", "2H", "3H", "4H",
	    "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AC",
	    "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC",
	    "QC", "KC", "J", "J",
	};

	Deck newdeck;

	shuffle(deck, newdeck);
	print(newdeck);

	return 0;
}

