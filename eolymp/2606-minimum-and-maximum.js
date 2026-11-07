/*

Find the minimum and maximum of two positive integers.

Input
Two positive integers a and b (a,b≤10^9).

Output
Print in one line the smaller of the two numbers a and b, followed by the larger one.

Examples

Input #1
4 2

Answer #1
2 4

Input #2
10 100

Answer #2
10 100

*/

function solve(a, b) {
	if (a > b)
		[a, b] = [b, a];
	return [a, b];
}

console.log(solve(4, 2));
console.log(solve(10, 100));
