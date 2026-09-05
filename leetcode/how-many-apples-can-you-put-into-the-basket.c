/*

You have some apples and a basket that can carry up to 5000 units of weight.

Given an integer array weight where weight[i] is the weight of the ith apple, return the maximum number of apples you can put in the basket.

Example 1:

Input: weight = [100,200,150,1000]
Output: 4
Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.

Example 2:

Input: weight = [900,950,800,1000,700,800]
Output: 5
Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.

Constraints:

1 <= weight.length <= 10^3
1 <= weight[i] <= 10^3

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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
apples(int *a, size_t n)
{
	static const int limit = 5000;

	int r, t;
	size_t i;

	qsort(a, n, sizeof(*a), cmp);

	r = t = 0;
	for (i = 0; i < n; i++) {
		if (t + a[i] > limit)
			break;
		t += a[i];
		r += 1;
	}
	return r;
}

int
main()
{
	int a1[] = { 100, 200, 150, 1000 };
	int a2[] = { 900, 950, 800, 1000, 700, 800 };

	assert(apples(a1, nelem(a1)) == 4);
	assert(apples(a2, nelem(a2)) == 5);

	return 0;
}
