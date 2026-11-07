/*

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Example 2:

Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.


Constraints:

The number of nodes in the tree is in the range [1, 25].
1 <= Node.val <= 2^31 - 1
root.val == min(root.left.val, root.right.val) for each internal node of the tree.

*/

#include <assert.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

void
recurse(Node *n, int m[2])
{
	if (!n)
		return;

	if (m[1] < 0 || m[1] >= n->val)
		m[1] = n->val;
	else if (m[0] < 0 || m[0] >= n->val)
		m[0] = n->val;

	recurse(n->left, m);
	recurse(n->right, m);
}

int
min2(Node *n)
{
	int m[2];

	m[0] = m[1] = -1;
	recurse(n, m);
	return m[0];
}

int
main(void)
{
	Node *t1 = &(Node){
	    .val = 2,
	    .left = &(Node){
	        .val = 2,
	    },
	    .right = &(Node){
	        .val = 5,
	        .left = &(Node){
	            .val = 5,
	        },
	        .right = &(Node){
	            .val = 7,
	        },
	    },
	};

	Node *t2 = &(Node){
	    .val = 2,
	    .left = &(Node){
	        .val = 2,
	    },
	    .right = &(Node){
	        .val = 2,
	    },
	};

	assert(min2(t1) == 5);
	assert(min2(t2) == -1);

	return 0;
}
