/*

Reversing an integer means to reverse all its digits.

    For example, reversing 2021 gives 1202. Reversing 12300 gives 321 as the leading zeros are not retained.

Given an integer num, reverse num to get reversed1, then reverse reversed1 to get reversed2. Return true if reversed2 equals num. Otherwise return false.
 

Example 1:

Input: num = 526
Output: true
Explanation: Reverse num to get 625, then reverse 625 to get 526, which equals num.

Example 2:

Input: num = 1800
Output: false
Explanation: Reverse num to get 81, then reverse 81 to get 18, which does not equal num.

Example 3:

Input: num = 0
Output: true
Explanation: Reverse num to get 0, then reverse 0 to get 0, which equals num.

 
Constraints:

    0 <= num <= 10^6

*/

var assert = require('assert');

function rev(n) {
	var r = 0;
	while (n > 0) {
		r = (r * 10) + (n % 10);
		n = Math.floor(n / 10);
	}
	return r;
}

function isorev(n) {
	return n == rev(rev(n));
}

function main() {
	assert(isorev(526) == true);
	assert(isorev(1800) == false);
	assert(isorev(0) == true);
	assert(isorev(6001) == true);
	assert(isorev(100) == false);
	assert(isorev(2021) == true);
	assert(isorev(12300) == false);
	assert(isorev(12301) == true);
}

main();
