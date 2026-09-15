#include <assert.h>

unsigned
f91(unsigned n)
{
	if (n <= 100)
		return 91;
	return n - 10;
}

int
main(void)
{
	assert(f91(500) == 490);
	assert(f91(91) == 91);

	return 0;
}
