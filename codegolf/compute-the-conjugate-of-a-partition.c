/*

We will think of a partition as a sequence of non-increasing integers.
For a given partition into n1,n2,…,nk with n1≥n2…nk−1≥nk=n we write it out with ni dots on row i.
So for 6,1,1 we would write six dots on the first row, one on the second and one on the third

Task
Given a partition, you should output its conjugate.
That is you should output how many dots there are in each column of the dot diagram.
For the input 6,1,1 the output should be 3,1,1,1,1,1.

Examples
5, 2, 1 gives output 3, 2, 1, 1, 1
4, 3, 1 gives output 3, 2, 2, 1
4, 2, 2 gives output 3, 3, 1, 1
3, 3, 2 gives output 3, 3, 2

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

size_t
conjugate(unsigned *a, size_t n, unsigned *r)
{
	size_t i, j, l;

	l = 0;
	for (i = 0; i < n; i++)
		l = max(l, a[i]);

	memset(r, 0, sizeof(*r) * l);
	for (i = 0; i < n; i++) {
		for (j = 0; j < a[i]; j++)
			r[j]++;
	}
	return l;
}

void
test(unsigned *a, size_t n, unsigned *r, size_t nr)
{
	unsigned p[128];
	size_t np;

	np = conjugate(a, n, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	unsigned a1[] = {5, 2, 1};
	unsigned r1[] = {3, 2, 1, 1, 1};

	unsigned a2[] = {4, 3, 1};
	unsigned r2[] = {3, 2, 2, 1};

	unsigned a3[] = {4, 2, 2};
	unsigned r3[] = {3, 3, 1, 1};

	unsigned a4[] = {3, 3, 2};
	unsigned r4[] = {3, 3, 2};

	test(a1, nelem(a1), r1, nelem(r1));
	test(a2, nelem(a2), r2, nelem(r2));
	test(a3, nelem(a3), r3, nelem(r3));
	test(a4, nelem(a4), r4, nelem(r4));

	return 0;
}
