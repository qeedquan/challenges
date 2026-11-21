/*

Given the following list of numbers, find the group of sequential positive numbers with the highest sum.

Example input:

12 2 35 -1 20 9 76 5 4 -3 4 -5 19 80 32 -1
Example output:

131
The most succinct code wins.

My approach via Perl is 87 chars (with input as command-line args):

print((sort { $b <=> $a } do { push @s, $_ > 0 ? pop(@s) + $_ : 0 for @ARGV; @s })[0]);

*/

function solve(array) {
	let current = 0;
	let maximum = 0;
	array.forEach((value) => {
		current = (value > 0) ? (current + value) : 0;
		maximum = Math.max(maximum, current);
	})
	return maximum;
}

console.log(solve([12, 2, 35, -1, 20, 9, 76, 5, 4, -3, 4, -5, 19, 80, 32, -1]));

