/*

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j].
If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.

Constraints:

1 <= g.length <= 3 * 10^4
0 <= s.length <= 3 * 10^4
1 <= g[i], s[j] <= 2^31 - 1

Note: This question is the same as 2410: Maximum Matching of Players With Trainers.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
assign(int *a, size_t na, int *c, size_t nc)
{
	size_t i, j;

	qsort(a, na, sizeof(*a), cmp);
	qsort(c, nc, sizeof(*c), cmp);

	for (i = j = 0; i < na && j < nc; j++) {
		if (a[i] <= c[j])
			i++;
	}
	return i;
}

int
main(void)
{
	int a1[] = { 1, 2, 3 };
	int c1[] = { 1, 1 };

	int a2[] = { 1, 2 };
	int c2[] = { 1, 2, 3 };

	int a3[] = { 4, 7, 9 };
	int c3[] = { 8, 2, 5, 8 };

	int a4[] = { 1, 1, 1 };
	int c4[] = { 10 };

	assert(assign(a1, nelem(a1), c1, nelem(c1)) == 1);
	assert(assign(a2, nelem(a2), c2, nelem(c2)) == 2);
	assert(assign(a3, nelem(a3), c3, nelem(c3)) == 2);
	assert(assign(a4, nelem(a4), c4, nelem(c4)) == 1);

	return 0;
}
