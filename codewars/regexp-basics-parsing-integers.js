/*

Implement a function/class, which should return an integer if the input string is in one of the formats specified below, or null/nil/None otherwise.

Format:

Optional - or +
Base prefix 0b (binary), 0x (hexadecimal), 0o (octal), or in case of no prefix decimal.
Digits depending on base
Any extra character (including whitespace) makes the input invalid, in which case you should return null/nil/None.

Digits are case insensitive, but base prefix must be lower case.

See the test cases for examples.

*/

String.prototype.toInteger = function () {
	let match = this.match(/^([-+])?(0b[01]+|0x[0-9A-Fa-f]+|0o[0-7]+|\d+)$/);
	if (!match)
		return null;
	return `${match[1] || 0}1` * match[2];
};

console.log("0b101".toInteger());
console.log("0x7f".toInteger());
console.log("-32525".toInteger());
console.log("0o10".toInteger());
