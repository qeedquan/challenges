/*

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

Constraints:

    The number of nodes in the root tree is in the range [1, 2000].
    The number of nodes in the subRoot tree is in the range [1, 1000].
    -10^4 <= root.val <= 10^4
    -10^4 <= subRoot.val <= 10^4

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
identical(Node *a, Node *b)
{
	if (!a && !b)
		return true;

	if ((a && !b) || (!a && b))
		return false;

	return (a->val == b->val) && identical(a->left, b->left) && identical(a->right, b->right);
}

bool
subtree(Node *a, Node *b)
{
	return identical(a, b) || identical(a->left, b) || identical(a->right, b);
}

int
main(void)
{
	Node *a1 = &(Node){
	    .val = 3,
	    .left = &(Node){
	        .val = 4,
	        .left = &(Node){
	            .val = 1,
	        },
	        .right = &(Node){
	            .val = 2,
	        },
	    },
	    .right = &(Node){
	        .val = 5,
	    },
	};

	Node *b1 = &(Node){
	    .val = 4,
	    .left = &(Node){
	        .val = 1,
	    },
	    .right = &(Node){
	        .val = 2,
	    },
	};

	Node *a2 = &(Node){
	    .val = 3,
	    .left = &(Node){
	        .val = 4,
	        .left = &(Node){
	            .val = 1,
	        },
	        .right = &(Node){
	            .val = 2,
	            .left = &(Node){
	                .val = 0,
	            },
	        },
	    },
	    .right = &(Node){
	        .val = 5,
	    },
	};

	assert(subtree(a1, b1) == true);
	assert(subtree(a2, b1) == false);
	assert(subtree(a1, a1) == true);
	assert(subtree(a2, a2) == true);
	assert(subtree(b1, b1) == true);

	return 0;
}
