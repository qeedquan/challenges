/*

Replace the elements of the array according to the assignment.

Input
The input file contains first the number N (1≤N≤100), followed by N numbers from 1 to 100 — the array elements Ai.
Then, two numbers q and w (from 1 to N, not necessarily different) are given.

You must make all elements equal to Aq become equal to Aw.
First read all the data, then make the required changes, and only after that output the result (do not perform transformations during output).
Try to avoid using additional arrays.

Output
Output N numbers: the elements of array Ai after the transformation.

Examples
Input #1
5
1 4 2 2 5
3 2

Answer #1
1 4 4 4 5

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(int *a, size_t n, size_t n0, size_t n1)
{
	size_t i;
	int x, y;

	x = a[n0 - 1];
	y = a[n1 - 1];
	for (i = 0; i < n; i++) {
		if (a[i] == x)
			a[i] = y;
	}
}

void
test(int *a, size_t n, size_t n0, size_t n1, int *r)
{
	solve(a, n, n0, n1);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = { 1, 4, 2, 2, 5 };
	int r1[] = { 1, 4, 4, 4, 5 };

	test(a1, nelem(a1), 3, 2, r1);

	return 0;
}
