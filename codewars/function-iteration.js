/*

The purpose of this kata is to write a higher-order function returning a new function that iterates on a specified function a given number of times. This new function takes in an argument as a seed to start the computation from.

For instance, consider the function getDouble. When run twice on value 3, yields 12 as shown below.

getDouble(3) => 6
getDouble(6) => 12

Let us name the new function createIterator and we should be able to obtain the same result using createIterator as shown below:

var doubleIterator = createIterator(getDouble, 2); // This means, it runs *getDouble* twice
doubleIterator(3) => 12

For the sake of simplicity, all function inputs to createIterator would be functions returning a small number and number of iterations would always be integers.

*/

var assert = require('assert');

function iterator(f, n) {
	return function(m) {
		let r = m;
		for (i = 0; i < n; i++)
			r = f(r);
		return r;
	}
}

function twice(x) {
	return x + x;
}

function main() {
	let twiceIterator = iterator(twice, 1);
	assert(twiceIterator(3) == 6);
	assert(twiceIterator(5) == 10);

	let quadrupleIterator = iterator(twice, 2);
	assert(quadrupleIterator(2) == 8);
	assert(quadrupleIterator(5) == 20);
}

main();
