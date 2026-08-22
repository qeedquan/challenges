var assert = require('assert');

function xor(a, b) {
	return a ^ b;
}

assert(xor(4, 6) == 2);
assert(xor(6, 9) == 15);
