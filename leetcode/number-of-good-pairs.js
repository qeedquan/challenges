/*

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:

Input: nums = [1,2,3]
Output: 0

Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100

*/

var assert = require('assert');

function pairs(a) {
	var m = new Map();
	var c = 0;
	for (var i = 0; i < a.length-1; i++) {
		if (!m.has(a[i]))
			m.set(a[i], 0);
		m.set(a[i], m.get(a[i]) + 1);
		
		if (m.has(a[i+1]))
			c += m.get(a[i+1]);
	}
	return c;
}

function main() {
	assert(pairs([1, 2, 3, 1, 1, 3]) == 4);
	assert(pairs([1, 1, 1, 1]) == 6);
	assert(pairs([1, 2, 3]) == 0);
	assert(pairs([1, 2, 3, 2, 1]) == 2);
}

main();
