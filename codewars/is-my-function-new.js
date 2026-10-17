/*

Write a function that returns whether it was called with the new operator.

The function must return a Boolean, but due to the way new works, valueOf() will be called on your returned value before strict comparison to true/false.

Examples:

wasCalledWithNew().valueOf();        // false
(new wasCalledWithNew).valueOf();    // true
wasCalledWithNew.call({}).valueOf(); // false

*/

var assert = require('assert');

function wasCalledWithNew() {
	return new Boolean(new.target);
}

assert(wasCalledWithNew().valueOf() == false);
assert((new wasCalledWithNew).valueOf() == true);
assert(wasCalledWithNew.call({}).valueOf() == false);

