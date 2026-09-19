/*

An ATM has an unlimited number of banknotes with denominations 10,20,50,100,200, and 500.
Given an integer n, determine the minimum number of banknotes required to obtain exactly n units.
If it is not possible to obtain the exact amount, print −1.

Input
The input contains a single integer n (1≤n≤10^6).

Output
Output the minimum number of banknotes required to obtain exactly n units.
If it is not possible, print −1.

Examples
For example, the amount 770 can be obtained as: 500+200+50+20.

Input #1
770

Answer #1
4

*/

var assert = require('assert');

function solve(n) {
	let coins = [500, 200, 100, 50, 20, 10];
	
	let r = 0;
	for (let i = 0; n > 0 && i < coins.length; i++) {
		let d = Math.floor(n / coins[i]);
		n -= d * coins[i];
		r += d;
	}
	if (n > 0)
		return -1;
	return r;
}

assert(solve(770) == 4);
