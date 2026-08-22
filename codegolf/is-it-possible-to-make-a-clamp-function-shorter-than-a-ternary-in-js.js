/*

Imagine this short function to clamp a number between 0 and 255:

c = n => n > 0 ? n < 255 ? n : 255 : 0
Is this the shortest possible version of a clamp function with JavaScript (without ES.Next features)?

P.S: Not sure if it's relevant but, the 0 and 255 are not random, the idea is to clamp a number as an 8-bit unsigned integer.

*/

var assert = require('assert');

function clamp(x, a, b) {
	return Math.max(a, Math.min(x, b));
}

function main() {
	assert(clamp(2000, 0, 255) == 255);
	assert(clamp(35, 0, 255) == 35);
	assert(clamp(-35, 0, 255) == 0);
}

main();
