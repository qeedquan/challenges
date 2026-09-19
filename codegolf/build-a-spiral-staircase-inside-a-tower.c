/*

These are two versions of the same tower with 5 floors

__F_     __⚑_
|D/|     |█/|
|\_|     |\_|
|_/|     |_/|
|\D|     |\█|
|_/|     |_/|
A spiral staircase is built inside the tower. Each floor is made of three elements:

walls on each side (|)
a flat surface (_) OR a door (D or █)
stairs that lead to the next floor (/ or \)
Each floor must have 1 flat surface or door, 1 staircase, and must be enclosed within 2 walls.

A door is always present on the left at the bottom of the tower (|█/| or |D/|) and the staircase should lead to the flag at the top of the tower.

The top of the tower is a flat rooftop with a tiny flag (__⚑_ or __F_). The flag is aligned with the direction of the staircase on the last floor.

__F_     __⚑_
|_/|     |_/|

_F__     _⚑__
|\_|     |\_|

Stairs always lead to a flat surface or a door, so the following floors combinations are not allowed:

|_/|     |\_|
|_/|     |\_|
Lastly, being a spiral staircase, stairs must change direction each floor. The following combinations are not allowed:

|/_|     |_\|
|_/|     |\_|

Task
Your task is to build and print a tower based on an input representing the height of each floor, such as 2 1 2 1 1. The minimum height for a floor is 1.

Each number in the input defines the height of the current floor and ultimately how tall the tower is.

Doors should only appear if specified in in the input. Additional doors are not allowed.

A few examples:

Input: 3 2 4 1 2
_⚑__   _F__
|\_|   |\_|
|█/|   |D/|
|\█|   |\D|
|_/|   |_/|         Input: 2 1 2 1 1
|\_|   |\_|         __⚑_   __F_
|_/|   |_/|         |█/|   |D/|
|\█|   |\D|         |\█|   |\D|
|_/|   |_/|         |_/|   |_/|
|\█|   |\D|         |\█|   |\D|
|_/|   |_/|         |█/|   |D/|        Input: 1
|\_|   |\_|         |\_|   |\_|         __⚑_   __F_
|█/|   |D/|         |█/|   |D/|         |█/|   |D/|

Rules
No need for input checking
The input must contain at least 1 value/height
The input can be a sequence of characters separated by a whitespace   or an array/list/stream of integers compatible with the language
Only chose one set of characters, don't print both versions of the tower
No other characters can be used as alternatives
This is a code-golf challenge, shortest solution in bytes wins

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
staircase(int *h, size_t n)
{
	static const char *sym[4] = {
		"\\_",
		"\\D",
		"_/",
		"D/",
	};

	size_t i, p;

	for (i = p = 0; i < n; i++)
		p ^= h[i] & 1;

	if (p)
		puts("__F_");
	else
		puts("_F__");

	for (; n > 0; n--) {
		for (; h[n - 1]-- > 0; p ^= 1) {
			i = !h[n - 1] + (2 * p);
			printf("|%s|\n", sym[i]);
		}
	}
	printf("\n");
}

int
main()
{
	int h1[] = { 3, 2, 4, 1, 2 };
	int h2[] = { 2, 1, 2, 1, 1 };
	int h3[] = { 1 };

	staircase(h1, nelem(h1));
	staircase(h2, nelem(h2));
	staircase(h3, nelem(h3));

	return 0;
}
