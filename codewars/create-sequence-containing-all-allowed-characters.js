/*

Define createSequence(regex) function that returns a string of all characters (in ASCII order) matching specified regular expression one-character criterion.

Examples
let digits = /[0-9]/;
// createSequence(digits) === '0123456789'

let hexadecimal = /[0-9A-F]/;
// createSequence(hexadecimal) === '0123456789ABCDEF'

*/

function createSequence(regex) {
	let sequence = [];
	for (let code = 32; code < 127; code++) {
		let string = String.fromCharCode(code);
		if (regex.test(string))
			sequence.push(string);
	}
	return sequence.join('');
}

let digits = /[0-9]/;
let hexadecimal = /[0-9A-F]/;

console.log(createSequence(digits));
console.log(createSequence(hexadecimal));

