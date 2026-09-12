/*

Simple challenge - eliminate all bugs from the supplied code so that the code runs and outputs the expected value. Output should be the length of the longest word, as a number.

There will only be one 'longest' word.

*/

var assert = require('assert');

function findLongest(str) {
	let split = str.split(' ');
	let longest = 0;
	for (let i = 0; i < split.length; i++)
		longest = Math.max(longest, split[i].length);
	return longest;
}

assert(findLongest("The quick white fox jumped around the massive dog") == 7);
assert(findLongest("Take me to tinseltown with you") == 10);
assert(findLongest("Sausage chops") == 7);
assert(findLongest("Wind your body and wiggle your belly") == 6);
assert(findLongest("Lets all go on holiday") == 7);

