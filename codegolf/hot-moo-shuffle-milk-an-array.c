/*

Background
Milking the deck is the name given to the following card shuffling method:

'Pinch' the deck to remove the top and bottom cards simultaneously. (With lots of imagination, this action resembles milking a cow.) This pair of cards forms the base of a new pile.
Repeat, adding each pair of cards to the top of the new pile, until the whole deck has been used.
Example

Suppose we start with a deck of six cards, [1, 2, 3, 4, 5, 6] (lower-indexed elements are nearer to the top). Let's milk the deck:

old = [1, 2, 3, 4, 5, 6], new = []
Remove [1, 6]: old = [2, 3, 4, 5], new = [1, 6]
Remove [2, 5]: old = [3, 4], new = [2, 5, 1, 6]
Remove [3, 4]: old = [], new = [3, 4, 2, 5, 1, 6]
After milking, the deck is therefore ordered [3, 4, 2, 5, 1, 6].

Challenge
Your task in this code-golf challenge is to implement the milking operation on a given array and output/return the result. The input array will contain only positive integers, not necessarily distinct. If the input array contains an odd number of elements, then the last milking step transfers only one element (the last one remaining) from the input to the output array.

Test cases
Input -> Output

[1, 2, 3, 4, 5, 6] -> [3, 4, 2, 5, 1, 6]
[1, 2, 3, 4, 5, 6, 7] -> [4, 3, 5, 2, 6, 1, 7]
[9, 7, 5, 3, 1, 2, 4, 6, 8, 10] -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
[1, 1, 2, 1, 2] -> [2, 1, 1, 1, 2]
[] -> []

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
milk(int *a, size_t n, int *r)
{
	size_t i, j;

	j = n;
	for (i = 0; i < n / 2; i++) {
		r[j - 1] = a[n - i - 1];
		r[j - 2] = a[i];
		j -= 2;
	}
	if (n & 1)
		r[0] = a[n / 2];
}

void
test(int *a, size_t n, int *r)
{
	int p[128];

	milk(a, n, p);
	if (n)
		assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = {1, 2, 3, 4, 5, 6};
	int a2[] = {1, 2, 3, 4, 5, 6, 7};
	int a3[] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 10};
	int a4[] = {1, 1, 2, 1, 2};

	int r1[] = {3, 4, 2, 5, 1, 6};
	int r2[] = {4, 3, 5, 2, 6, 1, 7};
	int r3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int r4[] = {2, 1, 1, 1, 2};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(NULL, 0, NULL);

	return 0;
}
