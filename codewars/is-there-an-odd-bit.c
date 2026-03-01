/*

Return 1 when any odd bit of x equals 1; 0 otherwise.

Assume that:

x is an unsigned, 32-bit integer;
the bits are zero-indexed (the least significant bit is position 0)

Examples
  2  -->  1 (true) because at least one odd bit is 1 (2 = 0b10)
  5  -->  0 (false) because none of the odd bits are 1 (5 = 0b101)
170  -->  1 (true) because all of the odd bits are 1 (170 = 0b10101010)

*/

#include <assert.h>
#include <stdint.h>

int
oddbit(uint32_t x)
{
	return !!(x & 0xaaaaaaaa);
}

int
main()
{
	assert(oddbit(2863311530) == 1);
	assert(oddbit(128) == 1);
	assert(oddbit(131) == 1);
	assert(oddbit(2) == 1);
	assert(oddbit(24082) == 1);
	assert(oddbit(0) == 0);
	assert(oddbit(85) == 0);
	assert(oddbit(1024) == 0);
	assert(oddbit(1) == 0);
	assert(oddbit(1365) == 0);
	assert(oddbit(170) == 1);
	assert(oddbit(5) == 0);

	return 0;
}
