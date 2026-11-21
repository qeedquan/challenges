/*

Task
Given an array a of integers, construct an array b of the same length as a such that


b[0] = a[0] + a[1] + ... + a[n - 2] + a[n - 1]
b[1] =        a[1] + ... + a[n - 2] + a[n - 1]
...
b[n - 2] =                 a[n - 2] + a[n - 1]
b[n - 1] =                            a[n - 1]

where n is the length of a.

Input/Output
[input] integer array a

3 ≤ a.length ≤ 10^4,

-1000 ≤ a[i] ≤ 1000.

[output] an integer array

Example
For a = [1, 2, 3], the output should be [6, 5, 3].

b[0]= 1 + 2 + 3 = 6
b[1]=     2 + 3 = 5
b[2]=         3 = 3

For a = [1, 2, 3, -6], the output should be [0, -1, -3, -6].

b[0]= 1 + 2 + 3 - 6 = 0
b[1]=     2 + 3 - 6 = -1
b[2]=         3 - 6 = -3
b[3]=           - 6 = -6

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
suffixsums(int *a, int *b, size_t n)
{
	size_t i;

	if (n == 0)
		return;

	b[n - 1] = a[n - 1];
	for (i = n - 1; i > 0; i--)
		b[i - 1] += b[i] + a[i - 1];
}

void
test(int *a, size_t n, int *r)
{
	int b[128];

	suffixsums(a, b, n);
	assert(!memcmp(b, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = { 1, 2, 3 };
	int a2[] = { 1, 2, 3, -6 };

	int r1[] = { 6, 5, 3 };
	int r2[] = { 0, -1, -3, -6 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}
