/*

Write a program in BF to insert Asterisks between each character and in the begining and the ending.

Input

1<=Input string length<100

The Input will consist of alphabets (Upper and lowercase), Numbers and special characters.

The input will be terminated with a null character for EOF.

Input: Good Morning!
Output: *G*o*o*d* *M*o*r*n*i*n*g*!*

*/

var assert = require('assert');

function asterisk(s) {
	r = "";
	for (var i = 0; i < s.length; i++) {
		r += "*" + s[i];
	}
	if (s.length > 0)
		r += "*";
	return r;
}

function main() {
	assert(asterisk("Good Morning!")) == "*G*o*o*d* *M*o*r*n*i*n*g*!*";
}

main();
