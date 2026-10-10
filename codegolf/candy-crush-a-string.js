/*

Given a non-empty string (or an integer if you prefer) composed exclusively of digits in the range [1-9], your task is to write a function (or a whole program) that applies a "Match-3 type of rule" from left to right and outputs the resulting string, like this :

[parameter] "12223" -> [returned value] "13"
Meaning, while parsing the string from left to right if you encounter the same digit repeated 3 or more times successively, this whole group of digits must "disappear", resulting in the concatenation of the left and right part of the remaining string.


Each time you deal with a group, you must start again from the left end and reiterate the same process until the string no longer changes (normally when you finally reach the right end).


If the string becomes empty at the end of the process, you should output an empty string, or the digit 0 as you prefer.

Test cases :

"1" -> "1"
"31122213" -> "33"
"44555554446" -> "6"
"1322232223222311" -> "1311"
"111" -> ""
"7789998877" -> ""

This is code-golf, so the shortest solution in bytes wins.

*/

var assert = require('assert');

function candycrush(s) {
	while (true) {
		t = s.replace(/(.)\1\1+/, '');
		if (s == t)
			break;
		s = t;
	}
	return s;
}

function main() {
	assert(candycrush("1") == "1");
	assert(candycrush("31122213") == "33");
	assert(candycrush("44555554446") == "6");
	assert(candycrush("1322232223222311") == "1311");
	assert(candycrush("111") == "");
	assert(candycrush("7789998877") == "");
}

main();
