/*

Me thinks there aren't enough easy questions on here that beginners can attempt!

The challenge: Given a random input string of 1's and 0's such as:

10101110101010010100010001010110101001010
Write the shortest code that outputs the bit-wise inverse like so:

01010001010101101011101110101001010110101

*/

var assert = require('assert');

function flip(s) {
	var p = "";
	for (var i = 0; i < s.length; i++) {
		if (s[i] == '1')
			p += '0';
		else if (s[i] == '0')
			p += '1';
		else
			p += s[i];
	}
	return p;
}

function main() {
	assert(flip("10101110101010010100010001010110101001010") == "01010001010101101011101110101001010110101");
}

main();
