/*

You are given an array a consisting of n (n≥3) positive integers. It is known that in this array, all the numbers except one are the same (for example, in the array [4,11,4,4] all numbers except one are equal to 4).

Print the index of the element that does not equal others. The numbers in the array are numbered from one.

Input
The first line contains a single integer t (1≤t≤100). Then t test cases follow.

The first line of each test case contains a single integer n (3≤n≤100) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100).

It is guaranteed that all the numbers except one in the a array are the same.

Output
For each test case, output a single integer — the index of the element that is not equal to others.

Example

input
4
4
11 13 11 11
5
1 4 4 4 4
10
3 3 3 3 10 3 3 3 3 3
3
20 20 10

output
2
1
5
3

*/

var assert = require('assert');

function single(a) {
	var m = new Map();
	var p = new Map();
	for (var i = 0; i < a.length; i++) {
		if (!m.has(a[i])) {
			m.set(a[i], 0);
			p.set(a[i], i + 1);
		}
		m.set(a[i], m.get(a[i]) + 1);
	}

	var r = 0;
	m.forEach(function(v, k, _) {
		if (v == 1)
			r = p.get(k);
	})
	return r;
}

function main() {
	assert(single([11, 13, 11, 11]) == 2);
	assert(single([1, 4, 4, 4, 4]) == 1);
	assert(single([3, 3, 3, 3, 10, 3, 3, 3, 3, 3]) == 5);
	assert(single([20, 20, 10]) == 3);
}

main();
