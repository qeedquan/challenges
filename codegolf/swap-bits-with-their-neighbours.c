/*

Task description
Given an integer, swap its (2k–1)-th and 2k-th least significant bits for all integers k > 0. This is sequence A057300 in the OEIS.

(The number is assumed to have “infinitely many” leading zeroes. In practice, this simply means prepending a single 0 bit to odd-length numbers.)

https://i.stack.imgur.com/j6sll.jpg

This is code-golf, so the shortest code (in bytes) wins.

Test cases
0 -> 0
1 -> 2
9 -> 6
85 -> 170
220 -> 236
1827 -> 2835
47525 -> 30298

*/

#include <assert.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A057300
uint64_t
bcs(uint64_t n)
{
	return ((n & 0x5555555555555555) << 1) | ((n & 0xaaaaaaaaaaaaaaaa) >> 1);
}

int
main(void)
{
	static const uint64_t tab[] = {0, 2, 1, 3, 8, 10, 9, 11, 4, 6, 5, 7, 12, 14, 13, 15, 32, 34, 33, 35, 40, 42, 41, 43, 36, 38, 37, 39, 44, 46, 45, 47, 16, 18, 17, 19, 24, 26, 25, 27, 20, 22, 21, 23, 28, 30, 29, 31, 48, 50, 49, 51, 56, 58, 57, 59, 52, 54, 53, 55, 60, 62, 61, 63, 128, 130, 129, 131, 136, 138};

	uint64_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(bcs(i) == tab[i]);

	assert(bcs(0) == 0);
	assert(bcs(1) == 2);
	assert(bcs(9) == 6);
	assert(bcs(85) == 170);
	assert(bcs(220) == 236);
	assert(bcs(1827) == 2835);
	assert(bcs(47525) == 30298);

	return 0;
}
