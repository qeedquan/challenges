/*

A square triple (a,b,c) is a triple where a, b, and c are integers and a^2 + b^2 = c^2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

Example 1:

Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).

Example 2:

Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).

Constraints:

    1 <= n <= 250

*/

var assert = require('assert');

function triples(n) {
	var r = 0;
	for (var a = 1; a <= n; a++) {
		for (var b = 1; b <= n; b++) {
			var c = Math.hypot(a, b);
			var d = Math.floor(c);
			if (c > n)
				break;
			if (c == d)
				r++;
		}
	}
	return r;
}

function main() {
	assert(triples(5) == 2);
	assert(triples(10) == 4);
}

main();
