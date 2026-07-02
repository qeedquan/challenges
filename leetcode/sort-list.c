/*

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

*/

#include <stdio.h>
#include <stdlib.h>

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
merge(Node *h1, Node *h2)
{
	static Node dummy;

	Node *p1, *p2, *t;

	p1 = h1;
	p2 = h2;
	t = &dummy;

	while (p1 && p2) {
		if (p1->val < p2->val) {
			t->next = p1;
			p1 = p1->next;
		} else {
			t->next = p2;
			p2 = p2->next;
		}
		t = t->next;
	}
	if (p1)
		t->next = p1;
	if (p2)
		t->next = p2;

	return dummy.next;
}

Node *
sort(Node *h)
{
	Node *p1, *p2;

	if (!h || !h->next)
		return h;

	p1 = h;
	p2 = h->next;
	while (p2 && p2->next) {
		p1 = p1->next;
		p2 = p2->next->next;
	}

	p2 = p1->next;
	p1->next = NULL;

	return merge(sort(h), sort(p2));
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
	int a1[] = { 1, 2, 3, 4 };
	int a2[] = { -1, 5, 3, 4, 0 };
	int a3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	Node *p1, *p2, *p3;

	p1 = mklist(a1, nelem(a1));
	p2 = mklist(a2, nelem(a2));
	p3 = mklist(a3, nelem(a3));

	p1 = sort(p1);
	p2 = sort(p2);
	p3 = sort(p3);

	print(p1);
	print(p2);
	print(p3);

	freelist(p1);
	freelist(p2);
	freelist(p3);

	return 0;
}
