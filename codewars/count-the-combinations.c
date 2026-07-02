/*

Consider a sequence of integers xs, and a target integer n. Your task is to write a function which counts how many combinations of indexes of xs meet two rules:

The size of the combination must be 1 less than the size of xs
The sum of elements corresponding to the indexes must equal n
For example:

xs = [5, 0, 0, 2], n = 7
All combinations of indexes (of size 3)
{0, 1, 2} -> 5 + 0 + 0 = 5
{0, 1, 3} -> 5 + 0 + 2 = 7
{0, 2, 3} -> 5 + 0 + 2 = 7
{1, 2, 3} -> 0 + 0 + 2 = 2
Only 2 combinations match the target -> Answer = 2

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
combos(int *a, size_t n, int v)
{
	size_t i;
	int c, s;

	c = s = 0;
	for (i = 0; i < n; i++)
		s += a[i];

	for (i = 0; i < n; i++) {
		if (s - a[i] == v)
			c++;
	}
	return c;
}

int
main()
{
	int a1[] = { 2, 0, 0, 0, 1 };
	int a2[] = { 0, 0, 0, 0, 0 };
	int a3[] = { 5, 0, 0, 2 };
	int a4[] = { 0, 0, 0, 0, 1 };

	assert(combos(a1, nelem(a1), 2) == 1);
	assert(combos(a1, nelem(a1), 1) == 1);
	assert(combos(a1, nelem(a1), 3) == 3);
	assert(combos(a2, nelem(a2), 0) == 5);
	assert(combos(a3, nelem(a3), 7) == 2);
	assert(combos(a4, nelem(a4), 1) == 4);
	assert(combos(a4, nelem(a4), 2) == 0);

	return 0;
}
