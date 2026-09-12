/*

Your dad doesn't really get punctuation, and he's always putting extra commas in when he posts. You can tolerate the run-on sentences, as he does actually talk like that, but those extra commas have to go!

Write a function called dadFilter that takes a string as argument and returns a string with the extraneous commas removed. The returned string should not end with a comma or any trailing whitespace.

*/

var assert = require('assert');

function dadFilter(str) {
	str = str.replace(/,+/g, ',');
	str = str.trim();
	str = str.replace(/,$/, '');
	return str;
}

assert(dadFilter("all this,,,, used to be trees,,,,,,") == "all this, used to be trees");
assert(dadFilter("i,, don't believe this round earth,,, show me evadence!!") == "i, don't believe this round earth, show me evadence!!");
