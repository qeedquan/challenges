/*

Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.

Example 1:
https://assets.leetcode.com/uploads/2021/08/10/even1-tree.jpg
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

Example 2:
https://assets.leetcode.com/uploads/2021/08/10/even2-tree.jpg
Input: root = [1]
Output: 0

Constraints:

The number of nodes in the tree is in the range [1, 10^4].
1 <= Node.val <= 100

Hint 1
Traverse the tree keeping the parent and the grandparent.

Hint 2
If the grandparent of the current node is even-valued, add the value of this node to the answer.

*/

#include <assert.h>

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

int
recurse(Node *n, int p, int gp)
{
	int r;

	if (!n)
		return 0;

	r = recurse(n->left, n->val, p) + recurse(n->right, n->val, p);
	if (gp % 2 == 0)
		r += n->val;
	return r;
}

int
sum(Node *n)
{
	return recurse(n, 1, 1);
}

int
main()
{
	Node *t1 = &(Node){
		.val = 6,
		.left = &(Node){
		    .val = 7,
		    .left = &(Node){
		        .val = 2,
		        .left = &(Node){
		            .val = 9,
		        },
		    },
		    .right = &(Node){
		        .val = 7,
		        .left = &(Node){
		            .val = 1,
		        },
		        .right = &(Node){
		            .val = 4,
		        },
		    },
		},
		.right = &(Node){
		    .val = 8,
		    .left = &(Node){
		        .val = 1,
		    },
		    .right = &(Node){
		        .val = 3,
		        .right = &(Node){
		            .val = 5,
		        },
		    },
		},
	};

	Node *t2 = &(Node){
		.val = 1,
	};

	assert(sum(t1) == 18);
	assert(sum(t2) == 0);

	return 0;
}
