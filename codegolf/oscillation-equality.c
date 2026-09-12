/*

We have objects that oscillate between two integer points, [l, r], at the speed of one unit per time unit, starting at l on t=0. You may assume l < r. For example, if an object oscillates on [3, 6], then we have:

t=0 -> 3
t=1 -> 4
t=2 -> 5
t=3 -> 6
t=4 -> 5
t=6 -> 4
t=7 -> 3
t=8 -> 4
Etc. But objects oscillate continuously, so we also have t=0.5 -> 3.5 and t=3.7 -> 5.3.

Given two objects oscillating between [l1, r1], [l2, r2], determine if there is ever a time t such that the two objects share the same position. You make take l1, r1, l2, r2 in any convenient format, and output any truthy/falsy values.

Truthy inputs:

[[3, 6], [3, 6]]
[[3, 6], [4, 8]]
[[0, 2], [2, 3]]
[[0, 3], [2, 4]]
[[7, 9], [8, 9]]

Falsy inputs:

[[0, 3], [3, 5]]
[[0, 2], [2, 4]]
[[5, 8], [9, 10]]
[[6, 9], [1, 2]]
[[1, 3], [2, 6]]

*/

#include <assert.h>

// Ported from @xnor solution
bool
resonate(int l1, int r1, int l2, int r2)
{
	int d, k, x;

	d = r1 - l1;
	if (d == 0)
		return false;

	k = 1;
	while (((r2 - l2) * k) % d)
		k += 1;
	x = ((k % 2) * d) / k;
	return r1 - l2 >= x && x <= r2 - l1;
}

int
main(void)
{
	assert(resonate(3, 6, 3, 6) == true);
	assert(resonate(3, 6, 4, 8) == true);
	assert(resonate(0, 2, 2, 3) == true);
	assert(resonate(0, 3, 2, 4) == true);
	assert(resonate(7, 9, 8, 9) == true);

	assert(resonate(0, 3, 3, 5) == false);
	assert(resonate(0, 2, 2, 4) == false);
	assert(resonate(5, 8, 9, 10) == false);
	assert(resonate(6, 9, 1, 2) == false);
	assert(resonate(1, 3, 2, 6) == false);

	return 0;
}
