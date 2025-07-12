/*

Complete the code which should return true if the given object is a single ASCII letter (lower or upper case), false otherwise.

*/

var assert = require('assert');

String.prototype.isLetter = function () {
	return /^[a-z]$/i.test(this);
}

for (let c = 'a'; c <= 'z'; c++)
	assert(c.isLetter() == true);
for (let c = 'A'; c <= 'Z'; c++)
	assert(c.isLetter() == true);
