/*

You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.

Your task is to assign a height to each tower so that:

The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
No two towers have the same height.
Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.

Example 1:

Input: maximumHeight = [2,3,4,3]

Output: 10

Explanation:

We can assign heights in the following way: [1, 2, 4, 3].

Example 2:

Input: maximumHeight = [15,10]

Output: 25

Explanation:

We can assign heights in the following way: [15, 10].

Example 3:

Input: maximumHeight = [2,2,1]

Output: -1

Explanation:

It's impossible to assign positive heights to each index so that no two towers have the same height.

Constraints:

1 <= maximumHeight.length <= 10^5
1 <= maximumHeight[i] <= 10^9

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
maximize(int *h, size_t n)
{
	size_t i;
	int p, r;

	if (n == 0)
		return 0;

	qsort(h, n, sizeof(*h), cmp);

	r = 0;
	p = h[n - 1] + 1;
	for (i = n; i > 0; i--) {
		p = min(h[i - 1], p - 1);
		if (p < 1)
			return -1;
		r += p;
	}
	return r;
}

int
main()
{
	int h1[] = { 2, 3, 4, 3 };
	int h2[] = { 15, 10 };
	int h3[] = { 2, 2, 1 };

	assert(maximize(h1, nelem(h1)) == 10);
	assert(maximize(h2, nelem(h2)) == 25);
	assert(maximize(h3, nelem(h3)) == -1);

	return 0;
}
