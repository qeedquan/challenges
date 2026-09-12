/*

The program takes three integers a, b and c as input, provided in a single line and separated by spaces. Your task is to sort these numbers in ascending order and display them.

Input
You will receive one line containing three integers a, b, and c separated by spaces.

Output
Print the three integers in ascending order.

Examples
Input #1
7 2 4

Answer #1
2 4 7

*/

function solve(a, b, c) {
	if (a > b)
		[a, b] = [b, a];
	if (b > c)
		[b, c] = [c, b];
	if (a > b)
		[a, b] = [a, b];
	return [a, b, c];
}

console.log(solve(7, 2, 4));

