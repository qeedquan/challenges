/*

In how many ways can you choose k elements out of n elements, not taking order into account?
Write a program to compute this number.

Input
The input file will contain one or more test cases.
Each test case consists of one line containing two integers n (n ≥ 1) and k (0 ≤ k ≤ n).
Input is terminated by two zeroes for n and k.

Output
For each test case, print one line containing the required number. This number will always fit into an
integer, i.e. it will be less than 2^31.
Warning: Don’t underestimate the problem. The result will fit into an integer — but if all intermediate
results arising during the computation will also fit into an integer depends on your algorithm. The test
cases will go to the limit.

Sample Input
4 2
10 5
49 6
0 0

Sample Output
6
252
13983816

*/

function binomial(n: number, k: number): number {
	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	let r = 1;
	for (let i = 0; i < k; i++)
		r = r * (n - i) / (i + 1);
	return r;
}

console.log(binomial(4, 2));
console.log(binomial(10, 5));
console.log(binomial(49, 6));

