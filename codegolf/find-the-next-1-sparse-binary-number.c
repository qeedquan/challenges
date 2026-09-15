/*

A positive integer N is K-sparse if there are at least K 0s between any two consecutive 1s in its binary representation.

So, the number 1010101 is 1-sparse whereas 101101 is not.

Your task is to find the next 1-sparse number for the given input number. For example, if the input is 12 (0b1100) output should be 16 (0b10000) and if the input is 18 (0b10010) output should be 20 (0b10100).

Smallest program or function (in bytes) wins! Standard loopholes disallowed.

*/

#include <assert.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
n1sbn(uvlong n)
{
	do {
		if (n == ULLONG_MAX)
			break;
		n++;
	} while (n & (n << 1));

	return n;
}

int
main(void)
{
	assert(n1sbn(12) == 16);
	assert(n1sbn(18) == 20);

	return 0;
}
