/*

Today is a common interview question.

Given a binary search tree t and two elements of the tree, m and n, with m < n, find the lowest element of the tree (farthest from the root) that is an ancestor of both m and n.

*/

#include <cstdio>

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int data, Node *left = NULL, Node *right = NULL)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}

	~Node()
	{
		delete left;
		delete right;
	}
};

// https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
Node *lca(Node *root, int value0, int value1)
{
	if (!root)
		return NULL;
	if (root->data > value0 && root->data > value1)
		return lca(root->left, value0, value1);
	if (root->data < value0 && root->data < value1)
		return lca(root->right, value0, value1);
	return root;
}

int main()
{
	auto root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(4);
	root->left->right = new Node(12);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);

	auto n1 = 10;
	auto n2 = 14;
	auto t = lca(root, n1, n2);
	printf("%d %d %d\n", n1, n2, t->data);

	n1 = 14;
	n2 = 8;
	t = lca(root, n1, n2);
	printf("%d %d %d\n", n1, n2, t->data);

	n1 = 10;
	n2 = 22;
	t = lca(root, n1, n2);
	printf("%d %d %d\n", n1, n2, t->data);

	delete root;
	return 0;
}
