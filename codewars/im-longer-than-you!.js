/*

Create a function longer that accepts a string and sorts the words in it based on their respective lengths in an ascending order. If there are two words of the same lengths, sort them alphabetically. Look at the examples below for more details.

longer("Another Green World") => Green World Another
longer("Darkness on the edge of Town") => of on the Town edge Darkness
longer("Have you ever Seen the Rain") => the you Have Rain Seen ever
Assume that only only Alphabets will be entered as the input. Uppercase characters have priority over lowercase characters. That is,

longer("hello Hello") => Hello hello
Don't forget to rate this kata and leave your feedback!! Thanks

*/

var assert = require('assert');

function compare(a, b) {
	if (a.length < b.length)
		return -1;
	if (a.length > b.length)
		return 1;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

function longer(s) {
	let t = s.split(' ');
	t.sort(compare);
	return t.join(' ');
}

assert(longer("Another Green World") == "Green World Another");
assert(longer("Darkness on the edge of Town") == "of on the Town edge Darkness");
assert(longer("Have you ever Seen the Rain") == "the you Have Rain Seen ever");
assert(longer("hello Hello") == "Hello hello");
