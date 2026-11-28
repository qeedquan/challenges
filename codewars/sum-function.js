/*

Write a sum function which will work properly when invoked using either syntax below.

sum(2,3);  // Outputs 5
sum(2)(3); // Outputs 5

HINT : use closures

*/

var assert = require('assert');

function sum() {
	switch (arguments.length) {
	case 0:
		return 0;
	case 1:
		return (x) => sum(arguments[0], x);
	}

	let total = 0;
	for (let i = 0; i < arguments.length; i++)
		total += arguments[i];
	return total;
}

assert(sum(2, 3) == 5);
assert(sum(2)(3) == 5);
