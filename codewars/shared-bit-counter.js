/*

Complete the method that returns true if 2 integers share at least two 1 bits, otherwise return false. For simplicity assume that all numbers are non-negative.

Examples
 7  =  0111 in binary
10  =  1010
15  =  1111
7 and 10 share only a single 1-bit (at index 2) --> false
7 and 15 share 3 1-bits (at indexes 1, 2, and 3) --> true
10 and 15 share 2 1-bits (at indexes 0 and 2) --> true
Hint: you can do this with just string manipulation, but binary operators will make your life much easier.

*/

var assert = require('assert');

function popcnt(n) {
	let c = 0;
	while (n != 0) {
		n &= (n - 1);
		c += 1;
	}
	return c;
}

function sharedbits(a, b) {
	return popcnt(a & b) >= 2;
}

function main() {
	assert(sharedbits(7, 10) == false);
	assert(sharedbits(7, 15) == true);
	assert(sharedbits(10, 15) == true);
}

main();
