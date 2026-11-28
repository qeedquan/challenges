/*

You are given a sequence of valid words and a string. Test if the string is made up by one or more words from the array.

Task
Test if the string can be entirely formed by consecutively concatenating words of the dictionary.

For example:

dictionary: ["code", "wars"]

s1:         "codewars" =>  true  -> match 'code', 'wars'
s2:         "codewar"  =>  false -> match 'code', unmatched 'war'
One word from the dictionary can be used several times.

*/

var assert = require('assert');

function valid(dict, word) {
	if (word == "")
		return true;

	for (let i = 1; i <= word.length; i++) {
		if (dict.includes(word.slice(0, i)) && valid(dict, word.slice(i)))
			return true;
	}
	return false;
}

assert(valid(['code', 'wars'], 'codewars') == true);
assert(valid(['wars', 'code'], 'codewars') == true);
assert(valid(['code', 'wars'], 'codecodewars') == true);
assert(valid(['code', 'wars'], 'codewar') == false);
assert(valid(['code', 'wars'], 'codewarscode') == true);
assert(valid(['code', 'star', 'wars'], 'starwars') == true);
assert(valid(['Star', 'Code', 'Wars'], 'StarCodeWars') == true);
assert(valid(['Star', 'Code', 'Wars'], 'WarsStarCode') == true);
assert(valid(['Star', 'Code', 'Wars'], 'CodeStarsWar') == false);
assert(valid([], 'codewars') == false);
assert(valid(['code', 'wars'], 'code') == true);
assert(valid(['a', 'b', 'c', 'd', 'e', 'f'], 'abcdef') == true);
assert(valid(['a', 'b', 'c', 'd', 'e', 'f'], 'abcdefg') == false);
assert(valid(['ab', 'a', 'bc'], 'abc') == true);
assert(valid(['ab', 'bc'], 'abc') == false);

