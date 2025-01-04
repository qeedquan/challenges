/*

Make a function "add" that will be able to sum elements of list continuously and return a new list of sums.

For example:

add [1,2,3,4,5] == [1, 3, 6, 10, 15], because it's calculated like
this : [1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4, 1 + 2 + 3 + 4 + 5]

If you want to learn more see https://en.wikipedia.org/wiki/Prefix_sum

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
prefixsum(int *a, size_t n, int *r)
{
	size_t i;

	if (n == 0)
		return;

	r[0] = a[0];
	for (i = 1; i < n; i++)
		r[i] += r[i - 1] + a[i];
}

void
test(int *a, size_t n, int *r)
{
	int p[16];

	prefixsum(a, n, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = {1, 2, 3, 4, 5};
	int r1[] = {1, 3, 6, 10, 15};

	test(a1, nelem(a1), r1);
	return 0;
}
