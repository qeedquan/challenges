/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Follow up: Could you do this in one pass?

Hint 1
Maintain two pointers and update one with a delay of n steps.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Node Node;

struct Node {
	int val;
	Node *next;
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

Node *
rm(Node *h, int n)
{
	Node dummy;
	Node *p1, *p2;
	int i;

	if (!h || n <= 0)
		return h;

	memset(&dummy, 0, sizeof(dummy));
	dummy.next = h;
	h = &dummy;

	p1 = p2 = h;
	for (i = 0; i < n; i++) {
		if (!p2)
			return h->next;
		p2 = p2->next;
	}

	while (p2->next) {
		p2 = p2->next;
		p1 = p1->next;
	}

	p2 = p1->next;
	p1->next = p2->next;

	free(p2);

	return h->next;
}

void
print(Node *h)
{
	while (h != NULL) {
		printf("%d ", h->val);
		h = h->next;
	}
	printf("\n");
}

Node *
mklist(int *a, size_t n)
{
	Node *h, *p;
	size_t i;

	h = p = NULL;
	for (i = 0; i < n; i++) {
		if (!h) {
			h = xcalloc(1, sizeof(*h));
			h->val = a[i];
			p = h;
		} else {
			p->next = xcalloc(1, sizeof(*p->next));
			p->next->val = a[i];
			p = p->next;
		}
	}
	return h;
}

void
freelist(Node *h)
{
	Node *p;

	while (h != NULL) {
		p = h->next;
		free(h);
		h = p;
	}
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 5 };
	int a2[] = { 1 };
	int a3[] = { 1, 2 };
	int a4[] = { 55, 66, 77 };

	Node *p1, *p2, *p3, *p4;

	p1 = mklist(a1, nelem(a1));
	p2 = mklist(a2, nelem(a2));
	p3 = mklist(a3, nelem(a3));
	p4 = mklist(a4, nelem(a4));

	p1 = rm(p1, 2);
	p2 = rm(p2, 1);
	p3 = rm(p3, 1);
	p4 = rm(p4, 199);

	print(p1);
	print(p2);
	print(p3);
	print(p4);

	freelist(p1);
	freelist(p2);
	freelist(p3);
	freelist(p4);

	return 0;
}
