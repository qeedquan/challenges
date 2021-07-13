/*

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

unsigned
hindex(unsigned *a, size_t n)
{
	unsigned h, m;
	size_t i;

	qsort(a, n, sizeof(*a), cmp);

	m = 0;
	for (i = 0; i < n; i++) {
		h = min(a[i], n - i);
		if (h > m)
			m = h;
		if (n - i < a[i])
			break;
	}
	return m;
}

int
main(void)
{
	unsigned a[] = {3, 0, 6, 1, 5};
	unsigned b[] = {0};
	unsigned c[] = {1};
	unsigned d[] = {1, 2, 2};
	unsigned e[] = {2, 2};
	printf("%u\n", hindex(a, nelem(a)));
	printf("%u\n", hindex(b, nelem(b)));
	printf("%u\n", hindex(c, nelem(c)));
	printf("%u\n", hindex(d, nelem(d)));
	printf("%u\n", hindex(e, nelem(e)));
	return 0;
}
