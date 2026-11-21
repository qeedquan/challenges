/*

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

Example 1:
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Constraints:

The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.

*/

#include <stdio.h>

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

Node *
prune(Node *n)
{
	if (!n)
		return NULL;
	n->left = prune(n->left);
	n->right = prune(n->right);
	if (!n->left && !n->right && !n->val)
		return NULL;
	return n;
}

void
printrec(Node *n)
{
	if (!n) {
		printf("null ");
		return;
	}

	printf("%d ", n->val);
	if (!n->left && !n->right)
		return;

	printrec(n->left);
	printrec(n->right);
}

void
print(Node *n)
{
	printrec(n);
	printf("\n");
}

int
main()
{
	Node *n1 = &(Node){
		.val = 1,
		.right = &(Node){
		    .val = 0,
		    .left = &(Node){
		        .val = 0,
		    },
		    .right = &(Node){
		        .val = 1,
		    },
		},
	};

	Node *n2 = &(Node){
		.val = 1,
		.left = &(Node){
		    .val = 0,
		    .left = &(Node){
		        .val = 0,
		    },
		    .right = &(Node){
		        .val = 0,
		    },
		},
		.right = &(Node){
		    .val = 1,
		    .left = &(Node){
		        .val = 0,
		    },
		    .right = &(Node){
		        .val = 1,
		    },
		},
	};

	Node *n3 = &(Node){
		.val = 1,
		.left = &(Node){
		    .val = 1,
		    .left = &(Node){
		        .val = 1,
		        .left = &(Node){
		            .val = 0,
		        },
		    },
		    .right = &(Node){
		        .val = 1,
		    },
		},
		.right = &(Node){
		    .val = 0,
		    .left = &(Node){
		        .val = 0,
		    },
		    .right = &(Node){
		        .val = 1,
		    },
		},
	};

	n1 = prune(n1);
	n2 = prune(n2);
	n3 = prune(n3);

	print(n1);
	print(n2);
	print(n3);

	return 0;
}
