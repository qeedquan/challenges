/*

A positive integer n is given.
Perform the following operation: subtract the sum of the digits of n from n.
Repeat this operation with the new result as long as the number remains positive.
Determine how many times this operation can be performed before the result becomes zero or negative.

Input
A single integer n (0<n≤2⋅10^9).

Output
Print the number of times the operation is performed.

Examples
Input #1
21

Answer #1
3

*/

var assert = require('assert');

function digsum(n) {
	let r = 0;
	while (n > 0) {
		r += n % 10;
		n = Math.floor(n / 10);
	}
	return r;
}

function solve(n) {
	let c = 0;
	while (n > 0) {
		n -= digsum(n);
		c += 1;
	}
	return c;
}

let tab = [
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10,
	10, 10, 10, 10, 10, 10, 11
];


assert(solve(21) == 3);
for (let i = 0; i < tab.length; i++) {
	assert(solve(i) == tab[i]);
}
