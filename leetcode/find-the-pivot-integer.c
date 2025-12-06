/*

Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.


Constraints:

1 <= n <= 1000

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef long long vlong;

/*

https://oeis.org/A001109

1 + 2 + ... + x = x + ... + n
(1+x)*x/2 = (x+n)*(n-x+1)/2

Solve for x
x = sqrt((n^2 + n) / 2)

*/

vlong
pivotint(vlong n)
{
	vlong x, z;

	if (n < 0)
		return -1;

	z = ((n * n) + n) / 2;
	x = sqrt(z);
	return (x * x == z) ? x : -1;
}

int
main(void)
{
	assert(pivotint(8) == 6);
	assert(pivotint(1) == 1);
	assert(pivotint(4) == -1);

	return 0;
}
