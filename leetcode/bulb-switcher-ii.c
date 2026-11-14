/*

There is a room with n bulbs labeled from 1 to n that all are turned on initially, and four buttons on the wall. Each of the four buttons has a different functionality where:

Button 1: Flips the status of all the bulbs.
Button 2: Flips the status of all the bulbs with even labels (i.e., 2, 4, ...).
Button 3: Flips the status of all the bulbs with odd labels (i.e., 1, 3, ...).
Button 4: Flips the status of all the bulbs with a label j = 3k + 1 where k = 0, 1, 2, ... (i.e., 1, 4, 7, 10, ...).
You must make exactly presses button presses in total. For each press, you may pick any of the four buttons to press.

Given the two integers n and presses, return the number of different possible statuses after performing all presses button presses.

Example 1:

Input: n = 1, presses = 1
Output: 2
Explanation: Status can be:
- [off] by pressing button 1
- [on] by pressing button 2
Example 2:

Input: n = 2, presses = 1
Output: 3
Explanation: Status can be:
- [off, off] by pressing button 1
- [on, off] by pressing button 2
- [off, on] by pressing button 3
Example 3:

Input: n = 3, presses = 1
Output: 4
Explanation: Status can be:
- [off, off, off] by pressing button 1
- [off, on, off] by pressing button 2
- [on, off, on] by pressing button 3
- [off, on, on] by pressing button 4

Constraints:

1 <= n <= 1000
0 <= presses <= 1000

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

/*

https://baihuqian.github.io/2018-07-31-bulb-switcher-ii/

As before, the first 6 lights uniquely determine the rest of the lights. This is because every operation that modifies the x-th light also modifies the (x+6)-th light, so the x-th light is always equal to the (x+6)-th light.

Actually, the first 3 lights uniquely determine the rest of the sequence, as shown by the table below for performing the operations a, b, c, d:

Light 1 = 1 + a + c + d
Light 2 = 1 + a + b
Light 3 = 1 + a + c
Light 4 = 1 + a + b + d
Light 5 = 1 + a + c
Light 6 = 1 + a + b
So that (modulo 2):

Light 4 = (Light 1) + (Light 2) + (Light 3)
Light 5 = Light 3
Light 6 = Light 2
The above justifies taking n=min(n,3) without loss of generality. The rest is now casework.

Let’s denote the state of lights by the tuple (a,b,c). The transitions are to XOR by (1, 1, 1), (0, 1, 0), (1, 0, 1), or (1, 0, 0).

When m = 0, all the lights are on, and there is only one state (1, 1, 1). The answer in this case is always 1.

When m = 1, we could get states (0, 0, 0), (1, 0, 1), (0, 1, 0)(, or (0, 1, 1). The answer in this case is either 2, 3, 4 for n = 1, 2, 3 respectively.

When m = 2, we can manually check that we can get 7 states: all of them except for (0, 1, 1). The answer in this case is either 2, 4, 7 for n = 1, 2, 3 respectively.

When m = 3, we can get all 8 states. The answer in this case is either 2, 4, 8 for n = 1, 2, 3 respectively.

*/

int
fliplights(int n, int m)
{
	static const int tab[4][3] = {
	    {1, 1, 1},
	    {2, 3, 4},
	    {2, 4, 7},
	    {2, 4, 8},
	};

	if (n <= 0 || m < 0)
		return 0;

	n = min(n, 3);
	m = min(m, 3);
	return tab[m][n - 1];
}

int
main(void)
{
	assert(fliplights(1, 1) == 2);
	assert(fliplights(2, 1) == 3);
	assert(fliplights(3, 1) == 4);

	return 0;
}
