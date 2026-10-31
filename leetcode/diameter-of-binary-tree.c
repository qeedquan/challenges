/*

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [1, 10^4].
    -100 <= Node.val <= 100

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

int
traverse(Node *n, int *d)
{
	int l, r;

	if (!n)
		return -1;

	l = traverse(n->left, d) + 1;
	r = traverse(n->right, d) + 1;
	*d = max(*d, l + r);
	return max(l, r);
}

int
diameter(Node *n)
{
	int d;

	d = 0;
	traverse(n, &d);
	return d;
}

int
main(void)
{
	Node *t1 = &(Node){
	    .val = 1,
	    .left = &(Node){
	        .val = 2,
	        .left = &(Node){
	            .val = 4,
	        },
	        .right = &(Node){
	            .val = 5,
	        },
	    },
	    .right = &(Node){
	        .val = 3,
	    },
	};

	Node *t2 = &(Node){
	    .val = 1,
	    .right = &(Node){
	        .val = 2,
	    },
	};

	assert(diameter(t1) == 3);
	assert(diameter(t2) == 1);

	return 0;
}
