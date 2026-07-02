#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
collect(int *c, size_t n)
{
	size_t i;
	int s, r;

	s = r = 0;
	for (i = 0; i < n; i++) {
		if (n - 1 == i || s + c[i] < c[i + 1]) {
			s += c[i];
			r += 1;
		}
	}
	return r;
}

int
main()
{
	int c1[] = { 1, 2, 4, 8, 16, 32 };
	int c2[] = { 1, 3, 6, 8, 15, 20 };

	assert(collect(c1, nelem(c1)) == 6);
	assert(collect(c2, nelem(c2)) == 4);

	return 0;
}
