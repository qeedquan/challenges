/*

Challenge
Given an ASCII operator from the list below and a number n, draw an ASCII representation of the operator using that operator as the character with the line segments of the operator having length n.

Input
An ASCII character from the list = + - x / and an integer n where n >= 1. (I'm using x instead of * and / instead of ÷, but you could use either one, whichever is easier). For + and x, you only have to handle odd numbers to avoid issues with alignment.

Output
An ASCII drawing of the operator composed of the character with segments of length n. Horizontal portions should have spaces between the characters to offset vertical/horizontal distance differences.

Rules
This is code-golf, so shortest code in bytes wins. Standard loopholes are forbidden.

Examples
Input: + 3

  +
+ + +
  +
Input: = 4

= = = =
= = = =
Input: = 10

= = = = = = = = = =
= = = = = = = = = =
Input: - 2

- -
Input: / 10

         /
        /
       /
      /
     /
    /
   /
  /
 /
/
Input: x 7

x     x
 x   x
  x x
   x
  x x
 x   x
x     x

*/

function paint(f, w, h) {
	for (let y = 0; y < h; y++) {
		for (let x = 0; x < w; x++) {
			process.stdout.write(f(x, y, w, h));
		}
		console.log();
	}
	console.log();
}

function cross(x, y, w, h) {
	let c = ' ';
	if (x == Math.floor(w/2))
		c = '+';
	else if (y == Math.floor(h/2) && !(x & 1))
		c = '+';
	return c;
}

function horizontal(op) {
	return function(x, y, w, h) {
		return (x & 1) ? ' ' : op;
	}
}

function diagonal(x, y, w, h) {
	return (x == h-y-1) ? '/' : ' ';
}

function saltire(x, y, w, h) {
	return (x == y || x == h-y-1) ? 'x' : ' ';
}

function operator(op, n) {
	console.log(op, n);
	switch (op) {
	case '=':
		paint(horizontal(op), n*2, 2);
		break;
	case '+':
		paint(cross, 2*n - 1, n);
		break;
	case '-':
		paint(horizontal(op), n*2, 1);
		break;
	case 'x':
		paint(saltire, n, n);
		break;
	case '/':
		paint(diagonal, n, n);
		break;
	}
}

function main() {
	operator('+', 3);
	operator('=', 4);
	operator('=', 10);
	operator('-', 2);
	operator('/', 10);
	operator('x', 7);
}

main();
