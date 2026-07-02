/*

This kata is based on Project Euler Problem 539

Object
Find the last number between 1 and n (inclusive) that survives the elimination process

How It Works
Start with the first number on the left then remove every other number moving right until you reach the the end, then from the numbers remaining start with the first number on the right and remove every other number moving left, repeat the process alternating between left and right until only one number remains which you return as the "last man standing"

Example
given an input of `9` our set of numbers is `1 2 3 4 5 6 7 8 9`

start by removing from the left    2   4   6   8
                                 1   3   5   7   9


then from the right                2       6
                                       4       8


then the left again                        6
                                   2


until we end with `6` as the last man standing
Note: due to the randomness of the tests it is possible that you will get unlucky and a few of the tests will be really large, so try submitting 2 or 3 times.

As always any feedback would be much appreciated

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A347325
int
lastman(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;

	n /= 2;
	return 2 * (n + 1 - lastman(n));
}

int
main()
{
	static const int tab[] = {
		1, 2, 2, 2, 2, 4, 4, 6, 6, 8, 8, 6, 6, 8, 8, 6, 6, 8, 8, 6, 6, 8, 8,
		14, 14, 16, 16, 14, 14, 16, 16, 22, 22, 24, 24, 22, 22, 24, 24, 30,
		30, 32, 32, 30, 30, 32, 32, 22, 22, 24, 24, 22, 22, 24, 24, 30, 30,
		32, 32, 30, 30, 32, 32, 22, 22, 24, 24, 22, 22, 24, 24
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(lastman(i + 1) == tab[i]);

	assert(lastman(9) == 6);
	assert(lastman(10) == 8);
	assert(lastman(100) == 54);
	assert(lastman(1000) == 510);

	return 0;
}
