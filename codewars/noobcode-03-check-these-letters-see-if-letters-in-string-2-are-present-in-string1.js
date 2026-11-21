/*

Write a function that checks if all the letters in the second string are present in the first one at least once, regardless of how many times they appear:

["ab", "aaa"]    =>  true
["trances", "nectar"]    =>  true
["compadres", "DRAPES"]  =>  true
["parses", "parsecs"]    =>  false

Function should not be case sensitive, as indicated in example #2. Note: both strings are presented as a single argument in the form of an array.

*/

var assert = require('assert');

function letterCheck(array) {
	let first = array[0];
	let second = array[1];
	for (let index in second) {
		let character = second[index];
		let lower = character.toLowerCase();
		let upper = character.toUpperCase();
		if (!first.includes(lower) && !first.includes(upper))
			return false;
	}
	return true;
}

assert(letterCheck(["ab", "aaa"]) == true);
assert(letterCheck(["trances", "nectar"]) == true);
assert(letterCheck(["compadres", "DRAPES"]) == true);
assert(letterCheck(["parses", "parsecs"]) == false);

