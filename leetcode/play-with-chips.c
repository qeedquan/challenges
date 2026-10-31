/*

There are some chips, and the i-th chip is at position chips[i].

You can perform any of the two following types of moves any number of times (possibly zero) on any chip:

    Move the i-th chip by 2 units to the left or to the right with a cost of 0.
    Move the i-th chip by 1 unit to the left or to the right with a cost of 1.

There can be two or more chips at the same position initially.

Return the minimum cost needed to move all the chips to the same position (any position).

Example 1:

Input: chips = [1,2,3]
Output: 1
Explanation: Second chip will be moved to positon 3 with cost 1. First chip will be moved to position 3 with cost 0. Total cost is 1.

Example 2:

Input: chips = [2,2,2,3,3]
Output: 2
Explanation: Both fourth and fifth chip will be moved to position two with cost 1. Total minimum cost will be 2.


Constraints:

    1 <= chips.length <= 100
    1 <= chips[i] <= 10^9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
movechips(long *chips, size_t nchips)
{
	size_t count[2];
	size_t i;

	count[0] = count[1] = 0;
	for (i = 0; i < nchips; i++)
		count[chips[i] & 1] += 1;

	return min(count[0], count[1]);
}

int
main()
{
	long chips1[] = { 1, 2, 3 };
	long chips2[] = { 2, 2, 2, 3, 3 };
	long chips3[] = { 1, 1000000000 };

	assert(movechips(chips1, nelem(chips1)) == 1);
	assert(movechips(chips2, nelem(chips2)) == 2);
	assert(movechips(chips3, nelem(chips3)) == 1);

	return 0;
}
