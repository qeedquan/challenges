/*

Given an array of positive integers arr, find a pattern of length m that is repeated k or more times.

A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times consecutively without overlapping.
A pattern is defined by its length and the number of repetitions.

Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.

Example 1:

Input: arr = [1,2,4,4,4,4], m = 1, k = 3
Output: true
Explanation: The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.

Example 2:

Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
Output: true
Explanation: The pattern (1,2) of length 2 is repeated 2 consecutive times. Another valid pattern (2,1) is also repeated 2 times.

Example 3:

Input: arr = [1,2,1,2,1,3], m = 2, k = 3
Output: false
Explanation: The pattern (1,2) is of length 2 but is repeated only 2 times. There is no pattern of length 2 that is repeated 3 or more times.

Constraints:

2 <= arr.length <= 100
1 <= arr[i] <= 100
1 <= m <= 100
2 <= k <= 100

Hint 1
Use a three-layer loop to check all possible patterns by iterating through all possible starting positions,
all indexes less than m, and if the character at the index is repeated k times.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
contains(int *a, size_t n, size_t m, size_t k)
{
	size_t c, i;

	if (m < 1 || k < 2)
		return false;

	for (c = i = 0; i + m < n; i++) {
		if (a[i] != a[i + m]) {
			c = 0;
			continue;
		}

		c += 1;
		if (c == (k - 1) * m)
			return true;
	}
	return false;
}

int
main()
{
	int a1[] = { 1, 2, 4, 4, 4, 4 };
	int a2[] = { 1, 2, 1, 2, 1, 1, 1, 3 };
	int a3[] = { 1, 2, 1, 2, 1, 3 };

	assert(contains(a1, nelem(a1), 1, 3) == true);
	assert(contains(a2, nelem(a2), 2, 2) == true);
	assert(contains(a3, nelem(a3), 2, 3) == false);

	return 0;
}
