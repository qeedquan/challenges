/*

OEIS sequence A003242 comprises the numbers of Carlitz compositions for any given positive integer. This is the number of integer partitions of the integer for which no two adjacent parts are equal.

For example, for 4:

Generate the possible integer partitions (and their permutations): [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [1,3], [3,1], [2,2], [4]
Filter out those which have adjacent equal parts, leaving: [1,2,1], [1,3], [3,1], [4]
Count, giving us our result of 4
The first 16 terms, using zero-indexing are:

1, 1, 1, 3, 4, 7, 14, 23, 39, 71, 124, 214, 378, 661, 1152, 2024

Pleasingly, the recently arrived year, 2024, is the value of this sequence where n=15
.

This is code golf, so the shortest answer in bytes per language wins. Standard loopholes are forbidden. This is also a sequence challenge, so you may take an integer argument and return the nth term, take an integer argument and return the first n terms, or take no arguments and return the infinite sequence. You may use zero- or one- indexing.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A048272
vlong
A048272(vlong n)
{
	vlong i, odd, even;

	odd = even = 0;
	for (i = 1; i <= n; i++) {
		if (n % i)
			continue;

		if (i & 1)
			odd++;
		else
			even++;
	}
	return odd - even;
}

// https://oeis.org/A003242
vlong
A003242(vlong n)
{
	vlong i, r;

	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	r = 0;
	for (i = 1; i <= n; i++)
		r += A048272(i) * A003242(n - i);
	return r;
}

int
main(void)
{
	static const vlong A048272tab[] = {1, 0, 2, -1, 2, 0, 2, -2, 3, 0, 2, -2, 2, 0, 4, -3, 2, 0, 2, -2, 4, 0, 2, -4, 3, 0, 4, -2, 2, 0, 2, -4, 4, 0, 4, -3, 2, 0, 4, -4, 2, 0, 2, -2, 6, 0, 2, -6, 3, 0, 4, -2, 2, 0, 4, -4, 4, 0, 2, -4, 2, 0, 6, -5, 4, 0, 2, -2, 4, 0, 2, -6, 2, 0, 6, -2, 4, 0, 2, -6, 5, 0, 2, -4, 4, 0, 4, -4, 2, 0, 4, -2, 4};

	static const vlong A003242tab[] = {1, 1, 1, 3, 4, 7, 14, 23, 39, 71, 124, 214, 378, 661, 1152, 2024, 3542, 6189, 10843, 18978, 33202, 58130, 101742, 178045, 311648, 545470};

	unsigned i;

	for (i = 0; i < nelem(A048272tab); i++)
		assert(A048272(i + 1) == A048272tab[i]);

	for (i = 0; i < nelem(A003242tab); i++)
		assert(A003242(i) == A003242tab[i]);

	return 0;
}
