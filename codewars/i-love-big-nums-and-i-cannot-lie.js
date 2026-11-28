/*

Write

function biggest(nums)
that given an array of numbers >= 0, will arrange them such that they form the biggest number.

For example:

biggest([1, 2, 3]) === '321'
biggest([3, 30, 34, 5, 9]) === '9534330'
The results will be large so make sure to return a string.

*/

var assert = require('assert');

function biggest(nums) {
	nums = nums.map(String);
	nums.sort((a, b) => (b + a).localeCompare(a + b));
	nums = nums.join('');
	nums = nums.replace(/^0+/, '0');
	return nums;
}

assert(biggest([1, 2, 3]) == '321');
assert(biggest([3, 30, 34, 5, 9]) == '9534330');

