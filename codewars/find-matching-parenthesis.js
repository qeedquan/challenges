/*

Implement String prototype method findParenMatch, taking an index pointing into the string as an argument:
String.prototype.findParenMatch = function(pos) {} ;

Based on the given index, return the index of the matching parenthesis in the given string; or -1, Nothing or a similar empty value, if there is no such index.

What is the matching parenthesis?

Consider this string: "(())". The two outer parentheses are a set, and the two inner ones are another set.

    set 1
  ________
 |        |
 V        V
 (  (  )  )
    ^  ^
    |__|
    set 2

Examples:

"(something)".findParenMatch(0) => 10 // because the parenthesis that matches the one on index 0 is at index 10.
"(something)".findParenMatch(10) => 0 // because the parenthesis that matches the one on index 10 is at index 0.

Let's consider something a bit more complicated:

"(som(th)ng)".findParenMatch(0)  => 10 // because the parenthesis that matches the one on index 0 is at index 10.
"(som(th)ng)".findParenMatch(10) =>  0 // because the parenthesis that matches the one on index 10 is at index 0.
"(som(th)ng)".findParenMatch(4)  =>  7 // because the parenthesis that matches the one on index 4 is at index 7.
"(som(th)ng)".findParenMatch(7)  =>  4 // because the parenthesis that matches the one on index 7 is at index 4.
More cases:

")()".findParenMatch(0) => -1 // because there is no matching parenthesis in the string
")()".findParenMatch(1) =>  2 // as usual.

"())".findParenMatch(0) =>  1 // since it's the closest match
"())".findParenMatch(1) =>  0 // as usual.
"())".findParenMatch(2) => -1 // because it's already closed by the parenthesis at index 1.
Input Assumptions
The index pos/n provided will always be within the range of the string.

The only characters occurring in the string are a-z and () - you do not need to account for other types of brackets such as [] or {}.

*/

var assert = require('assert');

String.prototype.findParenMatch = function (position) {
	let count = 1;
	let delta = (this[position] === '(') ? 1 : -1;
	for (let index = position + delta; index >= 0 && index < this.length; index += delta) {
		if (this[index] === '(')
			count += delta;
		if (this[index] === ')')
			count -= delta;
		if (!count)
			return index;
	}
	return -1;
};

assert("(something)".findParenMatch(0) == 10);
assert("(something)".findParenMatch(10) == 0);

assert("(som(th)ng)".findParenMatch(0) == 10);
assert("(som(th)ng)".findParenMatch(10) == 0);
assert("(som(th)ng)".findParenMatch(4) == 7);
assert("(som(th)ng)".findParenMatch(7) == 4);

assert(")()".findParenMatch(0) == -1);
assert(")()".findParenMatch(1) == 2);

assert("())".findParenMatch(0) == 1);
assert("())".findParenMatch(1) == 0);
assert("())".findParenMatch(2) == -1);

