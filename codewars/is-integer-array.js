/*

Write a function with the signature shown below:

function isIntArray(arr) {
  return true
}
returns true / True if every element in an array is an integer or a float with no decimals.
returns true / True if array is empty.
returns false / False for every other input.

*/

function isIntArray(array) {
	if (!Array.isArray(array))
		return false;

	let filtered = array.filter(element => parseInt(element) != element);
	return filtered.length == 0;
}

console.log(isIntArray([1, 2, 3, 4]));
console.log(isIntArray([]));
console.log(isIntArray(['x', 'y', 12, "D"]));
console.log(isIntArray([[]]));
