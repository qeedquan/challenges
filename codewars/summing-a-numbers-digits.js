/*

Write a function named sumDigits which takes a number as input and returns the sum of the absolute value of each of the number's decimal digits.

For example: (Input --> Output)

10 --> 1
99 --> 18
-32 --> 5
Let's assume that all numbers in the input will be integer values.

*/

var assert = require('assert');

function digsum(n) {
	let r = 0;
	n = Math.abs(n);
	while (n > 0) {
		r += n % 10;
		n = Math.floor(n / 10);
	}
	return r;
}

assert(digsum(10) == 1);
assert(digsum(99) == 18);
assert(digsum(-32) == 5);
