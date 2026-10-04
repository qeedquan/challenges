/*

In a binary tree, a lonely node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.

Given the root of a binary tree, return an array containing the values of all lonely nodes in the tree. Return the list in any order.

Example 1:


Input: root = [1,2,3,null,4]
Output: [4]
Explanation: Light blue node is the only lonely node.
Node 1 is the root and is not lonely.
Nodes 2 and 3 have the same parent and are not lonely.
Example 2:


Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
Output: [6,2]
Explanation: Light blue nodes are lonely nodes.
Please remember that order doesn't matter, [2,6] is also an acceptable answer.
Example 3:

Input: root = [11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]
Output: [77,55,33,66,44,22]
Explanation: Nodes 99 and 88 share the same parent. Node 11 is the root.
All other nodes are lonely.
Example 4:

Input: root = [197]
Output: []
Example 5:

Input: root = [31,null,78,null,28]
Output: [78,28]


Constraints:

The number of nodes in the tree is in the range [1, 1000].
Each node's value is between [1, 10^6].

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

void
dump(int *a, size_t n)
{
	size_t i;

	printf("[ ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("]\n");
}

void
recurse(Node *t, int *p, size_t *n)
{
	Node *l, *r;

	if (t == NULL)
		return;

	l = t->left;
	r = t->right;
	if (l && !r)
		p[(*n)++] = l->val;
	else if (!l && r)
		p[(*n)++] = r->val;

	recurse(l, p, n);
	recurse(r, p, n);
}

size_t
lonely(Node *t, int *p)
{
	size_t n;

	n = 0;
	recurse(t, p, &n);
	return n;
}

void
test(Node *t, int *r, size_t nr)
{
	int p[128];
	size_t np;

	np = lonely(t, p);
	dump(p, np);
	assert(np == nr);
	if (nr)
		assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	Node *t1 = &(Node){
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
	int r1[] = {4};

	Node *t2 = &(Node){
	    .val = 7,
	    .left = &(Node){
	        .val = 1,
	        .left = &(Node){
	            .val = 6,
	        },
	    },
	    .right = &(Node){
	        .val = 4,
	        .left = &(Node){
	            .val = 5,
	        },
	        .right = &(Node){
	            .val = 3,
	            .right = &(Node){
	                .val = 2,
	            },
	        },
	    },
	};
	int r2[] = {6, 2};

	Node *t3 = &(Node){
	    .val = 11,
	    .left = &(Node){
	        .val = 99,
	        .left = &(Node){
	            .val = 77,
	            .left = &(Node){
	                .val = 55,
	                .left = &(Node){
	                    .val = 33,
	                },
	            },
	        },
	    },
	    .right = &(Node){
	        .val = 88,
	        .right = &(Node){
	            .val = 66,
	            .right = &(Node){
	                .val = 44,
	                .right = &(Node){
	                    .val = 22,
	                },
	            },
	        },
	    },
	};
	int r3[] = {77, 55, 33, 66, 44, 22};

	Node *t4 = &(Node){
	    .val = 197,
	};

	Node *t5 = &(Node){
	    .val = 31,
	    .right = &(Node){
	        .val = 78,
	        .right = &(Node){
	            .val = 28,
	        },
	    },
	};
	int r5[] = {78, 28};

	test(t1, r1, nelem(r1));
	test(t2, r2, nelem(r2));
	test(t3, r3, nelem(r3));
	test(t4, NULL, 0);
	test(t5, r5, nelem(r5));

	return 0;
}
