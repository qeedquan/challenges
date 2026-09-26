/*

The radius of a circle r is given. Find the circumference and the area of a circle.

Input
The radius of a circle r is a real number (r>0).

Output
Print in one line the circumference and the area of a circle with 4 decimal digits.

Examples

Input #1
1.234

Answer #1
7.7535 4.7839

*/

function solve(r) {
	return [2*Math.PI*r, Math.PI*r*r];
}

console.log(solve(1.234));
