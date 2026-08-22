/*

Explanation
A perfect shuffle is where a deck of cards is split exactly in half and the cards from each pile are alternately interleaved. The original bottom cards and the original top card must be preserved after a perfect shuffle.

After 8 perfect shuffles, a standard 52 card deck returns to its original order.

Challenge
Write a program that displays the state of a deck of cards as it goes through 8 consecutive perfect shuffles. You may use any human-readable representation of a deck, provided that it displays the number and suit of each card in the deck in sequential order. It must display a representation of all of the cards, for all nine states.

This is code golf, so the shortest solution wins.

Example Output
Here is an example output produced by this example implementation in Javascript

AS,AC,AD,AH,2S,2C,2D,2H,3S,3C,3D,3H,4S,4C,4D,4H,5S,5C,5D,5H,6S,6C,6D,6H,7S,7C,7D,7H,8S,8C,8D,8H,9S,9C,9D,9H,10S,10C,10D,10H,JS,JC,JD,JH,QS,QC,QD,QH,KS,KC,KD,KH
AS,7D,AC,7H,AD,8S,AH,8C,2S,8D,2C,8H,2D,9S,2H,9C,3S,9D,3C,9H,3D,10S,3H,10C,4S,10D,4C,10H,4D,JS,4H,JC,5S,JD,5C,JH,5D,QS,5H,QC,6S,QD,6C,QH,6D,KS,6H,KC,7S,KD,7C,KH
AS,4C,7D,10H,AC,4D,7H,JS,AD,4H,8S,JC,AH,5S,8C,JD,2S,5C,8D,JH,2C,5D,8H,QS,2D,5H,9S,QC,2H,6S,9C,QD,3S,6C,9D,QH,3C,6D,9H,KS,3D,6H,10S,KC,3H,7S,10C,KD,4S,7C,10D,KH
AS,9S,4C,QC,7D,2H,10H,6S,AC,9C,4D,QD,7H,3S,JS,6C,AD,9D,4H,QH,8S,3C,JC,6D,AH,9H,5S,KS,8C,3D,JD,6H,2S,10S,5C,KC,8D,3H,JH,7S,2C,10C,5D,KD,8H,4S,QS,7C,2D,10D,5H,KH
AS,5S,9S,KS,4C,8C,QC,3D,7D,JD,2H,6H,10H,2S,6S,10S,AC,5C,9C,KC,4D,8D,QD,3H,7H,JH,3S,7S,JS,2C,6C,10C,AD,5D,9D,KD,4H,8H,QH,4S,8S,QS,3C,7C,JC,2D,6D,10D,AH,5H,9H,KH
AS,3S,5S,7S,9S,JS,KS,2C,4C,6C,8C,10C,QC,AD,3D,5D,7D,9D,JD,KD,2H,4H,6H,8H,10H,QH,2S,4S,6S,8S,10S,QS,AC,3C,5C,7C,9C,JC,KC,2D,4D,6D,8D,10D,QD,AH,3H,5H,7H,9H,JH,KH
AS,2S,3S,4S,5S,6S,7S,8S,9S,10S,JS,QS,KS,AC,2C,3C,4C,5C,6C,7C,8C,9C,10C,JC,QC,KC,AD,2D,3D,4D,5D,6D,7D,8D,9D,10D,JD,QD,KD,AH,2H,3H,4H,5H,6H,7H,8H,9H,10H,JH,QH,KH
AS,AD,2S,2D,3S,3D,4S,4D,5S,5D,6S,6D,7S,7D,8S,8D,9S,9D,10S,10D,JS,JD,QS,QD,KS,KD,AC,AH,2C,2H,3C,3H,4C,4H,5C,5H,6C,6H,7C,7H,8C,8H,9C,9H,10C,10H,JC,JH,QC,QH,KC,KH
AS,AC,AD,AH,2S,2C,2D,2H,3S,3C,3D,3H,4S,4C,4D,4H,5S,5C,5D,5H,6S,6C,6D,6H,7S,7C,7D,7H,8S,8C,8D,8H,9S,9C,9D,9H,10S,10C,10D,10H,JS,JC,JD,JH,QS,QC,QD,QH,KS,KC,KD,KH

var numbers = ["A", 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K"];
var suits = ["S", "C", "D", "H"];
var deck = [];
for(var i = 0; i < numbers.length; i++) {
    for(var j = 0; j < suits.length; j++) {
      deck.push(numbers[i] + suits[j]);
    }
}
document.writeln(deck);

var shuffle = function() {
    var newDeck = [];
    var midpoint = deck.length / 2;
    for(var i = 0; i < midpoint; i++) {
      newDeck.push(deck[i], deck[midpoint + i]);
    }
    document.writeln(deck = newDeck);
}
var i = 8;
while(i--) shuffle();

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

enum {
	CARDS = 52,
};

typedef char Deck[CARDS][4];

void
gendeck(Deck deck)
{
	static const char cards[][4] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	static const char suits[][4] = {"S", "C", "D", "H"};

	size_t ndeck;
	size_t i, j;

	ndeck = 0;
	for (i = 0; i < nelem(cards); i++) {
		for (j = 0; j < nelem(suits); j++)
			sprintf(deck[ndeck++], "%s%s", cards[i], suits[j]);
	}
}

void
shuffle(Deck deck)
{
	Deck newdeck;
	size_t ndeck;
	size_t mid;
	size_t i;

	mid = CARDS / 2;
	ndeck = 0;
	for (i = 0; i < mid; i++) {
		memcpy(newdeck[ndeck++], deck[i], sizeof(deck[i]));
		memcpy(newdeck[ndeck++], deck[mid + i], sizeof(deck[mid + i]));
	}
	memcpy(deck, newdeck, sizeof(newdeck));
}

void
output(Deck deck)
{
	size_t i;

	for (i = 0; i < CARDS; i++) {
		printf("%s", deck[i]);
		if (i + 1 < CARDS)
			printf(",");
	}
	printf("\n");
}

int
main(void)
{
	Deck deck0, deck;

	gendeck(deck0);
	output(deck0);
	memcpy(deck, deck0, sizeof(deck0));
	for (;;) {
		shuffle(deck);
		output(deck);
		if (!memcmp(deck, deck0, sizeof(deck0)))
			break;
	}

	return 0;
}
