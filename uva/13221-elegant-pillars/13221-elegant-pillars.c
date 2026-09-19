#include <assert.h>

typedef long long vlong;

vlong
pillars(vlong n)
{
	return ((n + 1) * (n + 1) / 2) - 1;
}

int
main()
{
	assert(pillars(1) == 1);
	assert(pillars(2) == 3);

	return 0;
}
