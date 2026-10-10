/*

Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.

If there aren't two consecutive 1's, return 0.

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
gap(unsigned long n)
{
	int c, f, m;

	for (c = f = m = 0; n; n >>= 1) {
		if (n & 1) {
			m = max(m, c);
			f = 1;
			c = 0;
		}
		if (f)
			c++;
	}
	return m;
}

int
main(void)
{
	assert(gap(22) == 2);
	assert(gap(5) == 2);
	assert(gap(6) == 1);
	assert(gap(8) == 0);
	assert(gap(0x80000000UL) == 0);
	assert(gap(0x80000001UL) == 31);
	assert(gap(0x8f000000UL) == 4);
	assert(gap(0x87000001UL) == 24);

	return 0;
}
