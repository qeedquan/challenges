/*

Task is simple!
Take an array of binary values (can be boolean, 0/1, etc.) and use those bits to construct an n-th bit long unsigned integer (return type does not need to be an unsigned integer, just a number of any form)
Examples:
[0, 1, 1, 0, 1, 0]
->
26
[true, true, false, true, false, false, true, true, false]
->
422

Functions are treated as the program e.x.

function uint(input) {
   // code here
   return result;
}
is the same as

input = getInput();
// code here
print(result);
Smallest code in bytes wins

*/

var assert = require('assert');

function uint(input) {
	let value = 0;
	input.forEach((bit) => {
		value = (value << 1) | bit;
	});
	return value;
}

function main() {
	assert(uint([0, 1, 1, 0, 1, 0]) == 26);
	assert(uint([true, true, false, true, false, false, true, true, false]) == 422);
}

main();
