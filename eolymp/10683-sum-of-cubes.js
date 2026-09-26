/*

Given positive integer n. Find the sum 1^3+2^3+3^3+…+n^3.

Input
One positive integer n (1≤n≤10000).

Output
Print the value of the sum.

Examples

Input #1
2

Answer #1
9

*/

var assert = require('assert');

// https://oeis.org/A000537
function solve(n) {
	return Math.floor(n*n*(n+1)*(n+1)/4);
}

var tab = [
	0, 1, 9, 36, 100, 225, 441, 784, 1296, 2025, 3025, 4356, 6084, 8281,
	11025, 14400, 18496, 23409, 29241, 36100, 44100, 53361, 64009, 76176,
	90000, 105625, 123201, 142884, 164836, 189225, 216225, 246016, 278784,
	314721, 354025, 396900, 443556, 494209, 549081
];

assert(solve(2) == 9);

for (let i = 0; i < tab.length; i++)
	assert(solve(i) == tab[i]);
