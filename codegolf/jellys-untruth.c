/*

Jelly has an "untruth" atom: Ṭ. This takes a non-empty array of positive integers and returns a Boolean array with 1s at the indexes in the input. For example:

[1,3,5,6]Ṭ ⁼ [1,0,1,0,1,1]
[5]Ṭ       ⁼ [0,0,0,0,1]
[2,1,1,2]Ṭ ⁼ [1,1]
[5,4,3]Ṭ   ⁼ [0,0,1,1,1]
[1]Ṭ       ⁼ [1]

Try it online!

Note that Jelly uses 1-indexing, and that duplicate values in the array have no effect.

Your job is to take a non-empty array of positive integers and output the result of applying Ṭ on the array. If your language has a builtin with this exact behaviour, you may not use it. You may also choose to use zero indexing if you wish (so the above examples become [0,2,4,5], [4], [1,0,0,1] etc) and take non-negative integers in the input array.

You may use your language’s true and false values instead of 1 and 0, so long as they are the Boolean values rather than general truthy and falsey values (e.g. 0 and non-zero integers). You may also take input as a set if your language has that type. The input is not guaranteed to be sorted and may be in any order. The output may not have trailing zeros (or any other "trailing" values).

This is code-golf so the shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

size_t
untruth(unsigned *a, size_t n, unsigned *r)
{
	size_t i, l;

	for (i = l = 0; i < n; i++)
		l = max(l, a[i]);

	memset(r, 0, sizeof(*r) * l);
	for (i = 0; i < n; i++)
		r[a[i] - 1] = 1;

	return l;
}

void
test(unsigned *a, size_t n, unsigned *r, size_t nr)
{
	unsigned p[32];
	size_t np;

	np = untruth(a, n, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	unsigned a1[] = {1, 3, 5, 6};
	unsigned r1[] = {1, 0, 1, 0, 1, 1};

	unsigned a2[] = {5};
	unsigned r2[] = {0, 0, 0, 0, 1};

	unsigned a3[] = {2, 1, 1, 2};
	unsigned r3[] = {1, 1};

	unsigned a4[] = {5, 4, 3};
	unsigned r4[] = {0, 0, 1, 1, 1};

	unsigned a5[] = {1};
	unsigned r5[] = {1};

	test(a1, nelem(a1), r1, nelem(r1));
	test(a2, nelem(a2), r2, nelem(r2));
	test(a3, nelem(a3), r3, nelem(r3));
	test(a4, nelem(a4), r4, nelem(r4));
	test(a5, nelem(a5), r5, nelem(r5));

	return 0;
}
