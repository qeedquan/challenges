/*

Hint
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Example 1:
https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:
https://assets.leetcode.com/uploads/2020/11/09/tmp-tree-1.jpg
Input: root = [1,null,2,null,0,3]
Output: 3

Constraints:

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 10^5

Hint 1
For each subtree, find the minimum value and maximum value of its descendants.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
min(int a, int b)
{
	return (a < b) ? a : b;
}

void
dfs(Node *node, int minval, int maxval, int *maxdiff)
{
	if (!node)
		return;

	*maxdiff = max(*maxdiff, max(abs(minval - node->val), abs(maxval - node->val)));

	minval = min(minval, node->val);
	maxval = max(maxval, node->val);

	dfs(node->left, minval, maxval, maxdiff);
	dfs(node->right, minval, maxval, maxdiff);
}

int
maxancestordiff(Node *root)
{
	int maxdiff;

	if (!root)
		return 0;

	maxdiff = 0;
	dfs(root, root->val, root->val, &maxdiff);
	return maxdiff;
}

int
main()
{
	Node *tree1 = &(Node){
		.val = 8,
		.left = &(Node){
		    .val = 3,
		    .left = &(Node){
		        .val = 1,
		    },
		    .right = &(Node){
		        .val = 6,
		        .left = &(Node){
		            .val = 4,
		        },
		        .right = &(Node){
		            .val = 7,
		        },
		    },
		},
		.right = &(Node){
		    .val = 10,
		    .right = &(Node){
		        .val = 14,
		        .left = &(Node){
		            .val = 13,
		        },
		    },
		},
	};

	Node *tree2 = &(Node){
		.val = 1,
		.right = &(Node){
		    .val = 2,
		    .right = &(Node){
		        .val = 0,
		        .left = &(Node){
		            .val = 3,
		        },
		    },
		},
	};

	assert(maxancestordiff(tree1) == 7);
	assert(maxancestordiff(tree2) == 3);

	return 0;
}
