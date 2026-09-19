/*

Given two positive integers a and b. Check if a is divisible by b without a remainder.

Input
Two positive integers a and b (1≤a,b≤10^9)

Output
If a is not divisible by b, print two numbers in a single line: the quotient and the remainder of a divided by b. If a is divisible by b, print the string "Divisible".

Examples

Input #1
12 5

Answer #1
2 2

Input #2
15 3

Answer #2
Divisible

*/

function solve(a, b) {
	if (a%b == 0)
		return "Divisible";
	return [Math.floor(a / b), a % b];
}

console.log(solve(12, 5));
console.log(solve(15, 3));

