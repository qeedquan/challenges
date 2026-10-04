/*

Given two integer arrays startTime and endTime and given an integer queryTime.

The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].

Return the number of students doing their homework at time queryTime.
More formally, return the number of students where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.

Example 1:

Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
Output: 1
Explanation: We have 3 students where:
The first student started doing homework at time 1 and finished at time 3 and wasn't doing anything at time 4.
The second student started doing homework at time 2 and finished at time 2 and also wasn't doing anything at time 4.
The third student started doing homework at time 3 and finished at time 7 and was the only student doing homework at time 4.

Example 2:

Input: startTime = [4], endTime = [4], queryTime = 4
Output: 1
Explanation: The only student was doing their homework at the queryTime.

Constraints:

    startTime.length == endTime.length
    1 <= startTime.length <= 100
    1 <= startTime[i] <= endTime[i] <= 1000
    1 <= queryTime <= 1000

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
busy(int *s, int *e, size_t n, int q)
{
	size_t i;
	int c;

	c = 0;
	for (i = 0; i < n; i++) {
		if (s[i] <= q && q <= e[i])
			c++;
	}
	return c;
}

int
main(void)
{
	int s1[] = {1, 2, 3};
	int e1[] = {3, 2, 7};

	int s2[] = {4};
	int e2[] = {4};

	assert(busy(s1, e1, nelem(s1), 4) == 1);
	assert(busy(s2, e2, nelem(s2), 4) == 1);

	return 0;
}
