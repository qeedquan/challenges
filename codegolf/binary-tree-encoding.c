/*

Let's suppose you have a complete binary tree (i.e. each internal node has exactly two non empty descendants). Each node contains a nonzero integer. You are given the task of encoding and decoding the tree into/from a list of integers.

The tree is stored internally something like:

struct node {
  int data;
  struct node *left, *right;
};
And you have to implement two functions:

int *encode(struct node *root);
struct node *decode(int *array);
It is up to you how you encode and decode.

Points for:

minimum encoding length
complexity (ideally linear in number of nodes)
originality
No points for source code length and you are not restricted to C.

Tree example:

     5
    / \
   3   2
      / \
     2   1
    / \
   9   9

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*

Ported from @AShelly solution

Here is a solution which only takes N+ceiling(N/32)+1 ints of storage. This approaches 1.03125 N for large N, and is under 1.1 N for all N greater than 20.

The idea is to store an extra bit for each node where 1 is "hasChildren". These bits are packed into N/32 words up front.

*/

typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

float
randf()
{
	return (rand() * 1.0f) / RAND_MAX;
}

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

void
tree_free(Node *n)
{
	if (!n)
		return;
	tree_free(n->left);
	tree_free(n->right);
	free(n);
}

int
tree_compare(Node *node1, Node *node2)
{
	if (!node1)
		return !node2;

	if (!node2 || (node1->data != node2->data))
		return 0;

	return tree_compare(node1->left, node2->left) && tree_compare(node1->right, node2->right);
}

int
count_nodes(Node *node)
{
	if (!node)
		return 0;
	return 1 + count_nodes(node->left) + count_nodes(node->right);
}

int *
bencode_helper(Node *node, int *code, int *pos, int *flag)
{
	int has_kids;

	has_kids = (node->left != 0);

	code[*flag / 32] |= has_kids << (*flag & 31);
	*flag += 1;
	if (has_kids)
		bencode_helper(node->left, code, pos, flag);

	code[*pos] = node->data;
	*pos += 1;

	if (has_kids)
		bencode_helper(node->right, code, pos, flag);
	return code;
}

int *
bencode(Node *head, int *size)
{
	int num_nodes;
	int nflags;
	int pos;
	int flag;
	int *out;

	num_nodes = count_nodes(head);
	nflags = ceil(num_nodes / 32.0);
	pos = nflags + 1;
	flag = 32;

	*size = 1 + num_nodes + nflags;
	out = xcalloc(*size, sizeof(*out));
	out[0] = nflags + 1;

	return bencode_helper(head, out, &pos, &flag);
}

Node *
bdecode_helper(int *code, int *pos, int *flag)
{
	Node *node;
	int has_kids;

	node = xcalloc(1, sizeof(*node));

	has_kids = code[*flag / 32] >> (*flag & 31) & 1;
	*flag += 1;
	if (has_kids)
		node->left = bdecode_helper(code, pos, flag);

	node->data = code[*pos];
	*pos += 1;

	if (has_kids)
		node->right = bdecode_helper(code, pos, flag);

	return node;
}

Node *
bdecode(int *code)
{
	int flag;
	int pos;

	flag = 32;
	pos = code[0];
	if (!pos)
		return NULL;
	return bdecode_helper(code, &pos, &flag);
}

Node *
make_random_tree(float freq, int max_depth)
{
	Node *node;

	node = xcalloc(1, sizeof(*node));
	node->data = rand();
	if (max_depth-- && (randf() < freq)) {
		node->left = make_random_tree(freq, max_depth);
		node->right = make_random_tree(freq, max_depth);
	}
	return node;
}

int
main()
{
	Node *head;
	Node *dup;
	int i, size;
	int num_nodes;
	int *code;

	srand(time(NULL));

	head = make_random_tree(0.79, 20);
	num_nodes = count_nodes(head);
	code = bencode(head, &size);

	printf("Tree with %d nodes encodes to %d ints\n", num_nodes, size);
	for (i = 0; i < size; ++i) {
		printf("%.4x, ", code[i]);
	}
	puts("\n");

	dup = bdecode(code);
	if (tree_compare(head, dup)) {
		puts("Trees Compare Exactly!\n");
	} else {
		puts("FAILURE\n");
	}

	tree_free(head);
	tree_free(dup);
	free(code);

	return 0;
}
