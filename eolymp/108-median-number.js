/*

Three integers a, b, c are given, each of which satisfies ∣a∣,∣b∣,∣c∣≤1000.

Input
Three integers a, b, c are given, each of which satisfies ∣a∣,∣b∣,∣c∣≤1000.

Output
Print the median among the three numbers.

Examples

Input #8
0 999 77

Answer #8
77

*/

function solve(a, b, c) {
	let x = [a, b, c].sort();
	return x[1];
}

console.log(solve(0, 999, 77));
