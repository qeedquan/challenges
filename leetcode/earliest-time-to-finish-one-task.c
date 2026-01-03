/*

You are given a 2D integer array tasks where tasks[i] = [si, ti].

Each [si, ti] in tasks represents a task with start time si that takes ti units of time to finish.

Return the earliest time at which at least one task is finished.

Example 1:

Input: tasks = [[1,6],[2,3]]

Output: 5

Explanation:

The first task starts at time t = 1 and finishes at time 1 + 6 = 7. The second task finishes at time 2 + 3 = 5. You can finish one task at time 5.

Example 2:

Input: tasks = [[100,100],[100,100],[100,100]]

Output: 200

Explanation:

All three tasks finish at time 100 + 100 = 200.

Constraints:

    1 <= tasks.length <= 100
    tasks[i] = [si, ti]
    1 <= si, ti <= 100

Hint 1
Compute finish[i] = s[i] + t[i] for each task and take the minimum.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
earliest(int t[][2], size_t n)
{
	size_t i;
	int m;

	if (n == 0)
		return 0;

	m = INT_MAX;
	for (i = 0; i < n; i++)
		m = min(m, t[i][0] + t[i][1]);
	return m;
}

int
main()
{
	int t1[][2] = { { 1, 6 }, { 2, 3 } };
	int t2[][2] = { { 100, 100 }, { 100, 100 }, { 100, 100 } };

	assert(earliest(t1, nelem(t1)) == 5);
	assert(earliest(t2, nelem(t2)) == 200);

	return 0;
}
