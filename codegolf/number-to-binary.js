/*

It seems we've managed to go all this time without a plain vanilla Number-To-Binary challenge! Whilst this will inevitably be only one element in many languages, it should put a few esolangs through their paces.

I truly looked for this challenge to no avail. If it already exists, comment as such and I'll delete this post-haste.

Input
A single non-negative integer.

Output
The same number as represented in Base 2.

Test Cases
4 -> 100
10 -> 1010
1234 -> 10011010010
Victory Condition
code-golf, so fewest bytes wins!

Notes
The output must consist of digits 0 and 1, either as characters or individual numbers in a list.
Zero may optionally return nothing.
Standard IO Applies
Standard Loopholes Apply
Have Fun!

*/

var assert = require('assert');

function main() {
	assert(4 == 0b100);
	assert(10 == 0b1010);
	assert(1234 == 0b10011010010);
}

main();
