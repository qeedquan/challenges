/*

You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
 

Constraints:

1 <= k <= n <= 1000
 

Follow up:

Could you solve this problem in less than O(n) complexity?

Hint:
The factors of n will be always in the range [1, n].
Keep a list of all factors sorted. Loop i from 1 to n and add i if n % i == 0. Return the kth factor if it exist in this list.

*/

var assert = require('assert');

// https://helloacm.com/efficient-algorithms-to-compute-the-kth-factor-of-a-natural-number-n/
function kthfactor(n, k) {
	if (n <= 0 || k <= 0)
		return -1;

	for (var d = 1; d*d <= n; d++) {
		if (n%d == 0 && --k == 0)
			return d;
	}

	for (d--; d >= 1; d--) {
		if (d*d == n)
			continue;
		
		if (n%d == 0 && --k == 0)
			return n/d;
	}

	return -1;
}

function main() {
	assert(kthfactor(12, 3) == 3);
	assert(kthfactor(7, 2) == 7);
	assert(kthfactor(4, 4) == -1);
	assert(kthfactor(1, 1) == 1);
	assert(kthfactor(1000, 3) == 4);
}

main();
