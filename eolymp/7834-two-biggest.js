/*

Array of n integers is given. Find the sum of two biggest elements in array.

Input
First line contains number n (n≤100). Next line contains n integers, each of them is no more than 100 by absolute value.

Output
Print the sum of two biggest elements in array.

Examples

Input #1
5
1 5 2 6 3

Answer #1
11

Input #12
5
-1 -2 -3 -4 -5

Answer #12
-3

*/

function solve(array) {
	let length = array.length;
	if (length < 2)
		return 0;

	array.sort((a, b) => a - b);
	return array[length - 1] + array[length - 2];
}

console.log(solve([1, 5, 2, 6, 3]));
console.log(solve([-1, -2, -3, -4, -5]));
