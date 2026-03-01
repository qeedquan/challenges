/*

You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.

Example 1:

Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.
Example 2:

Input: amount = [5,4,4]
Output: 7
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup, and a hot cup.
Second 2: Fill up a cold cup, and a warm cup.
Second 3: Fill up a cold cup, and a warm cup.
Second 4: Fill up a warm cup, and a hot cup.
Second 5: Fill up a cold cup, and a hot cup.
Second 6: Fill up a cold cup, and a warm cup.
Second 7: Fill up a hot cup.
Example 3:

Input: amount = [5,0,0]
Output: 5
Explanation: Every second, we fill up a cold cup.


Constraints:

amount.length == 3
0 <= amount[i] <= 100

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swap(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

void
sort3(int a[3])
{
	if (a[0] > a[1])
		swap(&a[0], &a[1]);
	if (a[1] > a[2])
		swap(&a[1], &a[2]);
	if (a[0] > a[1])
		swap(&a[0], &a[1]);
}

int
fillcups(int a[3])
{
	int c[3];
	int r;

	memcpy(c, a, sizeof(c));
	sort3(c);
	for (r = 0; c[2] > 0; r++) {
		c[2] -= 1;
		c[1] -= (c[1] > 0);
		sort3(c);
	}

	return r;
}

int
main(void)
{
	int a1[] = {1, 4, 2};
	int a2[] = {5, 4, 4};
	int a3[] = {5, 0, 0};

	assert(fillcups(a1) == 4);
	assert(fillcups(a2) == 7);
	assert(fillcups(a3) == 5);

	return 0;
}
