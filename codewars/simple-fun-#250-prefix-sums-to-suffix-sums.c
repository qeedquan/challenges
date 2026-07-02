/*

Task
Given the prefix sums of some array A, return suffix sums for the same array.

Array of prefix sums is defined as:

B[0] = A[0]
B[1] = A[0] + A[1]
B[2] = A[0] + A[1] + A[2]
...
B[n - 1] = A[0] + A[1] + ... + A[n - 1]

Array of suffix sums is defined as:

B[0] = A[0] + A[1] + A[2] + ... + A[n - 1]
B[1] =        A[1] + A[2] + ... + A[n - 1]
...
B[n - 2] =             A[n - 2] + A[n - 1]
B[n - 1] =                        A[n - 1]

Input/Output
[input] integer array prefixSums

prefix sums of the orginal array.

1 ≤ prefixSums.length ≤ 10^4,

-10^5 ≤ prefixSums[i] ≤ 10^5.

[output] an integer array

suffix sums of the orginal array.

Example
For prefixSums = [1, 3, 6, 10, 15],

the output should be [15, 14, 12, 9, 5].

You may verify that the initial array A is [1, 2, 3, 4, 5] (just try to calculate the prefix sums of it).

Then following the rules, you can calculate the suffix sums of A.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
prefixtosuffix(int *a, int *b, size_t n)
{
	size_t i;

	if (n == 0)
		return;

	b[0] = a[n - 1];
	for (i = 1; i < n; i++)
		b[i] = b[0] - a[i - 1];
}

void
test(int *a, size_t n, int *r)
{
	int b[128];

	prefixtosuffix(a, b, n);
	assert(!memcmp(b, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = { 1, 3, 6, 10, 15 };
	int a2[] = { 0 };
	int a3[] = { -1, -2, -3, -4, -5 };
	int a4[] = { 1, -4, 2, 90, 100, -1 };
	int a5[] = { 1, 0, 1, 0, 1, 0, 1, 0 };
	int a6[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	int a7[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };

	int r1[] = { 15, 14, 12, 9, 5 };
	int r2[] = { 0 };
	int r3[] = { -5, -4, -3, -2, -1 };
	int r4[] = { -1, -2, 3, -3, -91, -101 };
	int r5[] = { 0, -1, 0, -1, 0, -1, 0, -1 };
	int r6[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int r7[] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);

	return 0;
}
