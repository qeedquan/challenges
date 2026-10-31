/*

You and a friend have decided to play a game to drill your statistical intuitions. The game works like this:

You have a bunch of red and blue marbles. To start the game you grab a handful of marbles of each color and put them into the bag, keeping track of how many of each color go in. You take turns reaching into the bag, guessing a color, and then pulling one marble out. You get a point if you guessed correctly. The trick is you only have three seconds to make your guess, so you have to think quickly.

You've decided to write a function, guessBlue() to help automatically calculate whether you should guess "blue" or "red". The function should take four arguments:

the number of blue marbles you put in the bag to start
the number of red marbles you put in the bag to start
the number of blue marbles pulled out so far (always lower than the starting number of blue marbles)
the number of red marbles pulled out so far (always lower than the starting number of red marbles)
guessBlue() should return the probability of drawing a blue marble, expressed as a float. For example, guessBlue(5, 5, 2, 3) should return 0.6.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
chance(int total_blue, int total_red, int drawn_blue, int drawn_red)
{
	double total_remaining, blue_remaining;

	total_remaining = total_blue + total_red - (drawn_blue + drawn_red);
	blue_remaining = total_blue - drawn_blue;
	return blue_remaining / total_remaining;
}

void
test(int total_blue, int total_red, int blue, int red, double expected)
{
	double probability;

	probability = chance(total_blue, total_red, blue, red);
	printf("%f\n", probability);
	assert(fabs(probability - expected) < 1e-8);
}

int
main()
{
	test(5, 5, 2, 3, 0.6);
	test(5, 7, 4, 3, 0.2);
	test(12, 18, 4, 6, 0.4);

	return 0;
}
