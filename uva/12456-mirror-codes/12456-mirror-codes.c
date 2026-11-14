#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

vlong
solve(vlong *a, size_t n)
{
	vlong x, y;
	size_t i, j;

	if (n == 0)
		return 0;

	x = y = 1;
	for (i = 0; i < n; i++)
		y *= a[i];
	for (i = 0, j = n - 1; i <= j; i++, j--)
		x *= min(a[i], a[j]);
	return y - x;
}

int
main()
{
	vlong a1[] = { 2, 2 };
	vlong a2[] = { 2, 2, 2, 2 };
	vlong a3[] = { 2, 2, 2, 2, 2, 2 };

	assert(solve(a1, nelem(a1)) == 2);
	assert(solve(a2, nelem(a2)) == 12);
	assert(solve(a3, nelem(a3)) == 56);

	return 0;
}
