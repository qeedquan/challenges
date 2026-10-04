/*

Given a binary tree, determine if it is height-balanced.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true

Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -10^4 <= Node.val <= 10^4

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

int
height(Node *n)
{
	int l, r;

	if (!n)
		return 0;

	l = height(n->left);
	if (l < 0)
		return -1;

	r = height(n->right);
	if (r < 0)
		return -1;

	if (abs(l - r) > 1)
		return -1;

	return max(l, r) + 1;
}

bool
balanced(Node *n)
{
	return height(n) >= 0;
}

int
main(void)
{
	Node *t1 = &(Node){
	    .val = 3,
	    .left = &(Node){
	        .val = 9,
	    },
	    .right = &(Node){
	        .val = 20,
	        .left = &(Node){
	            .val = 15,
	        },
	        .right = &(Node){
	            .val = 7,
	        },
	    },
	};

	Node *t2 = &(Node){
	    .val = 1,
	    .left = &(Node){
	        .val = 2,
	        .left = &(Node){
	            .val = 3,
	            .left = &(Node){
	                .val = 4,
	            },
	            .right = &(Node){
	                .val = 4,
	            },
	        },
	        .right = &(Node){
	            .val = 3,
	        },
	    },
	    .right = &(Node){
	        .val = 2,
	    },
	};

	assert(balanced(t1) == true);
	assert(balanced(t2) == false);
	assert(balanced(NULL) == true);

	return 0;
}
