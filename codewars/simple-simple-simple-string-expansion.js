/*

Given a string that includes alphanumeric characters ('3a4B2d') return the expansion of that string: The numeric values represent the occurrence of each letter preceding that numeric value. There should be no numeric characters in the final string. Empty strings should return an empty string.

The first occurrence of a numeric value should be the number of times each character behind it is repeated, until the next numeric value appears.

stringExpansion('3D2a5d2f') === 'DDDaadddddff'
stringExpansion('3abc') === 'aaabbbccc'      // correct
stringExpansion('3abc') !== 'aaabc'          // wrong
stringExpansion('3abc') !== 'abcabcabc'      // wrong
If there are two consecutive numeric characters the first one is ignored.

stringExpansion('3d332f2a') === 'dddffaa'
If there are two consecutive alphabetic characters then the first character has no effect on the one after it.

stringExpansion('abcde') === 'abcde'
Your code should be able to work for both lower and capital case letters.

stringExpansion('') === ''

*/

var assert = require('assert');

function stringExpansion(input) {
	let repeats = 1;
	let result = "";
	for (let index = 0; index < input.length; index++) {
		if (/\d/.test(input[index]))
			repeats = Number(input[index]);
		else
			result += input[index].repeat(repeats);
	}
	return result;
}

assert(stringExpansion("3D2a5d2f") == "DDDaadddddff");
assert(stringExpansion("3abc") == "aaabbbccc");
assert(stringExpansion("3d332f2a") == "dddffaa");
assert(stringExpansion("abcde") == "abcde");
assert(stringExpansion("") == "");

