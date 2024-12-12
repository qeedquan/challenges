/*

A trick I learned in elementary school to determine whether or not a number was divisible by three is to add all of the integers in the number together and to divide the resulting sum by three.
If there is no remainder from dividing the sum by three, then the original number is divisible by three as well.

Given a series of digits as a string, determine if the number represented by the string is divisible by three.

Example:

"123"      -> true
"8409"     -> true
"100853"   -> false
"33333333" -> true
"7"        -> false

Try to avoid using the % (modulo) operator.

*/

var assert = require('assert');

function divisible3(n) {
	let r = 0;
	while (n > 0) {
		r += n % 10;
		n = Math.floor(n / 10);
	}
	return r%3 == 0;
}

function main() {
	assert(divisible3(123) == true);
	assert(divisible3(8409) == true);
	assert(divisible3(100853) == false);
	assert(divisible3(33333333) == true);
	assert(divisible3(7) == false);
	for (let i = 0; i <= 10000000; i++) {
		assert(divisible3(i) == !(i % 3));
	}
}

main();
