/*

Task
You are a magician. You're going to perform a trick.

You have b black marbles and w white marbles in your magic hat, and an infinite supply of black and white marbles that you can pull out of nowhere.

You ask your audience to repeatedly remove a pair of marbles from your hat and, for each pair removed, you add one marble to the hat according to the following rule, until there is only 1 marble left.

If the marbles of the pair that is removed are of the same color, you add a white marble to the hat. Otherwise, if one is black and one is white, you add a black marble.

Given the initial number of black and white marbles in your hat, your trick is to predict the color of the last marble.

Note: A magician may confuse your eyes, but not your mind ;-)

Input/Output
[input] integer b
Initial number of black marbles in the hat.

1 <= b <= 10^9

[input] integer w
Initial number of white marbles in the hat.

1 <= w <= 10^9

[output] a string
"Black" or "White" if you can safely predict the color of the last marble. If not, return "Unsure".

*/

#include <assert.h>
#include <string.h>

const char *
notsorandom(int black, int)
{
	if (black & 1)
		return "Black";
	return "White";
}

int
main()
{
	assert(!strcmp(notsorandom(1, 1), "Black"));
	assert(!strcmp(notsorandom(2, 1), "White"));
	assert(!strcmp(notsorandom(1, 2), "Black"));
	assert(!strcmp(notsorandom(2, 2), "White"));
	assert(!strcmp(notsorandom(6, 9), "White"));
	assert(!strcmp(notsorandom(10000, 10000), "White"));
	assert(!strcmp(notsorandom(11111, 22222), "Black"));
	return 0;
}
