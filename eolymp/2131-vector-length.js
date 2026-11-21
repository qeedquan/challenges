/*

Find the length of a vector.

Input
Four integers x1, y1, x2, y2— the coordinates of the beginning and end of the vector, respectively.
All input values do not exceed 10000 by absolute value.

Output
Print the length of the vector with 6 digits after the decimal point.

Examples
Input #1
1 1 2 2

Answer #1
1.414214

*/

function length(x1, y1, x2, y2) {
	let dx = x2 - x1;
	let dy = y2 - y1;
	return Math.sqrt(dx*dx + dy*dy);
}

console.log(length(1, 1, 2, 2));

