/*

Let's see how good your language of choice is at selective randomness.

Given 4 characters, A, B, C, and D, or a string of 4 characters ABCD as input, output one of the characters with the following probabilities:

A should have a 1/8 (12.5%) chance to be chosen
B should have a 3/8 (37.5%) chance to be chosen
C should have a 2/8 (25%) chance to be chosen
D should have a 2/8 (25%) chance to be chosen
This is in-line with the following Plinko machine layout:

   ^
  ^ ^
 ^ ^ ^
A B \ /
     ^
    C D
Your answer must make a genuine attempt at respecting the probabilities described. A proper explanation of how probabilities are computed in your answer (and why they respect the specs, disregarding pseudo-randomness and big numbers problems) is sufficient.

Scoring
This is code-golf so fewest bytes in each language wins!

*/

function plinko(a, b, c, d) {
	let x = Math.random();
	if (x < 0.125) {
		return a;
	}
	if (x < 0.5) {
		return b;
	}
	if (x < 0.75) {
		return c;
	}
	return d;
}

function sim(n) {
	let h = [0, 0, 0, 0];
	for (let i = 0; i < n; i++) {
		c = plinko(0, 1, 2, 3);
		h[c] += 1;
	}
	console.log(n, h);
}

function main() {
	for (let i = 1; i <= 1e7; i *= 10) {
		sim(i);
	}
}

main();
