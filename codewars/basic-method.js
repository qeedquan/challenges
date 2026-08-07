/*

Extend the Array's built-in functions by implementing .max() method. This method will return the largest number in the array. If the array contains one or more non-number elements that can't be converted into numbers (e.g., string letters), return NaN

Example:

[2,5,1,3].max() // returns 5
[1,2,3,8,4,9,7,42,99].max() // returns 99
[2,'5',1,3].max() // returns 5 ("5" can be converted to 5)
[2,5,1,'ab'].max() // returns NaN ("ab" can't be converted to a number)

Array will contain at least one item.

*/

var assert = require('assert');

Array.prototype.max = function() {
	let max = -Infinity;
	for (let i = 0; i < this.length; i++) {
		let value = +this[i];
		if (isNaN(value))
			return NaN;
		if (max < value)
			max = value;
	}
	return max;
};

assert([2, 5, 1, 3].max() == 5);
assert([1, 2, 3, 8, 4, 9, 7, 42, 99].max() == 99);
assert([2, '5', 1, 3].max() == 5);
assert(isNaN([2, 5, 1, 'ab'].max()));

