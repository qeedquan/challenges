/*

Alright, my second attempt at a code golf, let's see how this goes.

Pretend you have a 3x3 grid of digits, from 0 to 8:

 0 | 1 | 2
---+---+---
 3 | 4 | 5
---+---+---
 6 | 7 | 8
Return the neighbors the input has as indexes of the array.

Rules:

It's code golf, so shortest answer wins.
The pretend array's index can start at 0 or 1. (all examples use 0 though)
The submission can be just a procedure/function/method, but an example would be nice
The returned value can be in any order (if the input is 0 you could output either 13 or 31)
If you want, the output can be a list of numbers, e.g. [0,4,6] instead of 046
Diagonals don't count, as shown by the examples.
Examples:

0 -> 13
3 -> 046
4 -> 1357

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
index(unsigned n)
{
	static const char *tab[] = {"13", "024", "15", "046", "1357", "248", "37", "468", "57"};

	if (n >= nelem(tab))
		return NULL;
	return tab[n];
}

int
main(void)
{
	assert(!strcmp(index(0), "13"));
	assert(!strcmp(index(3), "046"));
	assert(!strcmp(index(4), "1357"));

	return 0;
}
