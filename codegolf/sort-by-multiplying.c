/*

You should write a program or function that given a list of positive integers multiplies each element with the smallest positive integer possible to create a strictly increasing list.

For example if the input is

5 4 12 1 3
the multiplications will be

5*1=5 4*2=8 12*1=12 1*13=13 3*5=15
and the output will be the increasing list

5 8 12 13 15
Input
A list of positive integers containing at least 1 element
Output
A list of positive integers
Examples
9 => 9
1 2 => 1 2
2 1 => 2 3
7 3 => 7 9
1 1 1 1 => 1 2 3 4
5 4 12 1 3 => 5 8 12 13 15
3 3 3 8 16 => 3 6 9 16 32
6 5 4 3 2 1 => 6 10 12 15 16 17
9 4 6 6 5 78 12 88 => 9 12 18 24 25 78 84 88
8 9 41 5 12 3 5 6 => 8 9 41 45 48 51 55 60
15 8 12 47 22 15 4 66 72 15 3 4 => 15 16 24 47 66 75 76 132 144 150 153 156

This is code golf so the shortest program or function wins.

Fun fact: the last element of the output for the input N, N-1, ... ,1 seems to be the (N+1)th element of the sequence A007952. If you find a proof, you are welcomed to include it in your golf answer or post it as a comment.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned uint;

void
dump(uint *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%u ", a[i]);
	printf("\n");
}

void
sort(uint *a, size_t n)
{
	size_t i;

	for (i = 1; i < n; i++) {
		if (a[i] == 0)
			a[i] = a[i - 1] + 1;
		else
			a[i] *= (a[i - 1] / a[i]) + 1;
	}
}

void
test(uint *a, size_t n, uint *r)
{
	sort(a, n);
	dump(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	uint a1[] = {9};
	uint r1[] = {9};

	uint a2[] = {1, 2};
	uint r2[] = {1, 2};

	uint a3[] = {7, 3};
	uint r3[] = {7, 9};

	uint a4[] = {1, 1, 1, 1};
	uint r4[] = {1, 2, 3, 4};

	uint a5[] = {5, 4, 12, 1, 3};
	uint r5[] = {5, 8, 12, 13, 15};

	uint a6[] = {3, 3, 3, 8, 16};
	uint r6[] = {3, 6, 9, 16, 32};

	uint a7[] = {6, 5, 4, 3, 2, 1};
	uint r7[] = {6, 10, 12, 15, 16, 17};

	uint a8[] = {9, 4, 6, 6, 5, 78, 12, 88};
	uint r8[] = {9, 12, 18, 24, 25, 78, 84, 88};

	uint a9[] = {8, 9, 41, 5, 12, 3, 5, 6};
	uint r9[] = {8, 9, 41, 45, 48, 51, 55, 60};

	uint a10[] = {15, 8, 12, 47, 22, 15, 4, 66, 72, 15, 3, 4};
	uint r10[] = {15, 16, 24, 47, 66, 75, 76, 132, 144, 150, 153, 156};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);
	test(a8, nelem(a8), r8);
	test(a9, nelem(a9), r9);
	test(a10, nelem(a10), r10);

	return 0;
}
