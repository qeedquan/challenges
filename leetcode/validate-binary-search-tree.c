/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1

*/

#include <assert.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

bool
validbst(Node *n)
{
	Node *l, *r;

	if (!n)
		return true;

	l = n->left;
	r = n->right;
	if (l && l->val >= n->val)
		return false;
	if (r && r->val <= n->val)
		return false;
	return validbst(l) && validbst(r);
}

int
main(void)
{
	Node *t1 = &(Node){
	    .val = 2,
	    .left = &(Node){
	        .val = 1,
	    },
	    .right = &(Node){
	        .val = 3,
	    },
	};

	Node *t2 = &(Node){
	    .val = 5,
	    .left = &(Node){
	        .val = 1,
	    },
	    .right = &(Node){
	        .val = 4,
	        .left = &(Node){
	            .val = 3,
	        },
	        .right = &(Node){
	            .val = 6,
	        },
	    },
	};

	assert(validbst(t1) == true);
	assert(validbst(t2) == false);

	return 0;
}
