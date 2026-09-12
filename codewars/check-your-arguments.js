/*

Bob has written a function to detect the type of an object. It receives any primitive values or objects, and returns its object type as a string.
But it seems to be working incorrectly. Can you figure out why, and fix the code for him?

*/

function objectType(...args) {
	return Object.prototype.toString.call(args.length ? args[0] : null);
}

console.log(objectType(Object(2)));
console.log(objectType(Object("XYZ")));
