/*

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].

Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].

Constraints:

    0 <= low <= high <= 10^9

*/

#include <assert.h>
#include <stdio.h>

int
oddsbf(int lo, int hi)
{
	int c, i;

	c = 0;
	for (i = lo; i <= hi; i++) {
		if (i & 1)
			c++;
	}
	return c;
}

/*

Let n = high - low
Let o = number of odds between the interval [low, high]

If n is even, o=n/2
If n is odd, then the number of odds depends on the parity of high/low
  If high or low is odd, o=n/2 + 1
  If both high and low is even, o=n/2

*/
int
odds(int lo, int hi)
{
	return ((hi - lo) / 2) + ((hi | lo) & 1);
}

int
main(void)
{
	int lo, hi, N;

	assert(odds(3, 7) == 3);
	assert(odds(8, 10) == 1);

	N = 2000;
	for (lo = 0; lo <= N; lo++) {
		for (hi = lo; hi <= N; hi++) {
			assert(odds(lo, hi) == oddsbf(lo, hi));
		}
	}

	return 0;
}
