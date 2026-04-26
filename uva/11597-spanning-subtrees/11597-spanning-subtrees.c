#include <assert.h>

int
trees(int n)
{
	return n / 2;
}

int
main(void)
{
	assert(trees(4) == 2);
	return 0;
}
