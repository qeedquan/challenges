/*

In the express lottery draw, N tickets were printed, each uniquely numbered from 1 to N.
However, when the winning number was drawn, it was discovered that the ticket with that number was missing.
Given the total number of tickets and the list of all available numbers, identify the missing number.

Input
The first line contains a non-negative integer N, where 1≤N≤10^6.
The second line lists N−1 distinct natural numbers, each not exceeding N.

Output
The missing number.

Examples

Input #1
5
1 5 4 2

Answer #1
3

*/

function triangular(n) {
	return Math.floor(n * (n + 1) / 2);
}

function solve(x) {
	let n = x.length + 1;
	let s = triangular(n);
	for (i = 0; i < n - 1; i++) {
		s -= x[i];
	}
	return s;
}

console.log(solve([1, 5, 4, 2]));
