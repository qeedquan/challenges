/*

Write a program to solve the sliding window minimum problem using any of the methods possible.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// https://www.zrzahid.com/sliding-window-minmax/
int *
slwmin(int *a, size_t n, size_t w)
{
	int *l, *r, *p;
	size_t i, j;

	if (n == 0 || w > n)
		return NULL;

	l = calloc(n, sizeof(*l));
	r = calloc(n, sizeof(*r));
	p = calloc(n - w + 1, sizeof(*p));
	if (!l || !r || !p)
		goto error;

	l[0] = a[0];
	r[n - 1] = a[n - 1];

	for (i = 1; i < n; i++) {
		j = n - i - 1;
		l[i] = (i % w == 0) ? a[i] : min(l[i - 1], a[i]);
		r[j] = (j % w == 0) ? a[j] : min(r[j + 1], a[j]);
	}

	for (i = j = 0; i + w <= n; i++)
		p[j++] = min(r[i], l[i + w - 1]);

	if (0) {
	error:
		free(p);
		p = NULL;
	}

	free(l);
	free(r);
	return p;
}

void
test(int *a, size_t n, size_t w, int *r, size_t nr)
{
	int *p;

	p = slwmin(a, n, w);
	assert(p);
	assert(!memcmp(p, r, sizeof(*r) * nr));
	free(p);
}

int
main(void)
{
	int a1[] = {1, 2, -1, -3, 4, 2, 5, 3};
	int r1[] = {-1, -3, -3, -3, 2, 2};

	int a2[] = {10, 20, 30, 50, 10, 70, 30};
	int r2[] = {10, 20, 30, 10, 10, 30};

	test(a1, nelem(a1), 3, r1, nelem(r1));
	test(a2, nelem(a2), 1, a2, nelem(a2));
	test(a2, nelem(a2), 2, r2, nelem(r2));

	return 0;
}
