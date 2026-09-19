/*

This comes from http://programmers.blogoverflow.com/2012/08/20-controversial-programming-opinions/

"Given that Pi can be estimated using the function 4×(1 - 1/3 + 1/5 - 1/7 + ⋯) with more terms giving greater accuracy, write a function that calculates Pi to an accuracy of 5 decimal places."

Note, the estimation must be done by calculating the sequence given above.

*/

function pi() {
	let N = 1_000_000;
	let r = 0;
	for (let i = 1; i <= N; i += 4)
		r += 1/i;
	for (let i = 3; i <= N; i += 4)
		r -= 1/i;
	return 4 * r;
}

function main() {
	console.log(pi().toFixed(5));
}

main();
