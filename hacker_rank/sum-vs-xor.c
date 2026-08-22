/*

Given an integer n, find x each such that:
0 <= x <= n
n + x = n ^ x

*/

#include <assert.h>
#include <stdio.h>

unsigned
sumxor_slow(unsigned n)
{
	unsigned c, i;

	for (c = i = 0; i <= n; i++) {
		if ((n + i) == (n ^ i))
			c++;
	}
	return c;
}

unsigned
trailzero(unsigned n)
{
	unsigned c;

	for (c = 0; n != 0; n >>= 1) {
		if ((n & 1) == 0)
			c++;
	}
	return c;
}

/*

Addition is equal to xor when there is no carry; xor is addition without carry.
This gives the following constraint on the binary representation:

If bit in n -> 1, then x -> 0
If bit in n -> 0, then x -> 0/1

Find the number of possible x's by counting 0s in n before the MSB 1 is set.
Any bits after the MSB 1 will be the same in xor/sum form and then 2^p will give the number of combinations where p is the number.

*/

unsigned
sumxor(unsigned n)
{
	return 1u << trailzero(n);
}

int
main(void)
{
	unsigned i;

	for (i = 0; i < 0xffff; i++)
		assert(sumxor_slow(i) == sumxor(i));
	return 0;
}
