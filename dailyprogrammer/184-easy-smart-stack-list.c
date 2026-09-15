/*

Description:
We all know the famous link list. We can use these to hold data in a linear fashion. The link list can be used to implement a stack as well for example.

For this challenge you will need to develop a smart stack list. So what makes this link list so smart? This link list will behave like a stack but also maintain an ascending sorted order of the data as well. So our link list maintains 2 orders (stack and sorted)

In today's world link list data structures are part of many development platforms. For this challenge you will be implementing this and not using already pre-made frameworks/standard link lists code that you call. You have to implement it and all the features.

The Challenge will have 2 steps.

Implement your smart link list

Test your smart link list

Data:
The smart link list will hold integer data.

Methods:
The smart link list must support these methods or operations.

Push - Push a number on top of the stack (our link list is a stack)

Pop - Pop the number off the top of the stack

Size - how many numbers are on your stack

Remove Greater - remove all integers off the stack greater in value then the given number

Display Stack - shows the stack order of the list (the order they were pushed from recent to oldest)

Display Ordered - shows the integers sorted from lowest to highest.

Smart list:
One could make a stack and when you do the display ordered do a sort. But our smart list must have a way so that it takes O(n) to display the link list in stack order or ascending order. In other words our link list is always in stack and sorted order. How do you make this work? That is the real challenge.

Test your list:
Develop a quick program that uses your smart stack list.

Generate a random number between 1-40. Call this number n.

Generate n random numbers between -1000 to 1000 and push them on your list

Display stack and sorted order

Generate a random number between -1000 and 1000 can call it x

Remove greater X from your list. (all integers greater than x)

Display stack and sorted order

pop your list (size of list / 2) times (50% of your list is removed)

Display stack and sorted order

*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

// ported from @skeeto solution
struct dlist {
	struct dlist *prev, *next;
};

typedef int (*sstack_compare_t)(const void *, const void *);
typedef void (*sstack_visit_t)(const void *value);

struct sstack_node {
	void *value;
	struct dlist stack, sort;
};

struct sstack {
	sstack_compare_t compare;
	size_t count;
	struct dlist stack, sort;
};

void *
xmalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		abort();
	return ptr;
}

void
dlist_insert(struct dlist *list, struct dlist *node)
{
	node->next = list->next;
	node->prev = list;
	if (list->next)
		list->next->prev = node;
	list->next = node;
}

void
dlist_remove(struct dlist *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
}

void
sstack_push(struct sstack *ss, void *value)
{
	struct sstack_node *node, *current;
	struct dlist *prev, *next;

	ss->count++;
	node = xmalloc(sizeof(*node));
	node->value = value;
	dlist_insert(&ss->stack, &node->stack);
	prev = &ss->sort;
	next = ss->sort.next;
	while (next) {
		current = container_of(next, struct sstack_node, sort);
		if (ss->compare(current->value, value) <= 0)
			break;
		prev = next;
		next = next->next;
	}
	dlist_insert(prev, &node->sort);
}

void *
sstack_pop(struct sstack *ss)
{
	struct dlist *dnode;
	struct sstack_node *node;
	void *value;

	ss->count--;
	dnode = ss->stack.next;
	node = container_of(dnode, struct sstack_node, stack);
	dlist_remove(&node->stack);
	dlist_remove(&node->sort);
	value = node->value;
	free(node);
	return value;
}

void
sstack_remove_gt(struct sstack *ss, void *value)
{
	struct dlist *dnode;
	struct sstack_node *node;

	dnode = ss->sort.next;
	while (dnode) {
		node = container_of(dnode, struct sstack_node, sort);
		if (ss->compare(node->value, value) <= 0)
			break;
		dlist_remove(&node->stack);
		dlist_remove(&node->sort);
		dnode = dnode->next;
		free(node);
		ss->count--;
	}
}

void
sstack_visit_stack(struct sstack *ss, void (*visit)(const void *value))
{
	struct dlist *dnode;
	struct sstack_node *node;

	dnode = ss->stack.next;
	for (; dnode; dnode = dnode->next) {
		node = container_of(dnode, struct sstack_node, stack);
		visit(node->value);
	}
}

void
sstack_visit_sorted(struct sstack *ss, void (*visit)(const void *value))
{
	struct dlist *dnode;
	struct sstack_node *node;

	dnode = ss->sort.next;
	for (; dnode; dnode = dnode->next) {
		node = container_of(dnode, struct sstack_node, sort);
		visit(node->value);
	}
}

void
sstack_free(struct sstack *ss)
{
	while (ss->count)
		sstack_pop(ss);
}

int
intcmp(const void *a, const void *b)
{
	return (intptr_t)a - (intptr_t)b;
}

void
intprint(const void *v)
{
	printf("%ld ", (intptr_t)v);
}

int
main()
{
	struct sstack ss = { .compare = intcmp };
	intptr_t value;
	int i;

	for (i = 0; i < 10; i++) {
		value = (rand() % 10);
		sstack_push(&ss, (void *)value);
	}
	sstack_visit_stack(&ss, intprint);
	printf("\n");
	sstack_visit_sorted(&ss, intprint);
	printf("\n");

	sstack_remove_gt(&ss, (void *)5);
	sstack_pop(&ss);
	sstack_pop(&ss);
	sstack_pop(&ss);
	sstack_pop(&ss);
	sstack_visit_stack(&ss, intprint);
	printf("\n");
	sstack_visit_sorted(&ss, intprint);
	printf("\n");
	sstack_free(&ss);

	return 0;
}
