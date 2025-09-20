/*

Number Pyramid
Image a number pyramid starts with 1, and the numbers increasing by 1.

For example, when the pyramid has 3 levels:

  1
 2 3
4 5 6
And the sum of three corners are:

1 + 4 + 6 = 11
Input:
You will be given a number n, which means how many levels the pyramid has.

0 <= n <= 5000

Output:
You need to return the sum of three corners of the pyramid.

When there is no level, return 0 as there is no corner.

When there is only one level, return 1 as it is the only corner.

Examples:

sum_corners(0) --> 0
sum_corners(1) --> 1
sum_corners(2) --> 6
sum_corners(3) --> 11

Golfing Message:
The length of your code should be less or equal to 35.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A160842
int
sumcorners(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	return (n * n) + 2;
}

int
main()
{
	static const int tab[] = {
		0, 1, 6, 11, 18, 27, 38, 51, 66, 83, 102, 123, 146, 171, 198, 227, 258,
		291, 326, 363, 402, 443, 486, 531, 578, 627, 678, 731, 786, 843, 902,
		963, 1026, 1091, 1158, 1227, 1298, 1371, 1446, 1523, 1602, 1683, 1766,
		1851, 1938, 2027, 2118, 2211, 2306, 2403, 2502
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(sumcorners(i) == tab[i]);

	return 0;
}
