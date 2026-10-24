/*

Create a function to lowercase all strings in an array. Non-string items should remain unchanged.

Example
arrayLowerCase(['Red', 'Green']) == ['red', 'green']
arrayLowerCase([1, 'Green']) == [1, 'green']

*/

function arrayLowerCase(array) {
	return array.map((element) => (typeof element === 'string' ? element.toLowerCase() : element));
}

console.log(arrayLowerCase(['Red', 'Green']));
console.log(arrayLowerCase([1, 'Green']));
