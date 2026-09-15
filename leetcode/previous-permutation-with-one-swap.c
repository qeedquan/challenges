/*

Given an array of positive integers arr (not necessarily distinct), return the

largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.

Note that a swap exchanges the positions of two numbers arr[i] and arr[j]

Example 1:

Input: arr = [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.

Example 2:

Input: arr = [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.

Example 3:

Input: arr = [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.

Constraints:

    1 <= arr.length <= 10^4
    1 <= arr[i] <= 10^4

Hint 1
You need to swap two values, one larger than the other. Where is the larger one located?

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void
ppo1(int *a, ssize_t n)
{
	ssize_t l, r;

	if (n < 1)
		return;

	l = n - 2;
	while (l >= 0 && a[l] <= a[l + 1])
		l--;

	if (l < 0)
		return;

	r = n - 1;
	while (r >= 0 && a[l] <= a[r])
		r--;
	while (r > 0 && a[r - 1] == a[r])
		r--;

	swap(&a[l], &a[r]);
}

void
test(int *a, size_t n, int *r)
{
	ppo1(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = { 3, 2, 1 };
	int a2[] = { 1, 1, 5 };
	int a3[] = { 1, 9, 4, 6, 7 };

	int r1[] = { 3, 1, 2 };
	int r2[] = { 1, 1, 5 };
	int r3[] = { 1, 7, 4, 6, 9 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);

	return 0;
}
