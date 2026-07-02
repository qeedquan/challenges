/*

The ones_count function returns the number of 1 bits in the given integer.

std::size_t ones_count( unsigned int value );

Templated
template <typename T>
std::size_t ones_count( T value );

*/

#include <assert.h>
#include <limits.h>
#include <stdbit.h>

typedef unsigned int uint;

// https://stackoverflow.com/questions/109023/count-the-number-of-set-bits-in-a-32-bit-integer/109025#109025
uint
ones(uint n)
{
	n = n - ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
	return n;
}

int
main()
{
	uint i;

	for (i = 0;; i++) {
		assert(ones(i) == stdc_count_ones(i));
		if (i == UINT_MAX)
			break;
	}

	return 0;
}
