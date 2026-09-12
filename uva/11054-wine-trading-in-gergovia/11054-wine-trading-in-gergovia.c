#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
trade(int *a, size_t n)
{
	size_t i;
	int c, r;

	c = r = 0;
	for (i = 0; i < n; i++) {
		c += a[i];
		r += abs(c);
	}
	return r;
}

int
main()
{
	int a1[] = { 5, -4, 1, -3, 1 };
	int a2[] = { -1000, -1000, -1000, 1000, 1000, 1000 };

	assert(trade(a1, nelem(a1)) == 9);
	assert(trade(a2, nelem(a2)) == 9000);

	return 0;
}
