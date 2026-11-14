/*

You are given an array of values.

Sum every number value in the array, and any nested arrays (to any depth).

Ignore all other types of values.

*/

var assert = require('assert');

function arraySum(array) {
	let total = 0;
	for (let index = 0; index < array.length; index++) {
		let element = array[index];
		if (typeof element === 'number' && !isNaN(element))
			total += element;
		else if (Array.isArray(element))
			total += arraySum(element);
	}
	return total;
}

assert(arraySum([1, 2]) == 3);
assert(arraySum([1, 2, 3]) == 6);
assert(arraySum([1, 2, [1, 2]]) == 6);
