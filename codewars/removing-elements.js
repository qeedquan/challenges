/*

Take an array and remove every second element from the array. Always keep the first element and start removing with the next element.

Example:

["Keep", "Remove", "Keep", "Remove", "Keep", ...] --> ["Keep", "Keep", "Keep", ...]
None of the arrays will be empty, so you don't have to worry about that!

*/

function removeEveryOther(array) {
	return array.filter((_, index) => !(index % 2));
}

console.log(removeEveryOther(["Keep", "Remove", "Keep", "Remove", "Keep"]));

