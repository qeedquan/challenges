/*

Format any integer provided into a string with "," (commas) in the correct places.

Example:

numberFormat(100000); // return '100,000'
numberFormat(5678545); // return '5,678,545'
numberFormat(-420902); // return '-420,902'

*/

var assert = require('assert');

function numberFormat(number) {
	let intl = Intl.NumberFormat("en-US");
	return intl.format(number);
}

function main() {
	assert(numberFormat(100000) == "100,000");
	assert(numberFormat(5678545) == "5,678,545");
	assert(numberFormat(-420902) == "-420,902");
}

main();
