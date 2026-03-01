/*

A Young diagram is an arrangement of boxes in left-justified rows and top-justified columns. For each box, all the spaces above it and to its left are occupied.

XXXXX
XXX
XXX
X
The hook length of a box is the number of boxes to its right in its row, and below it in its column, also counting itself once. For example, the second box has a hook length of 6:

X****
X*X
X*X
X
Here are all the hook lengths:

86521
532
421
1
Your goal is compute the product of the hook lengths, here 8*6*5*2*1*5*3*2*4*2*1*1 = 115200.

(Read about the hook length formula if you're interested in why this expression matters.)

Input: A collection of row-sizes as numbers like [5,3,3,1] or as a repeated unary symbol like [[1,1,1,1,1], [1,1,1], [1,1,1], [1]] or "XXXXX XXX XXX X". You can expect the list to be sorted ascending or descending, as you wish. The list will be non-empty and only contain positive integers.

Output: The product of hook lengths, which is a positive integer. Don't worry about integer overflows or runtime.

Built-ins dealing specifically with Young diagrams or integer partitions are not allowed.

Test cases:

[1] 1
[2] 2
[1, 1] 2
[5] 120
[2, 1] 3
[5, 4, 3, 2, 1] 4465125
[5, 3, 3, 1] 115200
[10, 5] 798336000

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
hooklength(vlong *a, vlong n)
{
	vlong *c, i, j, k, l, r;

	if (n < 1 || a[0] < 1)
		return 0;

	l = a[0];
	c = calloc(l, sizeof(*c));
	if (!c)
		return -1;

	for (i = 0; i < l; i++)
		c[i] = -1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < a[i]; j++)
			c[j] += 1;
	}

	r = 1;
	k = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < a[i]; j++)
			r *= a[i] - j + c[j] - k;
		k += 1;
	}

	free(c);
	return r;
}

int
main(void)
{
	vlong a1[] = {1};
	vlong a2[] = {2};
	vlong a3[] = {1, 1};
	vlong a4[] = {5};
	vlong a5[] = {2, 1};
	vlong a6[] = {5, 4, 3, 2, 1};
	vlong a7[] = {5, 3, 3, 1};
	vlong a8[] = {10, 5};

	assert(hooklength(a1, nelem(a1)) == 1LL);
	assert(hooklength(a2, nelem(a2)) == 2LL);
	assert(hooklength(a3, nelem(a3)) == 2LL);
	assert(hooklength(a4, nelem(a4)) == 120LL);
	assert(hooklength(a5, nelem(a5)) == 3LL);
	assert(hooklength(a6, nelem(a6)) == 4465125LL);
	assert(hooklength(a7, nelem(a7)) == 115200LL);
	assert(hooklength(a8, nelem(a8)) == 798336000LL);

	return 0;
}
