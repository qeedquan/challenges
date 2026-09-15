/*

Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.


Example 1:

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
Example 2:

Input: arr = [4,8,12,16]
Output: 2
Example 3:

Input: arr = [100]
Output: 1


Constraints:

1 <= arr.length <= 4 * 10^4
0 <= arr[i] <= 10^9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
turbulence(int *a, size_t n)
{
	int r, x, y;
	size_t i;

	r = x = y = 1;
	for (i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			x = y + 1;
			y = 1;
		} else if (a[i] < a[i - 1]) {
			y = x + 1;
			x = 1;
		} else
			x = y = 1;

		r = max(r, max(x, y));
	}
	return r;
}

int
main(void)
{
	int a1[] = {9, 4, 2, 10, 7, 8, 8, 1, 9};
	int a2[] = {4, 8, 12, 16};
	int a3[] = {100};

	assert(turbulence(a1, nelem(a1)) == 5);
	assert(turbulence(a2, nelem(a2)) == 2);
	assert(turbulence(a3, nelem(a3)) == 1);

	return 0;
}
