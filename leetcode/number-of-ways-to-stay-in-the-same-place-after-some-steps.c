/*

You have a pointer at index 0 in an array of size arrLen.
At each step, you can move 1 position to the left, 1 position to the right in the array,
or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Example 3:

Input: steps = 4, arrLen = 2
Output: 8

Constraints:

1 <= steps <= 500
1 <= arrLen <= 10^6

Hint 1
Try with Dynamic programming, dp(pos,steps): number of ways to back pos = 0 using exactly "steps" moves.

Hint 2
Notice that the computational complexity does not depend of "arrlen".

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

void
swap(vlong **a, vlong **b)
{
	vlong *t;

	t = *a;
	*a = *b;
	*b = t;
}

vlong
ways(vlong s, vlong n)
{
	static const vlong mod = 1000000007;

	vlong i, l, r;
	vlong *p, *q;

	l = min(1 + (s / 2), n);
	if (l < 1)
		return 0;

	p = calloc(l + 2, sizeof(*p));
	q = calloc(l + 2, sizeof(*q));
	if (!p || !q)
		goto error;

	for (p[1] = 1; s > 0; s--) {
		for (i = 1; i <= l; i++)
			q[i] = (p[i] + p[i - 1] + p[i + 1]) % mod;

		swap(&p, &q);
	}
	r = p[1];

	if (0) {
	error:
		r = -1;
	}

	free(p);
	free(q);
	return r;
}

int
main()
{
	assert(ways(3, 2) == 4);
	assert(ways(2, 4) == 2);
	assert(ways(4, 2) == 8);

	return 0;
}
