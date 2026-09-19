/*

Given a list of lists containing only 1s and 0s, return a new list that differs from list 1 in its first element, list 2 in its second element, list 3 in its 3rd element, and so on.

cantor([[0,0,0],
        [1,1,1],
        [0,1,0]]) = [1,0,1]

cantor([[1,0,0],
        [0,1,0],
        [0,0,1]]) = [0,0,0]
The nested list will always be perfectly square. Your solution should be a list containing only 1s and 0s.

See Wikipedia for background (if you're interested; it won't help you solve the kata). Obviously this kata is not the same because the lists are not infinite so it doesn't really prove anything -- consider it a tribute...

*/

var assert = require('assert');

function equals(a, b) {
	if (a === b)
		return true;
	if (a == null || b == null)
		return false;
	if (a.length !== b.length)
		return false;

	for (let i = 0; i < a.length; i++) {
		if (a[i] !== b[i])
			return false;
	}
	return true;
}

function cantor(m) {
	let r = [];
	for (let i = 0; i < m.length; i++) {
		r.push(~m[i][i] & 1);
	}
	return r;
}

function main() {
	assert(equals(cantor([[0, 0, 0], [1, 1, 1], [0, 1, 0]]), [1, 0, 1]));
	assert(equals(cantor([[1, 0, 0], [0, 1, 0], [0, 0, 1]]), [0, 0, 0]));
}

main();
