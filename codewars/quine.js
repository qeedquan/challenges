/*

Just write quine function.

https://en.wikipedia.org/wiki/Quine_(computing)

*/

function quine() {
	return quine.toString();
}

console.log(quine());
