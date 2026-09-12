/*

Write a function that appends the items from sequence 2 onto sequence 1, returning the newly formed sequence. Your function should also be able to handle nested sequences.

All inputs will be arrays/nested arrays.

For example:

['a','b','c'], [1,2,3]     --> ['a','b','c',1,2,3]
[['x','x'],'B'], ['c','D'] --> [['x','x'],'B','c','D']

*/

function appendArrays(array1, array2) {
	return [...array1, ...array2];
}

function main() {
	console.log(appendArrays(['a', 'b', 'c'], [1, 2, 3]));
	console.log(appendArrays([['x', 'x'], 'B'], ['c', 'D']));
}

main();
