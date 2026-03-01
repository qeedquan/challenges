/*

You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions:

The value of the first element in arr must be 1.
The absolute difference between any 2 adjacent elements must be less than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 for each i where 1 <= i < arr.length (0-indexed). abs(x) is the absolute value of x.
There are 2 types of operations that you can perform any number of times:

Decrease the value of any element of arr to a smaller positive integer.
Rearrange the elements of arr to be in any order.
Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.

Example 1:

Input: arr = [2,2,1,2,1]
Output: 2
Explanation:
We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
The largest element in arr is 2.

Example 2:

Input: arr = [100,1,1000]
Output: 3
Explanation:
One possible way to satisfy the conditions is by doing the following:
1. Rearrange arr so it becomes [1,100,1000].
2. Decrease the value of the second element to 2.
3. Decrease the value of the third element to 3.
Now arr = [1,2,3], which satisfies the conditions.
The largest element in arr is 3.

Example 3:

Input: arr = [1,2,3,4,5]
Output: 5
Explanation: The array already satisfies the conditions, and the largest element is 5.

Hint 1
Sort the Array.

Hint 2
Decrement each element to the largest integer that satisfies the conditions.

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
solve(int *a, size_t n)
{
	size_t i;
	int r;

	if (n == 0)
		return 0;

	qsort(a, n, sizeof(*a), cmp);

	r = 1;
	for (i = 1; i < n; i++)
		r = min(r + 1, a[i]);
	return r;
}

int
main()
{
	int a1[] = { 2, 2, 1, 2, 1 };
	int a2[] = { 100, 1, 1000 };
	int a3[] = { 1, 2, 3, 4, 5 };

	assert(solve(a1, nelem(a1)) == 2);
	assert(solve(a2, nelem(a2)) == 3);
	assert(solve(a3, nelem(a3)) == 5);

	return 0;
}
