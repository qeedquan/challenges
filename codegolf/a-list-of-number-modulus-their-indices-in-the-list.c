/*

A simple one: Take a list of positive integers as input and output the numbers modulus their 1-based index in the list.

If the input integers are {a, b, c, d, e, f, g} then the output should be {a%1, b%2, c%3, d%4, e%5, f%6, g%7} where % is the modulus operator.

Test cases:

10  9  8  7  6  5  4  3  2  1
 0  1  2  3  1  5  4  3  2  1

8 18  6 11 14  3 15 10  6 19 12  3  7  5  5 19 12 12 14  5
0  0  0  3  4  3  1  2  6  9  1  3  7  5  5  3 12 12 14  5

1
0

1  1
0  1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
listmod(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		a[i] %= (i + 1);
}

void
test(int *a, size_t n, int *r)
{
	listmod(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int a2[] = { 8, 18, 6, 11, 14, 3, 15, 10, 6, 19, 12, 3, 7, 5, 5, 19, 12, 12, 14, 5 };
	int a3[] = { 1 };
	int a4[] = { 1, 1 };

	int r1[] = { 0, 1, 2, 3, 1, 5, 4, 3, 2, 1 };
	int r2[] = { 0, 0, 0, 3, 4, 3, 1, 2, 6, 9, 1, 3, 7, 5, 5, 3, 12, 12, 14, 5 };
	int r3[] = { 0 };
	int r4[] = { 0, 1 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);

	return 0;
}
