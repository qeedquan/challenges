/*

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.


Constraints:

1 <= time.length <= 6 * 10^4
1 <= time[i] <= 500

*/
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
pairsdiv60(int *t, size_t n)
{
	size_t i, j, k;
	int c[60];
	int r;

	memset(c, 0, sizeof(c));
	r = 0;
	for (i = 0; i < n; i++) {
		j = (60 - (t[i] % 60)) % 60;
		k = t[i] % 60;
		r += c[j];
		c[k] += 1;
	}
	return r;
}

int
main()
{
	int t1[] = { 30, 20, 150, 100, 40 };
	int t2[] = { 60, 60, 60 };

	assert(pairsdiv60(t1, nelem(t1)) == 3);
	assert(pairsdiv60(t2, nelem(t2)) == 3);

	return 0;
}
