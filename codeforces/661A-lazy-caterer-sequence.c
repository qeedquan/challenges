/*

Lazy caterer sequence is defined as the maximum number of pieces formed when slicing a convex pancake with n cuts (each cut is a straight line). The formula is Cn = n·(n + 1) / 2 + 1. You are given n; calculate n-th element of the sequence.

Input
The only line of the input contains an integer n (0 ≤ n ≤ 100).

Output
Output the n-th element of lazy caterer sequence.

Examples
input
2
output
4
input
5
output
16

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://scipython.com/book2/chapter-2-the-core-python-language-i/examples/the-lazy-caterers-sequence/
// https://oeis.org/A000124
int
caterer(int n)
{
	return (n * (n + 1) / 2) + 1;
}

int
catererrec(int n)
{
	if (n < 0)
		return 0;
	if (n < 1)
		return 1;
	return catererrec(n - 1) + n;
}

int
main(void)
{
	static const int tab[] = {1, 2, 4, 7, 11, 16, 22, 29, 37, 46, 56, 67, 79, 92, 106, 121, 137, 154, 172, 191, 211, 232, 254, 277, 301, 326, 352, 379, 407, 436, 466, 497, 529, 562, 596, 631, 667, 704, 742, 781, 821, 862, 904, 947, 991, 1036, 1082, 1129, 1177, 1226, 1276, 1327, 1379};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		assert(caterer(i) == tab[i]);
		assert(catererrec(i) == tab[i]);
	}

	return 0;
}
