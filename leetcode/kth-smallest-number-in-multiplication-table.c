/*

Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

Example 1:

https://assets.leetcode.com/uploads/2021/05/02/multtable1-grid.jpg

Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.

Example 2:

https://assets.leetcode.com/uploads/2021/05/02/multtable2-grid.jpg

Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.

Constraints:

    1 <= m, n <= 3 * 10^4
    1 <= k <= m * n

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
kthbf(int m, int n, int k)
{
	int *x, l, r;
	int i, j;

	x = calloc(m * n, sizeof(*x));
	if (!x)
		return -1;

	l = 0;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++)
			x[l++] = i * j;
	}

	qsort(x, l, sizeof(*x), cmp);

	r = x[k - 1];

	free(x);
	return r;
}

int
count(int t, int m, int n)
{
	int c, i;

	c = 0;
	for (i = 1; i <= m; i++)
		c += min(t / i, n);
	return c;
}

int
kth(int m, int n, int k)
{
	int l, r, p;

	l = 1;
	r = m * n;
	while (l <= r) {
		p = l + (r - l) / 2;
		if (count(p, m, n) >= k)
			r = p - 1;
		else
			l = p + 1;
	}
	return l;
}

int
main()
{
	int m, n, k;

	assert(kth(3, 3, 5) == 3);
	assert(kth(2, 3, 6) == 6);

	for (m = 1; m <= 30; m++) {
		for (n = 1; n <= 30; n++) {
			for (k = 1; k <= m * n; k++)
				assert(kth(m, n, k) == kthbf(m, n, k));
		}
	}

	return 0;
}
