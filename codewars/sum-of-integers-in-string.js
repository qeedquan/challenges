/*

Your task in this kata is to implement a function that calculates the sum of the integers inside a string. For example, in the string "The30quick20brown10f0x1203jumps914ov3r1349the102l4zy dog", the sum of the integers is 3635.

Note: only positive integers will be tested.

*/

var assert = require('assert');

function sumOfIntegersInString(string) {
	let numbers = string.match(/\d+/g) || [];
	return numbers.reduce((sum, value) => sum + parseInt(value), 0);
}

assert(sumOfIntegersInString("The30quick20brown10f0x1203jumps914ov3r1349the102l4zy dog") == 3635);

