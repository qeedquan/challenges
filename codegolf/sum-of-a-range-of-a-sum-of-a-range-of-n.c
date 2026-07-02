/*

In this challenge, your input is an integer value. Your task is to find the sum of the range of the sum of the range of n.

Examples:

Input -> Output
1     -> 1
2     -> 6
3     -> 21
4     -> 55
5     -> 120
6     -> 231
7     -> 406
8     -> 666
9     -> 1035
10    -> 1540

This challenge should be fairly simple to complete in most languages :)
Have fun!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A002817
uvlong
dbltri(uvlong n)
{
	return n * (n + 1) * ((n * n) + n + 2) / 8;
}

int
main(void)
{
	static const uvlong tab[] = {0, 1, 6, 21, 55, 120, 231, 406, 666, 1035, 1540, 2211, 3081, 4186, 5565, 7260, 9316, 11781, 14706, 18145, 22155, 26796, 32131, 38226, 45150, 52975, 61776, 71631, 82621, 94830, 108345, 123256, 139656, 157641, 177310, 198765, 222111, 247456, 274911, 304590};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(dbltri(i) == tab[i]);

	return 0;
}
