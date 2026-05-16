/*

Modify the spacify function so that it returns the given string with spaces inserted between each character.

spacify("hello world") // returns "h e l l o   w o r l d"

*/

var assert = require('assert');

function spacify(s) {
	let r = "";
	for (let i = 0; i < s.length; i++) {
		r += s[i];
		if (i + 1 < s.length)
			r += ' ';
	}
	return r;
}

assert(spacify("hello world") == "h e l l o   w o r l d");
