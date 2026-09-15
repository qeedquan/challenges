/*

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

Example 1:
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.

Constraints:

The number of nodes in the list is in the range [1, 10^4]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

Hint 1
Traverse the linked list from the least significant digit to the most significant digit and multiply each node's value by 2
Hint 2

Handle any carry-over digits that may arise during the doubling process.

Hint 3
If there is a carry-over digit on the most significant digit, create a new node with that value and point it to the start of the given linked list and return it.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct List List;

struct List {
	int val;
	List *next;
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

List *
doubleit(List *head)
{
	List *newhead;
	List *curr;

	if (head->val >= 5) {
		newhead = xcalloc(1, sizeof(*newhead));
		newhead->next = head;
		head = newhead;
	}
	for (curr = head; curr; curr = curr->next) {
		curr->val = (curr->val * 2) % 10;
		if (curr->next && curr->next->val >= 5)
			curr->val += 1;
	}
	return head;
}

List *
vmklist(size_t n, va_list ap)
{
	List *h, *t, *p;
	size_t i;

	h = NULL;
	for (i = 0; i < n; i++) {
		p = xcalloc(1, sizeof(*p));
		p->val = va_arg(ap, int);
		if (!h)
			h = t = p;
		else {
			t->next = p;
			t = p;
		}
	}
	return h;
}

List *
mklist(size_t n, ...)
{
	List *l;
	va_list ap;

	va_start(ap, n);
	l = vmklist(n, ap);
	va_end(ap);
	return l;
}

void
print(List *l)
{
	for (; l; l = l->next)
		printf("%d ", l->val);
	printf("\n");
}

void
freelist(List *l)
{
	List *p;

	for (p = l; p;) {
		p = l->next;
		free(l);
		l = p;
	}
}

int
main()
{
	List *l1, *l2;

	l1 = mklist(3, 1, 8, 9);
	l2 = mklist(3, 9, 9, 9);

	l1 = doubleit(l1);
	l2 = doubleit(l2);

	print(l1);
	print(l2);

	freelist(l1);
	freelist(l2);

	return 0;
}
