/*

Kata Task
Given a list of random integers, return the Three Amigos.

These are 3 numbers that live next to each other in the list, and who have the most in common with each other by these rules:

lowest statistical range
same parity
Notes
The list will contain at least 3 numbers
If there is more than one answer then return the first one found (reading the list left to right)
If there is no answer (e.g. no 3 adjacent numbers with same parity) then return an empty list.
Examples
ex1

Input = [1, 2, 34, 2, 1, 5, 3, 5, 7, 234, 2, 1]

Result = [5,3,5]

ex2

Input = [2, 4, 6, 8, 10, 2, 2, 2, 1, 1, 1, 5, 3]

Result = [2,2,2]

ex3

Input = [2, 4, 5, 3, 6, 3, 1, 56, 7, 6, 3, 12]

Result = []

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int *
threeamigos(int *a, size_t n, int r[3])
{
	int p0, p1, p2;
	int m0, m1;
	int d, m, f;
	size_t i;

	f = 0;
	m = INT_MAX;
	for (i = 2; i < n; i++) {
		p0 = a[i - 2] & 1;
		p1 = a[i - 1] & 1;
		p2 = a[i] & 1;
		if (p0 != p1 || p1 != p2)
			continue;

		m0 = min(min(a[i - 2], a[i - 1]), a[i]);
		m1 = max(max(a[i - 2], a[i - 1]), a[i]);
		d = m1 - m0;
		if (d < m) {
			r[0] = a[i - 2];
			r[1] = a[i - 1];
			r[2] = a[i];
			m = d;
			f = 1;
		}
	}
	return (f) ? r : NULL;
}

void
test(int *a, size_t n, int r[3])
{
	int x[3], *p;

	p = threeamigos(a, n, x);
	if (!r)
		assert(p == r);
	else
		assert(!memcmp(x, r, sizeof(x)));
}

int
main()
{
	int a1[] = { 1, 2, 34, 2, 1, 5, 3, 5, 7, 234, 2, 1 };
	int a2[] = { 2, 4, 6, 8, 10, 2, 2, 2, 1, 1, 1, 5, 3 };
	int a3[] = { 2, 4, 5, 3, 6, 3, 1, 56, 7, 6, 3, 12 };

	int r1[] = { 5, 3, 5 };
	int r2[] = { 2, 2, 2 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), NULL);

	return 0;
}
