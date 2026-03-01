/*

In this example you need to implement a function that sort a list of integers based on it's binary representation.

The rules are simple:

sort the list based on the amount of 1's in the binary representation of each number.
if two numbers have the same amount of 1's, the shorter string goes first. (ex: "11" goes before "101" when sorting 3 and 5 respectively)
if the strings have the same length, lower decimal number goes first. (ex: 21 = "10101" and 25 = "11001", then 21 goes first as is lower)
Examples:

Input: [1,15,5,7,3]

( in binary strings is: ["1", "1111", "101", "111", "11"])
Output: [15, 7, 3, 5, 1]

(and after sortByBinaryOnes is: ["1111", "111", "11", "101", "1"])

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	unsigned x0, x1;
	unsigned b0, b1;
	unsigned w0, w1;

	x0 = *(unsigned *)a;
	x1 = *(unsigned *)b;

	b0 = stdc_count_ones(x0);
	b1 = stdc_count_ones(x1);
	if (b0 < b1)
		return 1;
	if (b0 > b1)
		return -1;

	w0 = stdc_bit_width(x0);
	w1 = stdc_bit_width(x1);
	if (w0 < w1)
		return -1;
	if (w0 > w1)
		return 1;

	if (x0 < x1)
		return -1;
	if (x0 > x1)
		return 1;
	return 0;
}

void
sortones(unsigned *a, size_t n)
{
	qsort(a, n, sizeof(*a), cmp);
}

void
test(unsigned *a, size_t n, unsigned *r)
{
	size_t i;

	sortones(a, n);
	for (i = 0; i < n; i++)
		printf("%u ", a[i]);
	printf("\n");
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main()
{
	unsigned a1[] = { 1, 3 };
	unsigned a2[] = { 1, 2, 3, 4 };
	unsigned a3[] = { 1, 15, 5, 7, 3 };
	unsigned a4[] = { 80, 21 };
	unsigned a5[] = { 0, 1024, 33 };
	unsigned a6[] = { 2, 2048, 3 };
	unsigned a7[] = { 5, 2049, 3 };
	unsigned a8[] = { 1, 5, 21, 7, 44, 99, 50, 51, 49, 80, 33, 25 };

	unsigned r1[] = { 3, 1 };
	unsigned r2[] = { 3, 1, 2, 4 };
	unsigned r3[] = { 15, 7, 3, 5, 1 };
	unsigned r4[] = { 21, 80 };
	unsigned r5[] = { 33, 1024, 0 };
	unsigned r6[] = { 3, 2, 2048 };
	unsigned r7[] = { 3, 5, 2049 };
	unsigned r8[] = { 51, 99, 7, 21, 25, 44, 49, 50, 5, 33, 80, 1 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);
	test(a8, nelem(a8), r8);

	return 0;
}
