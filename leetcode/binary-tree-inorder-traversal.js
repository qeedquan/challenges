/*

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?

*/

var assert = require('assert');

class Node {
	constructor(val, left=null, right=null) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

function equals(a, b) {
	if (!Array.isArray(a) || !Array.isArray(b))
		return false;
	if (a.length != b.length)
		return false;
	return a.every((v, i) => v === b[i]);
}

function inorder(n) {
	if (n == null)
		return [];

	var r = [];
	var x = inorder(n.left);
	var y = inorder(n.right);
	if (x != null)
		r.push(x);
	r.push(n.val);
	if (y != null)
		r.push(y);
	return r.flat();
}

function main() {
	t1 = new Node(1, null, new Node(2, new Node(3)));
	t2 = null;
	t3 = new Node(1);

	assert(equals(inorder(t1), [1, 3, 2]));
	assert(equals(inorder(t2), []));
	assert(equals(inorder(t3), [1]));
}

main();
