/*

I define mousetails's sequence as follows:

If the nth element of the sequence is q, then n+1 must appear q times in the sequence
The sequence is weakly monotonically increasing (eg. no lower number may follow a higher number)
f(1)=1
I'll show an example of how this works:

the first element is 1
after the 1, come 1 2s
then 2 3s, since f(2)=2
then three 4s and three 5s, since f(3)=f(4)=3
then four 6s, four 7s, four 8s, five 9s, five 10s, and five 11s
six 12s, six 13s six 14s, six 15s, seven 16s etc.
Thus, it comes out to be

1,2,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,9,10,10,10,10,10,11,11,11,11,11,12,12,12,12,12,12,13,13,13,13,13,13,14,14,14,14,14,14,...
Sequence rules apply, you may either:

Given n, output the nth element of the sequence
Given n, output the first N terms
Output the sequence infinity
Either 0 or 1 based indexing is acceptable.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@Arnauld

a(1) = 1
a(2) = 2
a(n) = 1 + a(n - a(a(n - 1) - 1)), n >= 3

*/

int
mousetail(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return 1 + mousetail(n - mousetail(mousetail(n - 1) - 1));
}

int
main(void)
{
	static const int tab[] = {
		1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9,
		9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12,
		13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(mousetail(i + 1) == tab[i]);

	return 0;
}
