/*

The object of this puzzle is to take a deck of 52 cards and shuffle it so that each card is in a random position.

Given:
An array, deck, of 52 distinct integers representing the cards. When you start, deck contains exactly one of each card in some unknown order.
A function, int rand(min, max), that returns a random integer between ints min and max, inclusive. You can assume that this function is truly random.
A function, void swap(x, y) that swaps two cards in the deck. If you call swap(x, y), the cards at positions x and y will switch places.
When:
The program calls shuffle() (or shuffle(deck) or deck.shuffle() or however your implementation likes to run),
Then:
deck should contain exactly one of each card in perfectly random order.
The Catch:
You can't declare any variables. Call swap and rand as much as you like, but you can't declare any variables of your own. This includes for loop counters--even implicit ones like in a foreach.

Clarifications:
You can change minor details to suit your chosen language. For example, you can write swap to switch two integers by reference. Changes should be to make this work with your language, not to make the puzzle easier.
deck can be a global variable, or you can take it in as a parameter.
You can do anything you want to the contents of deck, but you can't change its length.
Your cards can be numbered 0-51, 1-52, or anything you like.
You can write this in any language, but no cheating with your language's built-in shuffle function.
Yes, you could write the same line 52 times. No one will be impressed.
Execution time doesn't matter, but true randomness does.
This isn't really code golf, but feel free to minimize/obfuscate your code.

Edit: Boilerplate code and visualizer
If you used .NET or JavaScript, here's some test code you may find useful:

JavaScript:
Quick-and-dirty JavaScript visualizer, with CoffeeScript source: https://gist.github.com/JustinMorgan/3989752bdfd579291cca
Runnable version (just paste in your shuffle() function): http://jsfiddle.net/4zxjmy42/
C#:
ASP.NET visualizer with C# codebehind: https://gist.github.com/JustinMorgan/4b630446a43f28eb5559
Stub with just the swap and rand utility methods: https://gist.github.com/JustinMorgan/3bb4e6b058d70cc07d41
This code sorts and shuffles the deck several thousand times and performs some basic sanity testing: For each shuffle, it verifies that there are exactly 52 cards in the deck with no repeats. Then the visualizer plots the frequency of each card ending up at each place in the deck, displaying a grayscale heat map.

The visualizer's output should look like snow with no apparent pattern. Obviously it can't prove true randomness, but it's a quick and easy way to spot-check. I recommend using it or something like it, because certain mistakes in the shuffling algorithm lead to very recognizable patterns in the output. Here's an example of the output from two implementations, one with a common flaw:

Visualizer output
https://i.sstatic.net/kHQdr.jpg

The flawed version does partially shuffle the deck, so might look fine if you examined the array by hand. The visualizer makes it easier to notice a pattern.

*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int deck[52];

void
reset()
{
	int i;

	for (i = 0; i < 52; i++)
		deck[i] = i;
}

void
swap(int a, int b)
{
	deck[a] = deck[b] ^ deck[a];
	deck[b] = deck[b] ^ deck[a];
	deck[a] = deck[b] ^ deck[a];
}

int
rng(int a, int b)
{
	return floor(drand48() * (1 + b - a)) + a;
}

/*

ported from @aaaaaaaaaaaa solution

I believe this is the intended form of solution,
I use the card in position 0 to keep track of progress, only shuffling the cards that have already been used as counter, this achieves the standard 52! permutations with a perfect equal distribution.
The procedure is complicated by XOR swap not allowing that an element is swapped by itself.

*/

void
shuffle()
{
	// sort 0 into element 0
	while (deck[0] != 0)
		swap(0, deck[0]);

	// run 51 times
	while (deck[0] < 51) {
		// sort element deck[0]+1 into position deck[0]+1
		while (deck[deck[0] + 1] != deck[0] + 1)
			swap(deck[deck[0] + 1], deck[0] + 1);

		// swap element deck[0]+1 into position 0, thus increasing the value of deck[0] by 1
		swap(0, deck[0] + 1);

		// swap the element at position deck[0] to a random position in the range 1 to deck[0]
		if (rng(0, deck[0] - 1))
			swap(deck[0], rng(1, deck[0] - 1));
	}

	// swap the element at position 0 to a random position
	if (rng(0, 51))
		swap(0, rng(1, 51));
}

void
print()
{
	int i;

	for (i = 0; i < 52; i++)
		printf("%d ", deck[i]);
	printf("\n");
}

int
main()
{
	int i;

	srand48(time(NULL));
	reset();
	for (i = 0; i < 100; i++) {
		shuffle();
		print();
	}

	return 0;
}
