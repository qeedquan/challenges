/*

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.


Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
odd3(int *a, size_t n)
{
	size_t i, j, k;

	for (i = 0; i < n; i = k) {
		j = i;
		while (j < n && (a[j] & 1) == 0)
			j++;

		k = j;
		while (k < n && (a[k] & 1) != 0)
			k++;

		if (k - j >= 3)
			return true;
	}
	return false;
}

int
main(void)
{
	int a1[] = {2, 6, 4, 1};
	int a2[] = {1, 2, 34, 3, 4, 5, 7, 23, 12};
	int a3[] = {1, 3, 6, 1, 2, 4, 1, 5, 10};
	int a4[] = {1, 3, 6, 1, 2, 4, 1, 5, 10, 1, 3, 5};

	assert(odd3(a1, nelem(a1)) == false);
	assert(odd3(a2, nelem(a2)) == true);
	assert(odd3(a3, nelem(a3)) == false);
	assert(odd3(a4, nelem(a4)) == true);

	return 0;
}
