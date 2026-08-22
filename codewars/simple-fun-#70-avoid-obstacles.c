/*

Task
You are given an array of integers arr that representing coordinates of obstacles situated on a straight line.

Assume that you are jumping from the point with coordinate 0 to the right. You are allowed only to make jumps of the same length represented by some integer.

Find the minimal length of the jump enough to avoid all the obstacles.

Example
For arr = [5, 3, 6, 7, 9], the output should be 4.

Check out the image below for better understanding:


Input/Output
[input] integer array arr

Non-empty array of positive integers.

Constraints: 1 ≤ inputArray[i] ≤ 100.

[output] an integer

The desired length.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
available(int *a, size_t n, int l)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (!(a[i] % l))
			return false;
	}
	return true;
}

int
avoid(int *a, size_t n)
{
	int i;

	for (i = 2; i < INT_MAX; i++) {
		if (available(a, n, i))
			return i;
	}
	return -1;
}

int
main()
{
	int a1[] = { 5, 3, 6, 7, 9 };
	int a2[] = { 2, 3 };
	int a3[] = { 1, 4, 10, 6, 2 };
	int a4[100];

	size_t i;

	for (i = 0; i < nelem(a4); i++)
		a4[i] = i + 1;

	assert(avoid(a1, nelem(a1)) == 4);
	assert(avoid(a2, nelem(a2)) == 4);
	assert(avoid(a3, nelem(a3)) == 7);
	assert(avoid(a4, nelem(a4)) == 101);

	return 0;
}
