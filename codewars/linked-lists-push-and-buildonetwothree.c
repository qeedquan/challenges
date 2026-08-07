/*

Linked Lists - Push & BuildOneTwoThree

Write push() and buildOneTwoThree() functions to easily update and initialize linked lists. Try to use the push() function within your buildOneTwoThree() function.

Here's an example of push() usage:

var chained = null
chained = push(chained, 3)
chained = push(chained, 2)
chained = push(chained, 1)
push(chained, 8) === 8 -> 1 -> 2 -> 3 -> null


The push function accepts head and data parameters, where head is either a node object or null/None/nil. Your push implementation should be able to create a new linked list/node when head is null/None/nil.

The buildOneTwoThree function should create and return a linked list with three nodes: 1 -> 2 -> 3 -> null

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *next;
};

void
freel(Node *node)
{
	Node *next;

	for (; node; node = next) {
		next = node->next;
		free(node);
	}
}

Node *
push(Node *head, int data)
{
	Node *node;

	node = calloc(1, sizeof(*node));
	if (!node)
		return NULL;

	node->data = data;
	node->next = head;
	return node;
}

Node *
build123()
{
	return push(push(push(NULL, 3), 2), 1);
}

void
print(Node *node)
{
	for (; node; node = node->next)
		printf("%d ", node->data);
	printf("\n");
}

int
main()
{
	Node *node;

	node = build123();
	print(node);
	freel(node);
	return 0;
}
