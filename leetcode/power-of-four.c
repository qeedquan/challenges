/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Follow up: Could you solve it without loops/recursion?

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

bool
ispow4(uint32_t n)
{
	return n && !(n & (n - 1)) && !(n & 0xAAAAAAAA);
}

int
main(void)
{
	uint32_t i, p;

	p = 1;
	for (i = 0; i < 10000000; i++) {
		if (ispow4(i)) {
			assert(i == p);
			p *= 4;
		}
	}
	return 0;
}
