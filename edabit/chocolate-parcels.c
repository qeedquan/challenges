/*

Mubashir needs to assemble a parcel of ordered chocolates. He got two types of chocolates:

Small chocolates (2 grams each)
Big chocolates (5 grams each)
Create a function that takes three parameters: Number of small available chocolates nSmall, number of big chocolates available nBig and desired weight (in grams) of the final parcel order.

The function should return the required number of small chocolates to achieve the goal. The function should return -1 if the goal cannot be achieved by any possible combinations of small and big chocolates.

Examples
chocolatesParcel(4, 1, 13) ➞ 4
// 4 small chocolates = 8 grams
// 1 big chocolate = 5 grams
// 8 + 5 = 13 grams
// Required number of small chocolates = 4

chocolatesParcel(4, 1, 14) ➞ -1
// You can not make any combination to reach 14 grams.

chocolatesParcel(2, 1, 7) ➞ 1
// 1 big chocolate = 5 grams
// 1 small chocolates = 2 grams
// 5 + 2 = 7 grams
// Required number of small chocolates = 1

Notes
Maximize the use of big chocolates that are available to achieve the desired goal. And only then should you proceed to use the small chocolates.
You can't break chocolates into small pieces.

*/

#include <assert.h>

int
parcels(int nsmall, int nbig, int order)
{
	int s, b;

	for (b = nbig; b >= 0; b--) {
		s = order - (5 * b);
		if (s < 0 || (s & 1))
			continue;

		s /= 2;
		if (s <= nsmall)
			return s;
	}
	return -1;
}

int
main(void)
{
	assert(parcels(4, 1, 13) == 4);
	assert(parcels(4, 1, 14) == -1);
	assert(parcels(2, 1, 7) == 1);
	assert(parcels(0, 1, 5) == 0);
	assert(parcels(3, 1, 6) == 3);
	assert(parcels(3, 0, 7) == -1);
	assert(parcels(2, 1, 9) == 2);
	assert(parcels(58, 156, 283) == 4);
	assert(parcels(3, 1000, 5012) == -1);
	assert(parcels(1, 1, 1) == -1);
	assert(parcels(1, 1, 8) == -1);
	assert(parcels(4, 1, 12) == -1);
	assert(parcels(10, 400, 2004) == 2);

	return 0;
}
