/*

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation:

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct List List;

struct List {
	int data;
	List *next;
};

List *
insert(List *l, int v)
{
	List *lp, *n;

	n = calloc(1, sizeof(*n));
	if (n == NULL)
		return NULL;
	n->data = v;

	for (lp = l; l != NULL; l = l->next)
		lp = l;

	if (lp != NULL)
		lp->next = n;

	return n;
}

List *
mklist(int n, ...)
{
	List *h, *t;
	int i, v;
	va_list ap;

	h = t = NULL;
	va_start(ap, n);
	for (i = 0; i < n; i++) {
		v = va_arg(ap, int);
		t = insert(t, v);
		if (h == NULL)
			h = t;
	}
	va_end(ap);

	return h;
}

void
freelist(List *l)
{
	List *lp;

	while (l != NULL) {
		lp = l->next;
		free(l);
		l = lp;
	}
}

List *
swappairs(List *head)
{
	List *curr, *prev, *next;

	curr = head;
	prev = NULL;
	next = NULL;
	while (curr && curr->next) {
		next = curr->next;

		curr->next = next->next;
		if (prev == NULL)
			head = prev = next;
		else
			prev->next = next;
		next->next = curr;

		prev = curr;
		curr = curr->next;
	}
	return head;
}

void
print(List *l)
{
	for (; l != NULL; l = l->next)
		printf("%d->", l->data);
	printf("NULL\n");
}

int
main(void)
{
	List *l1, *l2, *l3, *l4;

	l1 = mklist(4, 1, 2, 3, 4);
	l2 = mklist(0);
	l3 = mklist(1, 1);
	l4 = mklist(3, 1, 2, 3);

	l1 = swappairs(l1);
	l2 = swappairs(l2);
	l3 = swappairs(l3);
	l4 = swappairs(l4);

	print(l1);
	print(l2);
	print(l3);
	print(l4);

	freelist(l1);
	freelist(l2);
	freelist(l3);
	freelist(l4);

	return 0;
}
