/*

Inspired by Generate Keyboard Friendly Numbers.

Background
Many number pads have the following layout:

789

456

123

0

We define a number's neighborhood as the set of cells orthogonally adjacent to it on the numpad shown, including itself. For example, 2's neighborhood is {1,5,3,0,2} and 0's neighborhood is {1,2,0}. There is a list of each number's neighborhood below, above test cases.

We define a numpad friendly number as a positive integer where, when written in decimal without leading zeroes, each digit except for the first is in the neighborhood of the previous digit.

For example,

7856 is a numpad friendly number because 8 is in the neighborhood of 7, 5 is in the neighborhoood of 8, and 6 is in the neighborhood of 5.
1201 is a numpad friendly number because 2 is in the neighborhood of 1, 0 is in the neighborhood of 2, and 1 is in the neighborhood of 0.
82 is not a numpad friendly number because 2 is not in the neighborhood of 8.
802 is not a numpad friendly number because 0 is not in the neighborhood of 8 (neighborhoods don't wrap around).

Related OEIS Sequence. Note that this related sequence is distinct because it counts 0 as adjacent to 7 instead of 1 and 2.
https://oeis.org/A124097

Challenge
Given a positive integer n, return the n-th or the first n numpad friendly numbers, where the first is 1. You may use 0-based indexing, where the 0-th numpad friendly number would be 1.

Neighborhoods
Each digits's neighborhood is listed here:

0:{0,1,2}
1:{0,1,2,4}
2:{0,1,2,3,5}
3:{2,3,6}
4:{1,4,5,7}
5:{2,4,5,6,8}
6:{3,5,6,9}
7:{4,7,8}
8:{5,7,8,9}
9:{6,8,9}
Test Cases / Sequence
These are the first 100 terms

[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 20, 21, 22, 23, 25, 32, 33, 36, 41, 44, 45, 47, 52, 54, 55, 56, 58, 63, 65, 66, 69, 74, 77, 78, 85, 87, 88, 89, 96, 98, 99, 100, 101, 102, 110, 111, 112, 114, 120, 121, 122, 123, 125, 141, 144, 145, 147, 200, 201, 202, 210, 211, 212, 214, 220, 221, 222, 223, 225, 232, 233, 236, 252, 254, 255, 256, 258, 320, 321, 322, 323, 325, 332, 333, 336, 363, 365, 366, 369, 410, 411, 412, 414, 441, 444, 445, 447]

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
nf(unsigned n)
{
	static const unsigned tab[] = {0x7, 0x17, 0x2f, 0x4c, 0xb2, 0x174, 0x268, 0x190, 0x3a0, 0x340};

	unsigned b, v;

	if (n == 0)
		return false;

	for (; n > 10; n /= 10) {
		v = tab[n % 10];
		b = (n / 10) % 10;
		if (!(v & (1 << b)))
			return false;
	}
	return true;
}

int
main(void)
{
	static const unsigned tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 20, 21, 22, 23, 25, 32, 33, 36, 41, 44, 45, 47, 52, 54, 55, 56, 58, 63, 65, 66, 69, 74, 77, 78, 85, 87, 88, 89, 96, 98, 99, 100, 101, 102, 110, 111, 112, 114, 120, 121, 122, 123, 125, 141, 144, 145, 147, 200, 201, 202, 210, 211, 212, 214, 220, 221, 222, 223, 225, 232, 233, 236, 252, 254, 255, 256, 258, 320, 321, 322, 323, 325, 332, 333, 336, 363, 365, 366, 369, 410, 411, 412, 414, 441, 444, 445, 447};

	unsigned i, j;

	for (i = j = 0; i < nelem(tab); j++) {
		if (nf(j))
			assert(j == tab[i++]);
	}
	return 0;
}
