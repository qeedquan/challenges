/*

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3^x.

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 3^1 + 3^2
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 3^0 + 3^2 + 3^4
Example 3:

Input: n = 21
Output: false


Constraints:

1 <= n <= 10^7

*/

#include <assert.h>
#include <stdbool.h>

/*

https://oeis.org/A005836
https://www.geeksforgeeks.org/check-if-n-can-be-represented-as-sum-of-distinct-powers-of-3/

To have distinct powers of 3, to sum up to N, in ternary form the ith digit can be either 0, 1 or 2 (In Binary, it is 0 and 1). Thus, there can be three cases for each digit at ith position:

Digit can be 0 i.e. there is No 3^i number in N.
Digit can be 1 i.e, there is One 3^i number in N.
Digit cannot be 2 because then there are 2 of 3^i, therefore, not distinct.
Follow the below steps to solve the problem:

Iterate until N becomes 0 and perform the following steps:
If the value of N%3 is 2, then print “No”.
Otherwise, divide N by 3.
After completing the above steps, if the value of N is 0 then print “Yes”. Otherwise, “No”.

*/

bool
dp3(unsigned n)
{
	for (; n > 0; n /= 3) {
		if ((n % 3) == 2)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(dp3(12) == true);
	assert(dp3(91) == true);
	assert(dp3(21) == false);

	return 0;
}
