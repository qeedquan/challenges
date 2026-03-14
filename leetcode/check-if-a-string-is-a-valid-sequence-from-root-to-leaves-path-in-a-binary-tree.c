/*

Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree.

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a
path results in a sequence in the given binary tree.

Example 1:
https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_1.png
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation:
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure).
Other valid sequences are:
0 -> 1 -> 1 -> 0
0 -> 0 -> 0

Example 2:
https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_2.png
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.

Example 3:
https://assets.leetcode.com/uploads/2019/12/18/leetcode_testcase_3.png
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.

Constraints:

1 <= arr.length <= 5000
0 <= arr[i] <= 9
Each node's value is between [0 - 9].

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

bool
dfs(Node *node, int *array, size_t size, size_t depth)
{
	if (!node || depth >= size || node->val != array[depth])
		return false;
	if (depth + 1 >= size && node->left == node->right)
		return true;
	return dfs(node->left, array, size, depth + 1) || dfs(node->right, array, size, depth + 1);
}

bool
valid(Node *root, int *array, size_t size)
{
	return dfs(root, array, size, 0);
}

int
main()
{
	Node *tree = &(Node){
		.val = 0,
		.left = &(Node){
		    .val = 1,
		    .left = &(Node){
		        .val = 0,
		        .right = &(Node){
		            .val = 1,
		        },
		    },
		    .right = &(Node){
		        .val = 1,
		        .left = &(Node){
		            .val = 0,
		        },
		        .right = &(Node){
		            .val = 0,
		        },
		    },
		},
		.right = &(Node){
		    .val = 0,
		    .left = &(Node){
		        .val = 0,
		    },
		},
	};

	int array1[] = { 0, 1, 0, 1 };
	int array2[] = { 0, 0, 1 };
	int array3[] = { 0, 1, 1 };

	assert(valid(tree, array1, nelem(array1)) == true);
	assert(valid(tree, array2, nelem(array2)) == false);
	assert(valid(tree, array3, nelem(array3)) == false);

	return 0;
}
