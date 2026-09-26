/*

Task
Heading off to the Tree Arboretum of Various Heights, I bring along my camera to snap up a few photos. Ideally, I'd want to take a picture of as many trees as possible, but the taller trees may cover up the shorter trees behind it.

A tree is hidden if it is shorter than or the same height as a ( any ) tree in front of it, as seen in a particular direction.

Given a list of tree heights, create a function which returns "left" or "right", depending on which side allows me to see as many trees as possible.

Worked Example
[1, 3, 1, 6, 5] ➞ "left"
// If I stand on the left, I can see trees of heights 1, 3 and 6.
// If I stand on the right, I can see trees of heights 5 and 6.
// Return "left" because I would see more trees.
Examples
[5, 6, 5, 4] ➞ "right"

[1, 2, 3, 3, 3, 3, 3] ➞ "left"

[3, 1, 4, 1, 5, 9, 2, 6] ➞ "left"

Notes
There will always be a best side.

*/

var assert = require('assert');

function trees(a) {
	let L = R = 0;
	let l = r = 0;
	let n = a.length;
	for (let i = 0; i < n; i++) {
		if (a[i] > L) {
			L = a[i];
			l += 1;
		}
		if (a[n - i - 1] > R) {
			R = a[n - i - 1];
			r += 1;
		}
	}
	return (l > r) ? "left" : "right";
}

assert(trees([1, 3, 1, 6, 5]) == "left");
assert(trees([5, 6, 5, 4]) == "right");
assert(trees([1, 2, 3, 3, 3, 3, 3]) == "left");
assert(trees([3, 1, 4, 1, 5, 9, 2, 6]) == "left");
