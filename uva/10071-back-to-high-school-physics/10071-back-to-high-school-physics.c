#include <assert.h>

int
displacement(int v, int t)
{
	return 2 * v * t;
}

int
main(void)
{
	assert(displacement(0, 0) == 0);
	assert(displacement(5, 12) == 120);

	return 0;
}
