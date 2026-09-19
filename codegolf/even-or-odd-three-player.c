/*

It's a three players game, play with one hand.

At same time, each player show his hand with 0 to 5 fingers extended.

If all player show same kind of (even or odd) number, there is no winner. But else, the player showing different kind the two other win.

 P l a y e r s
A      B      C       Winner

Even   Even   Even    No winner
Odd    Odd    Odd     No winner
Even   Odd    Odd     Player A
Odd    Even   Even    Player A
Even   Odd    Even    Player B
Odd    Even   Odd     Player B
Odd    Odd    Even    Player C
Even   Even   Odd     Player C
The requested tool could use arguments (3 arguments as numeric between 0 and 5) or STDIN (3 values by line, separated by spaces).

There is no need to check input: Irregular input could produce unexpected output.

Arguments or values on line is given from left to right, from player A to player C.

Output must only contain A, B or C (capitalized) or the string no one (in lower case, with a regular space).

Tool may work only once or as a filter on all input lines.

Shortest code win.

*/

#include <assert.h>
#include <string.h>

const char *
judge(int a, int b, int c)
{
	static const char *tab[] = {
	    [0] = "no one",
	    [7] = "no one",
	    [3] = "A",
	    [4] = "A",
	    [2] = "B",
	    [5] = "B",
	    [1] = "C",
	    [6] = "C",
	};

	int i;

	i = ((a & 1) << 2) | ((b & 1) << 1) | (c & 1);
	return tab[i];
}

void
test(int a, int b, int c, const char *r)
{
	assert(!strcmp(judge(a, b, c), r));
}

int
main(void)
{
	test(0, 0, 0, "no one");
	test(1, 1, 1, "no one");
	test(0, 1, 1, "A");
	test(1, 0, 0, "A");
	test(0, 1, 0, "B");
	test(1, 0, 1, "B");
	test(1, 1, 0, "C");
	test(0, 0, 1, "C");

	return 0;
}
