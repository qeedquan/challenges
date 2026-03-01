/*

A marquee is a low-tech board that allows customizable letters. For example, here is a marquee:

SALE ON SNEAKERS
However, someone might come along and vandalize it by removing letters to send a different message:

S     N    AKE
Given two non-empty string inputs, an original message and a new message, determine whether the new message can be created by removing characters from the original message. Spaces left by removal can be compressed, as above, or left in, as in the becoming t e by removing the h. Both messages will only contain letters and spaces, case is up to you.

Test Cases
"the", "the" -> true
"the", "t e" -> true
"the", "te" -> true
"te", "t e" -> false
"then i walked", "the" -> true
"then i walked", "niald" -> true
"abcde", "abj" -> false
"a b c d e", "abcde" -> true
"y today", "yt" -> true
"sale on sneakers", "snake" -> true
"today", "toad" -> false
"today", "tyy" -> false
"the sale on sneakers", "t e snake" -> true
"this is a sign", "th s i  a s  n" -> true
"the sale on sneakers", "the salon sneakers" -> true
"the sale on sneakers", "the sal  on sneakers" -> true
"a   b   c", "abc" -> true
"a   bc", "a  b  c" -> false
"a   b   c", "a       c" -> true
"a   b   c", "a        c" -> false
"the", " the" -> false
"the", " h " -> true
"the", "h" -> true

*/

var assert = require('assert');

function vandalizable(s, t) {
	var i = 0;
	for (const c of s) {
		if (i >= t.length)
			return true;
		if (c == t[i] || t[i] == ' ')
			i += 1;
	}
	return i >= t.length;
}

function main() {
	assert(vandalizable("the", "the") == true);
	assert(vandalizable("the", "t e") == true);
	assert(vandalizable("the", "te") == true);
	assert(vandalizable("te", "t e") == false);
	assert(vandalizable("then i walked", "the") == true);
	assert(vandalizable("then i walked", "niald") == true);
	assert(vandalizable("abcde", "abj") == false);
	assert(vandalizable("a b c d e", "abcde") == true);
	assert(vandalizable("y today", "yt") == true);
	assert(vandalizable("sale on sneakers", "snake") == true);
	assert(vandalizable("today", "toad") == false);
	assert(vandalizable("today", "tyy") == false);
	assert(vandalizable("the sale on sneakers", "t e snake") == true);
	assert(vandalizable("this is a sign", "th s i  a s  n") == true);
	assert(vandalizable("the sale on sneakers", "the salon sneakers") == true);
	assert(vandalizable("the sale on sneakers", "the sal  on sneakers") == true);
	assert(vandalizable("a   b   c", "abc") == true);
	assert(vandalizable("a   bc", "a  b  c") == false);
	assert(vandalizable("a   b   c", "a       c") == true);
	assert(vandalizable("a   b   c", "a        c") == false);
	assert(vandalizable("the", " the") == false);
	assert(vandalizable("the", " h ") == true);
	assert(vandalizable("the", "h") == true);
}

main();
