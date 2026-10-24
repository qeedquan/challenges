/*

Write a function that takes a list of at least four elements as an argument and returns a list of the middle two or three elements in reverse order.

*/

function reverseMiddle(array) {
	let midpoint = Math.floor(array.length / 2);
	let slice = array.slice(midpoint - 1, midpoint + 1 + (array.length % 2));
	return slice.reverse();
}

console.log(reverseMiddle([1, 2, 3, 4]));
console.log(reverseMiddle([1, 2, 3, 4, 5]));
console.log(reverseMiddle([1, 2, 3, 4, 5, 6]));
console.log(reverseMiddle([1, 2, 3, 4, 5, 6, 7]));
console.log(reverseMiddle([]));
