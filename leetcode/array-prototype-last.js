/*

Write code that enhances all arrays such that you can call the array.last() method on any array and it will return the last element. If there are no elements in the array, it should return -1.

Example 1:

Input: nums = [1,2,3]
Output: 3
Explanation: Calling nums.last() should return the last element: 3.
Example 2:

Input: nums = []
Output: -1
Explanation: Because there are no elements, return -1.
 

Constraints:

0 <= arr.length <= 1000
0 <= arr[i] <= 1000

Hint:
Inside the Array.prototype.last function body, you have access to the "this" keyword. "this" is equal to the contents of the array in this case.You can access elements in the array via this[0], this[1], etc.
You can also access properties and method like this.length, this.forEach, etc.

*/

var assert = require('assert');

Array.prototype.last = function() {
	if (this.length == 0)
		return -1;
	return this[this.length - 1];
}

function main() {
	assert([1, 2, 3].last() == 3);
	assert([].last() == -1);
}

main();
