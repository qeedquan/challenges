/*

The partial sums of a list of integers [a1, a2, a3, ..., an] are

s1 = a1
s2 = a1 + a2
s3 = a1 + a2 + a3
...
sn = a1 + a2 + ... + an

We can then take the list of partial sums [s1, s2, s3, ..., sn] and compute its partial sums again to produce a new list, and so on.

Related: Iterated forward differences

Input:

A non-empty list of integers
A positive number of iterations,
Output: Print or return the list of integers that results from taking the partial sums that many times.

Fewest bytes wins. Built-ins are OK even if they outright solve the problem.

Test cases:

f([-3, 4, 7, -1, 15], 1) == [-3, 1, 8, 7, 22]
f([-3, 4, 7, -1, 15], 3) == [-3, -5, 1, 14, 49]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
partialsum(int *a, size_t n, int m)
{
	int i;
	size_t j;

	for (i = 0; i < m; i++) {
		for (j = 1; j < n; j++)
			a[j] += a[j - 1];
	}
}

void
test(int *a, size_t n, int m, int *r)
{
	partialsum(a, n, m);
	print(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {-3, 4, 7, -1, 15};
	int r1[] = {-3, 1, 8, 7, 22};

	int a2[] = {-3, 4, 7, -1, 15};
	int r2[] = {-3, -5, 1, 14, 49};

	test(a1, nelem(a1), 1, r1);
	test(a2, nelem(a2), 3, r2);

	return 0;
}
