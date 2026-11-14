/*

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.

Calculate the number of perfect squares below a number n where n will be taken as an input

Examples:

There are 9 perfect squares below 100: 1, 4, 9, 16, 25, 36, 49, 64, 81

Constraints:  0<n<10^6

Since this is a golfing challenge, the entry with least amount of bytes will win.

Best of Luck!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A000196
int
count(int n)
{
	if (n < 1)
		return 0;
	return sqrt(n - 1);
}

int
main()
{
	static const int tab[] = {
		0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
		9, 9, 9, 9, 9, 9, 9, 9, 10, 10
	};

	size_t i;

	assert(count(100) == 9);

	for (i = 0; i < nelem(tab); i++)
		assert(count(i + 1) == tab[i]);

	return 0;
}
