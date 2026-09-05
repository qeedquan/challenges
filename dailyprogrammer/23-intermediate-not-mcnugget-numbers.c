/*

At McDonalds’ Restaurants, the Chicken McNugget meals are available in sizes of 6 McNuggets, 9 McNuggets, or 20 McNuggets.
A number is a McNugget number if it can be the sum of the number of McNuggets purchased in an order (before eating any of them).
Henri Picciotto devised the math of McNugget numbers in the 1980s while dining with his son at McDonald’s, working the problem out on a napkin.

Your task is to determine all numbers that are not McNugget numbers.

source: programmingpraxis.com

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A065003
bool
mcn(int n)
{
	if (n > 43)
		return true;

	for (; n >= 0; n -= 20) {
		if (!(n % 3) && n != 3)
			return true;
	}
	return false;
}

int
main()
{
	static const int tab[] = {
		1, 2, 3, 4, 5, 7, 8, 10, 11, 13, 14, 16,
		17, 19, 22, 23, 25, 28, 31, 34, 37, 43
	};

	int i, j, n;

	n = tab[nelem(tab) - 1];
	for (i = j = 0; i <= n; i++) {
		if (i == tab[j]) {
			assert(mcn(i) == false);
			j += 1;
		} else
			assert(mcn(i) == true);
	}

	return 0;
}
