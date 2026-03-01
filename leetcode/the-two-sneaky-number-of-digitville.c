/*

In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1.
Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers.
Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.



Example 1:

Input: nums = [0,1,1,0]

Output: [0,1]

Explanation:

The numbers 0 and 1 each appear twice in the array.

Example 2:

Input: nums = [0,3,2,1,3,2]

Output: [2,3]

Explanation:

The numbers 2 and 3 each appear twice in the array.

Example 3:

Input: nums = [7,1,5,4,3,4,6,0,9,5,8,2]

Output: [4,5]

Explanation:

The numbers 4 and 5 each appear twice in the array.

Constraints:
2 <= n <= 100
nums.length == n + 2
0 <= nums[i] < n
The input is generated such that nums contains exactly two repeated elements.

Hint 1
To solve the problem without the extra space, we need to think about how many times each number occurs in relation to the index.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef int (*fn)(int, int);

int
filter(int *a, size_t n, int b, fn f)
{
	size_t i;
	int r;

	if (n < 2)
		return 0;

	r = 0;
	for (i = 0; i < n; i++) {
		if (f(a[i], b))
			r ^= a[i];
	}
	for (i = 0; i < n - 2; i++) {
		if (f(i, b))
			r ^= i;
	}
	return r;
}

int
btrue(int, int)
{
	return 1;
}

int
boff(int x, int b)
{
	return (x & b) == 0;
}

int
bon(int x, int b)
{
	return (x & b) != 0;
}

void
sneaky(int *a, size_t n, int r[2])
{
	int b;

	b = filter(a, n, 0, btrue);
	b = b & ~(b - 1);
	r[0] = filter(a, n, b, boff);
	r[1] = filter(a, n, b, bon);
}

void
test(int *a, size_t n, int r[2])
{
	int x[2];

	sneaky(a, n, x);
	printf("%d %d\n", x[0], x[1]);
	assert(!memcmp(x, r, sizeof(x)));
}

int
main()
{
	int a1[] = { 0, 1, 1, 0 };
	int a2[] = { 0, 3, 2, 1, 3, 2 };
	int a3[] = { 7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2 };

	int r1[] = { 0, 1 };
	int r2[] = { 2, 3 };
	int r3[] = { 4, 5 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);

	return 0;
}
