/*

Write the given four-digit natural number, omitting the two middle digits.

Input
The input consists of a single line containing a four-digit natural number n.

Output
Output the resulting number.

Examples
Input #1
1023

Answer #1
13

*/

function solve(n) {
	return (n % 10) + 10*(Math.floor(n / 1000) % 10);
}

console.log(solve(1023));

