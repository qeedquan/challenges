/*

You are given an array of documents (strings), a term (string), and two booleans finetuning your indexing operation. Return an array containing the document IDs (1-based indices of documents in the array), where the term occurs, sorted in ascending order.

Booleans:

CaseSensitive: test matches test, but not Test
Not CaseSensitive: test matches both test and Test

Exact Match: test matches test and .test!, but not attest or test42
Not Exact Match: test matches both test and attest

Example:
buildInvertedIndex(["Sign", "sign", "Signature", "Sign-ature"], "Sign", true, true)

return [1,4]

*/

var assert = require('assert');

function assertEqual(result, expected) {
	assert(result.length == expected.length);
	for (index = 0; index < result.length; index++)
		assert(result[index] == expected[index]);
}

function buildInvertedIndex(collection, term, caseSensitive, exactMatch) {
	let pattern = term;
	let flags = '';
	if (exactMatch)
		pattern = '\\b' + pattern + '\\b';
	if (!caseSensitive)
		flags = 'i';

	let regex = new RegExp(pattern, flags);
	let result = [];
	for (let index = 0; index < collection.length; index++) {
		let value = collection[index];
		if (regex.test(value))
			result.push(index + 1);
	}
	return result;
}

assertEqual(buildInvertedIndex(['hello there', 'general kenobi'], 'hello', true, false), [1]);
assertEqual(buildInvertedIndex(['Hello there', 'general kenobi'], 'hello', true, false), []);
assertEqual(buildInvertedIndex(['hello there', 'general kenobi'], 'kenobi', true, false), [2]);
assertEqual(buildInvertedIndex(['hello there', 'gEnErAl kenobi'], 'general', true, false), []);
assertEqual(buildInvertedIndex(['Lorem Ipsum Dolor', 'Hodor Dolor Hodor', 'Dolormiten are not a thing'],'Dolor', true, false), [1, 2, 3]);
assertEqual(buildInvertedIndex(['Lorem Ipsum Dolor', 'Hodor Dolor Hodor', 'Dolormiten are not a thing'],'holor', true, false), []);
assertEqual(buildInvertedIndex(["Sign", "sign", "Signature", "Sign-ature"], "Sign", true, true), [1, 4]);

assertEqual(buildInvertedIndex(['hello there', 'general kenobi'], 'Hello', false, false), [1]);
assertEqual(buildInvertedIndex(['Rumpel Dumpel','Holger', 'Quadrumpel'], 'UmPeL', false, false), [1, 3]);

assertEqual(buildInvertedIndex(['!hellos there', 'general kenobi'],'Hello', false, true), []);
assertEqual(buildInvertedIndex(['hello there', 'general kenobi'], 'Hell', false, true), []);
assertEqual(buildInvertedIndex(['hello. there', 'general kenobi'], 'hello', true, true), [1]);
assertEqual(buildInvertedIndex(['Im Wald gibts nicht viel zu tun', 'Oooh du schoener Westerwald'], 'wald', false, true), [1]);

assertEqual(buildInvertedIndex(['hellos there', 'general kenobi'], 'Hello', false, false), [1]);
assertEqual(buildInvertedIndex(['hello there', 'general kenobi'], 'Hello', true, false), []);
assertEqual(buildInvertedIndex(['hello there', 'general kenobi'], 'Hell', false, false), [1]);

