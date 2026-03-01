/*

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:

Input: rowIndex = 0
Output: [1]

Example 3:

Input: rowIndex = 1
Output: [1,1]

Constraints:

    0 <= rowIndex <= 33

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

*/

var assert = require('assert');

function equal(a, b) {
	if (a.length != b.length)
		return false;
	return a.every((v, i) => v == b[i])
}

function binomial(n, k) {
	var c = 1;
	for (var x = n-k+1; x <= n; x++)
		c *= x;
	for (x = 1; x <= k; x++)
		c = Math.floor(c/x);
	return c;
}

function row(n) {
	r = [];
	for (var k = 0; k <= n; k++) {
		r.push(binomial(n, k));
	}
	return r;
}

function main() {
	assert(equal(row(3), [1, 3, 3, 1]));
	assert(equal(row(0), [1]));
	assert(equal(row(1), [1, 1]));
}

main();
