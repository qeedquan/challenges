/*

Create a function to return true type of variable, i.e.

type([]) == 'array'
type({}) == 'object'
type('') == 'string'
type(NaN) == 'number'

*/

var assert = require('assert');

function type(value) {
	if (value === null)
		return "null";
	if (value === undefined)
		return "undefined";
	return value.constructor.name.toLowerCase();
}

assert(type([]) == 'array');
assert(type({}) == 'object');
assert(type('') == 'string');
assert(type(NaN) == 'number');
