/*

Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.

Example 1:

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
Example 2:

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.


Constraints:

3 <= arr.length <= 100
0 <= arr[i] <= 1000
0 <= a, b, c <= 1000

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
triplets(int *x, size_t n, int a, int b, int c)
{
	size_t i, j, k;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				if (abs(x[i] - x[j]) <= a &&
				    abs(x[j] - x[k]) <= b &&
				    abs(x[i] - x[k]) <= c)
					r++;
			}
		}
	}
	return r;
}

int
main(void)
{
	int a1[] = {3, 0, 1, 1, 9, 7};
	int a2[] = {1, 1, 2, 2, 3};

	assert(triplets(a1, nelem(a1), 7, 2, 3) == 4);
	assert(triplets(a2, nelem(a2), 0, 0, 1) == 0);

	return 0;
}
