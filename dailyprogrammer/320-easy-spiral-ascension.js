/*

Description
The user enters a number. Make a spiral that begins with 1 and starts from the top left, going towards the right, and ends with the square of that number.

Input description
Let the user enter a number.

Output description
Note the proper spacing in the below example. You'll need to know the number of digits in the biggest number.

You may go for a CLI version or GUI version.

Challenge Input
5
4

Challenge Output
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

 1  2  3  4 
12 13 14  5
11 16 15  6
10  9  8  7

Bonus
As a bonus, the code could take a parameter and make a clockwise or counter-clockwise spiral.

Credit
This challenge was suggested by u/MasterAgent47 (with a bonus suggested by u/JakDrako), many thanks to them both. If you would like, submit to r/dailyprogrammer_ideas if you have any challenge ideas!

*/

function floor(x) {
	if (x < 0)
		return Math.ceil(x);
	return Math.floor(x);
}

function spiralindex(x, y) {
	let z = x;
	let s = 1;
	if (y*y >= x*x) {
		z = y;
		s = -1;
	}

	let p = 4*z*z - y - x;
	if (y < x)
		p += 2*s*(y - x);
	return p;
}

// https://stackoverflow.com/questions/9970134/get-spiral-index-from-location/9971465#9971465
function spiral(n) {
	if (n & 1) {
		var sx = floor(n / 2);
		var ex = floor((1 - n) / 2) - 1;
		var dx = -1;
		var sy = floor((1 - n) / 2);
		var ey = floor(n / 2) + 1;
		var dy = 1;
	} else {
		var sx = floor((1 - n) / 2);
		var ex = floor(n / 2) + 1;
		var dx = 1;
		var sy = floor(n / 2);
		var ey = floor((1 - n) / 2) - 1;
		var dy = -1;
	}

	console.log("n=" + n);
	for (let y = sy; y != ey; y += dy) {
		for (let x = sx; x != ex; x += dx) {
			process.stdout.write(n*n - spiralindex(x, y) + " ");
		}
		console.log();
	}
	console.log();
}

function main() {
	for (let i = 1; i <= 10; i++)
		spiral(i);
}

main();
