/*

Imagine that you are given two sticks. You want to end up with three sticks of equal length. You are allowed to cut either or both of the sticks to accomplish this, and can throw away leftover pieces.

Write a function, maxlen, that takes the lengths of the two sticks (L1 and L2, both positive values), that will return the maximum length you can make the three sticks.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
threesticks(int l1, int l2)
{
	int lo, hi;

	hi = max(l1, l2);
	lo = min(l1, l2);
	if (hi / 3 > lo)
		return hi / 3;
	if (hi - lo > lo)
		return lo;
	return hi / 2;
}

int
main()
{
	assert(threesticks(5, 12) == 5);
	assert(threesticks(12, 5) == 5);

	return 0;
}
