/*

There are some stones on Bob's table in a row, and each of them can be red, green or blue, indicated by the characters R, G, and B.

Help Bob find the minimum number of stones he needs to remove from the table so that the stones in each pair of adjacent stones have different colours.

Examples:

"RGBRGBRGGB"   => 1
"RGGRGBBRGRR"  => 3
"RRRRGGGGBBBB" => 9

*/

var assert = require('assert');

function solve(stones) {
	let filtered = stones.replace(/(.)\1+/g, '$1');
	return stones.length - filtered.length;
}

assert(solve("") == 0);
assert(solve("RRGGBB") == 3);
assert(solve("RGBRGB") == 0);
assert(solve("BGRBBGGBRRR") == 4);
assert(solve("GBBBGGRRGRB") == 4);
assert(solve("GBRGGRBBBBRRGGGB") == 7);
assert(solve("RGBRGBRGGB") == 1);
assert(solve("RGGRGBBRGRR") == 3);
assert(solve("RRRRGGGGBBBB") == 9);

