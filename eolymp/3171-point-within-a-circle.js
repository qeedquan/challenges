/*

Check if the point is inside the circle.

Input
The first line contains the coordinates of the circle's center and its radius: x, y, r.
The second line contains the coordinates of point A: xa, ya.
All numbers are integers whose absolute values do not exceed 10000.

Output
Print YES if point A belongs to the circle (including the boundary), and NO otherwise.

Examples

Input #1
2 1 2
1 3

Answer #1
NO

*/

function solve(a, b, r, x, y) {
	let v = Math.sqrt((x-a)*(x-a) + (y-b)*(y-b));
	if (v > r)
		return "NO";
	return "YES";
}

console.log(solve(2, 1, 2, 1, 3));
