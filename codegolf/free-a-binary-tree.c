/*

So before you read some basic computer science concepts.

A binary tree is a dynamically allocated structure (usually used for ordered storage).
Because of its nature traversal of binary trees is usually recursive;
This is because linear traversal (via a loop) is not natural when there are two avenues of looping.
Recursive: This means a function that calls itself.
In old fashioned languages, memory management requires manual memory management.
Manual: Means you have to do it yourself.
When you do manual memory management you need to actual ask the underlying system to free each member of the tree.
Free: recover the memory in to the global poos so it can be re-used and you don't run out of memory.
Freeing: this is done by calling the function free() and passing it the pointer you want to recover.
Pointer: Its like a virtual stick. At the end is memory. When you ask for memory you are given a pointer (virtual stick) that has memory. When you are done you give back the pointer (virtual stick).
The recursive solution:
freeTree(Node* node)
{
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
The problem then is that recursion means you are repeatedly calling the same function. This grows the stack. Growing the stack uses more memory. The reason you are freeing the tree is you want memory back using more memory is counterproductive (even if you do get both bits of memory back).

At last the question:
SO the problem centers around converting the recursive version above into a linear solution (so that you don't have to use memory).

Give the node type

typedef struct Node Node;
struct Node
{
    Node* left;
    Node* right;
};
Write a function to free a tree of these nodes.

Restrictions:

Cannot use recursion (not even indirectly)
Cannot allocate any dynamic space for tracking.

Note there is an O(n) solution

Winner:

Best Complexity.
Tie Break 1: First Submitted
Tie Break 2: Least amount of characters.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int value;
	Node *left;
	Node *right;
};

Node *
alloc(int value)
{
	Node *node;

	node = calloc(1, sizeof(*node));
	if (!node)
		abort();
	node->value = value;
	return node;
}

/*

ported from @Arnaud Le Blanc solution

This does a depth-first walk on the tree, and uses the ->left pointer of traversed nodes to keep track of the parent.

*/

void
freebst(Node *root)
{
	Node *node, *up;
	Node *left, *right;

	node = root;
	up = NULL;
	while (node != NULL) {
		if (node->left != NULL) {
			left = node->left;
			node->left = up;
			up = node;
			node = left;
		} else if (node->right != NULL) {
			right = node->right;
			node->left = up;
			node->right = NULL;
			up = node;
			node = right;
		} else {
			if (up == NULL) {
				free(node);
				node = NULL;
			}
			while (up != NULL) {
				free(node);
				if (up->right != NULL) {
					node = up->right;
					up->right = NULL;
					break;
				} else {
					node = up;
					up = up->left;
				}
			}
		}
	}
}

int
main()
{
	Node *root;

	root = alloc(1);
	root->left = alloc(2);
	root->right = alloc(3);
	root->left->left = alloc(4);
	root->right->right = alloc(5);
	freebst(root);
	return 0;
}
