/*

You are given an array with several "even" words, one "odd" word, and some numbers mixed in.

Determine if any of the numbers in the array is the index of the "odd" word. If so, return true, otherwise false.

*/

var assert = require('assert');

function oddball(array) {
	return array.includes(array.indexOf('odd'));
}

assert(oddball(["even", 9, "even", 88, "even", 777, "even", 10, "odd", 8, "even"]) == true);
assert(oddball(["even", 63, "even", 1, "even", 88, "odd", 3, "even"]) == false);
assert(oddball(["even", 19, "odd", 2, "even"]) == true);

