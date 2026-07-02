/*

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Constraints:

    The number of nodes in the tree is in the range [2, 100].
    1 <= Node.val <= 100
    Each node has a unique value.
    x != y
    x and y are exist in the tree.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
traverse(Node *n, int v, Node **p)
{
	Node *l, *r;

	if (!n)
		return 0;

	l = n->left;
	r = n->right;
	if ((l && l->val == v) || (r && r->val == v)) {
		*p = n;
		return 1;
	}

	return 1 + max(traverse(l, v, p), traverse(r, v, p));
}

bool
cousins(Node *n, int x, int y)
{
	Node *p0, *p1;
	int d0, d1;

	p0 = p1 = NULL;
	d0 = traverse(n, x, &p0);
	d1 = traverse(n, y, &p1);
	return d0 == d1 && p0 != p1;
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
	    },
	    .right = &(Node){
	        .val = 3,
	    },
	};

	Node *t2 = &(Node){
	    .val = 1,
	    .left = &(Node){
	        .val = 2,
	        .right = &(Node){
	            .val = 4,
	        },
	    },
	    .right = &(Node){
	        .val = 3,
	        .right = &(Node){
	            .val = 5,
	        },
	    },
	};

	Node *t3 = &(Node){
	    .val = 1,
	    .left = &(Node){
	        .val = 2,
	        .right = &(Node){
	            .val = 4,
	        },
	    },
	    .right = &(Node){
	        .val = 3,
	    },
	};

	assert(cousins(t1, 4, 3) == false);
	assert(cousins(t2, 5, 4) == true);
	assert(cousins(t3, 2, 3) == false);

	return 0;
}
