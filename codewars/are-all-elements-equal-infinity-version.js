/*

Task
Create a function eqAll that determines if all elements of a list are equal.
list can be any iterable ( https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Iteration_protocols#iterable ), and may be infinite. Return value is a Boolean.

Examples
eqAll("aaa") => true
eqAll("abc") => false
eqAll("")    => true

eqAll([0,0,0]) => true
eqAll([0,1,2]) => false
eqAll([])      => true

Notes
For the function result to be true, the iterable must be finite; false, however, can result from an element finitely far from the left end. There will be no tests with infinite series of equal elements.
Elements will be primitive values; equality should be strict (===).

*/

function eqAll(iterable) {
	const iterator = iterable[Symbol.iterator]();
	const first = iterator.next();

	if (first.done)
		return true;

	const value = first.value;
	let next = null;
	while (!(next = iterator.next()).done) {
		if (next.value !== value)
			return false;
	}
	return true;
}

console.log(eqAll("aaa"));
console.log(eqAll("abc"));
console.log(eqAll(""));

console.log(eqAll([0, 0, 0]));
console.log(eqAll([0, 1, 2]));
console.log(eqAll([]));

