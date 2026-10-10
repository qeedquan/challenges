/*

Another Kata testing an whether all elements of an array are square, although this time the array can be a multidemtional array with any number of dimensions.

Your task - Write a function that checks whether all elements in a multidimensional array are square numbers. The function should be able to take any number of array elements and any number of dimensions.

Your function should return true if all elements are square numbers and false if not.

An entirely empty array should return undefined.

You can assume that all array elements will be positive integers.

Examples:

isSquare([1, 4, 9, 16, 25, 36]);
//returns true

isSquare([1, 2, 3, 4, 5, 6]);
//returns false

isSquare([1, [4], [9, 16, 25], [36, 49, [64, 81]], [100, [121, 144, [169]]], [196, [225, [256, 289, [324, [361, 400]]]]]]);
//returns true

*/

var assert = require('assert');

function isSquare(x) {
	switch (typeof x) {
	case 'object':
		for (let i = 0; i < x.length; i++) {
			if (!isSquare(x[i]))
				return false;
		}
		return true;
	
	case 'number':
		let s = Math.floor(Math.sqrt(x));
		return s*s == x;
	}
	return false;
}

assert(isSquare([1, 4, 9, 16, 25, 36]) == true);
assert(isSquare([1, 2, 3, 4, 5, 6]) == false);
assert(isSquare([1, [4], [9, 16, 25], [36, 49, [64, 81]], [100, [121, 144, [169]]], [196, [225, [256, 289, [324, [361, 400]]]]]]) == true);

