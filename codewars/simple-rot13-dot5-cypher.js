/*

You are asked to write a simple cypher that rotates every character (in range [a-zA-Z], special chars will be ignored by the cipher) by 13 chars.
As an addition to the original ROT13 cipher, this cypher will also cypher numerical digits ([0-9]) with 5 chars.

Example:

"The quick brown fox jumps over the 2 lazy dogs"
will be cyphered to:

"Gur dhvpx oebja sbk whzcf bire gur 7 ynml qbtf"
Your task is to write a ROT13.5 (ROT135) method that accepts a string and encrypts it. Decrypting is performed by using the same method, but by passing the encrypted string again.

Note: when an empty string is passed, the result is also empty.

When passing your succesful algorithm, some random tests will also be applied. Have fun!

*/

var assert = require('assert');

function rot135(s) {
	r = "";
	for (let i = 0; i < s.length; i++) {
		c = s.charCodeAt(i);
		if (97 <= c && c <= 109)
			c += 13;
		else if (65 <= c && c <= 77)
			c += 13;
		else if (110 <= c && c <= 122)
			c -= 13;
		else if (78 <= c && c <= 90)
			c -= 13;
		else if (48 <= c && c <= 52)
			c += 5;
		else if (53 <= c && c <= 57)
			c -= 5;
		r += String.fromCharCode(c);
	}
	return r;
}

function main() {
	assert(rot135("The quick brown fox jumps over the 2 lazy dogs") == "Gur dhvpx oebja sbk whzcf bire gur 7 ynml qbtf");
	assert(rot135("Gur dhvpx oebja sbk whzcf bire gur 7 ynml qbtf") == "The quick brown fox jumps over the 2 lazy dogs");
}

main();
