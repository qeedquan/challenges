/*

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2


Constraints:

2 <= values.length <= 5 * 10^4
1 <= values[i] <= 1000

Hint 1
Can you tell the best sightseeing spot in one pass (ie. as you iterate over the input?) What should we store or keep track of as we iterate to do this?

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxsight(int *a, size_t n)
{
	size_t i;
	int c, r;

	c = r = 0;
	for (i = 0; i < n; i++) {
		r = max(r, c + a[i]);
		c = max(c, a[i]) - 1;
	}
	return r;
}

int
main()
{
	int a1[] = { 8, 1, 5, 2, 6 };
	int a2[] = { 1, 2 };

	assert(maxsight(a1, nelem(a1)) == 11);
	assert(maxsight(a2, nelem(a2)) == 2);

	return 0;
}
