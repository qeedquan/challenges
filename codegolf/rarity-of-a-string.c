/*

Input: A string
Output: The rarity of the string, as described below.
To find the rarity of a string, follow the steps below.

Start with 0.
Subtract 3 for each E, A, T, or O in the string.
Subtract 2 for each I, N, S, or H in the string.
Subtract 1 for each R, D, L, or C in the string.
Add 1 for each W, F, G, or Y in the string.
Add 2 for each K, V, B, or P in the string.
Add 3 for each J, Q, X, or Z in the string.

Test cases:

Input: "rarity"
Output: -9

Input: "aardvark"
Output: -8

Input: "quine"
Output: -4

Input: "wow"
Output: -1

Input: "why"
Output: 0

Input: "puppy"
Output: 7

Scoring:
This is code-golf. The shortest answer in bytes wins!

Clarifications:

The input only consists of lowercase letters.
The input is guaranteed to be non-empty.
For U and M, do nothing.

*/

#include <assert.h>
#include <ctype.h>

int
rarity(const char *s)
{
	static const char tab[256] = {
	    ['E'] = -3,
	    ['A'] = -3,
	    ['T'] = -3,
	    ['O'] = -3,
	    ['I'] = -2,
	    ['N'] = -2,
	    ['S'] = -2,
	    ['H'] = -2,
	    ['R'] = -1,
	    ['D'] = -1,
	    ['L'] = -1,
	    ['C'] = -1,
	    ['W'] = 1,
	    ['F'] = 1,
	    ['G'] = 1,
	    ['Y'] = 1,
	    ['K'] = 2,
	    ['V'] = 2,
	    ['B'] = 2,
	    ['P'] = 2,
	    ['J'] = 3,
	    ['Q'] = 3,
	    ['X'] = 3,
	    ['Z'] = 3,
	};

	int r;

	for (r = 0; *s; s++)
		r += tab[toupper(*s) & 0xff];
	return r;
}

int
main(void)
{
	assert(rarity("rarity") == -9);
	assert(rarity("aardvark") == -8);
	assert(rarity("quine") == -4);
	assert(rarity("wow") == -1);
	assert(rarity("why") == 0);
	assert(rarity("puppy") == 7);

	return 0;
}
