#include <assert.h>
#include <stdio.h>
#include <limits.h>

// implement addition using xor
unsigned
add1(unsigned x)
{
	unsigned y;

	if (x == UINT_MAX)
		return 0;

	for (y = 1;; y <<= 1) {
		x ^= y;
		if (x & y)
			break;
	}
	return x;
}

unsigned
addn(unsigned x, unsigned n)
{
	unsigned i;

	for (i = 0; i < n; i = add1(i))
		x = add1(x);
	return x;
}

int
main(void)
{
	assert(add1(UINT_MAX) == 0);
	assert(addn(20, 3) == 23);
	assert(addn(255, 2555) == 2810);

	return 0;
}
