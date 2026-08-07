/*

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.


Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"

Constraints:

1 <= n <= 9
1 <= k <= n!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef long long vlong;

int
perm(vlong n, vlong k, char *b)
{
	vlong g, i, *p, t;

	*b = '\0';
	if (n < 1 || k < 1)
		return -EINVAL;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -errno;

	t = 1;
	for (i = 1; i <= n; i++) {
		p[i - 1] = i;
		t *= i;
	}
	if (t < k)
		return -1;

	for (g = t; n > 0; n--) {
		g /= n;
		i = (k - 1) / g;
		b += sprintf(b, "%lld", p[i]);
		memmove(p + i, p + i + 1, sizeof(*p) * (n - i));
		k -= g * i;
	}

	free(p);
	return 0;
}

void
test(vlong n, vlong k, const char *r)
{
	char b[128];

	assert(perm(n, k, b) >= 0);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(3, 1, "123");
	test(3, 2, "132");
	test(3, 3, "213");
	test(3, 4, "231");
	test(3, 5, "312");
	test(3, 6, "321");
	test(4, 9, "2314");
	test(3, 1, "123");

	return 0;
}
