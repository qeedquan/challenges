/*

Task
Given an array of positive integers, replace each element with the parity of the sum of the other elements. The array is guaranteed to have at least 2 elements.

Definition
Parity: whether a number is odd or even.
Example
For the array [1,2,3,1]:

Replace 1 with the parity of 2+3+1, i.e. even.
Replace 2 with the parity of 1+3+1, i.e. odd.
Replace 3 with the parity of 1+2+1, i.e. even.
Replace 1 with the parity of 1+2+3, i.e. even.
Output: [even, odd, even, even]

Input
An array of positive integer.

You may take it as a proper array, or as a linefeed-separated string of positive integers.

You may assume that the array and the values inside are within the handling capability of your language.

Output
An array of two consistent values, one representing odd, one representing even.

You may output it as a linefeed-separated string of the two values.

Testcases
Inputs:

[1, 2, 3, 1]
[1, 2, 3, 2, 1]
[2, 2]
[100, 1001]

Outputs:

[even, odd, even, even]
[even, odd, even, odd, even]
[even, even]
[odd, even]
Note: you may choose other consistent values other than odd and even.

Scoring
This is code-golf. Shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
psoe(int *a, size_t n, int *r)
{
	size_t i;
	int p;

	p = 0;
	for (i = 0; i < n; i++)
		p ^= a[i];

	for (i = 0; i < n; i++)
		r[i] = (p ^ a[i]) & 1;
}

void
test(int *a, size_t n, int *r)
{
	int p[128];

	psoe(a, n, p);
	dump(p, n);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 2, 3, 1};
	int r1[] = {0, 1, 0, 0};

	int a2[] = {1, 2, 3, 2, 1};
	int r2[] = {0, 1, 0, 1, 0};

	int a3[] = {2, 2};
	int r3[] = {0, 0};

	int a4[] = {100, 1001};
	int r4[] = {1, 0};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);

	return 0;
}
