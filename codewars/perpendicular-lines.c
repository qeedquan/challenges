/*

You are given an input (n) which represents the amount of lines you are given, your job is to figure out what is the maximum amount of perpendicular lines you can make using these lines.

Note: A perpendicular line is one that forms a 90 degree angle

n will always be greater than or equal to 0

Examples with 3 and 4 lines
https://imgur.com/BpssDwz

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A002620
int
bisects(int n)
{
	return (n * n) / 4;
}

int
main()
{
	static const int tab[] = {
		0, 0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 30, 36, 42, 49, 56, 64,
		72, 81, 90, 100, 110, 121, 132, 144, 156, 169, 182, 196, 210,
		225, 240, 256, 272, 289, 306, 324, 342, 361, 380, 400, 420, 441,
		462, 484, 506, 529, 552, 576, 600, 625, 650, 676, 702, 729, 756,
		784, 812
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(bisects(i) == tab[i]);

	return 0;
}
