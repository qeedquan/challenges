#include <assert.h>
#include <math.h>

int
blindsort(int n)
{
	if (n < 1)
		return 0;

	return n - 1 + floor(log(n - 1) / log(2));
}

int
main()
{
	assert(blindsort(2) == 1);
	assert(blindsort(4) == 4);

	return 0;
}
