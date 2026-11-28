/*

Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.


Example 1:

Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
Explanation
CustomStack stk = new CustomStack(3); // Stack is Empty []
stk.push(1);                          // stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.push(3);                          // stack becomes [1, 2, 3]
stk.push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4
stk.increment(5, 100);                // stack becomes [101, 102, 103]
stk.increment(2, 100);                // stack becomes [201, 202, 103]
stk.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
stk.pop();                            // return 202 --> Return top of the stack 202, stack becomes [201]
stk.pop();                            // return 201 --> Return top of the stack 201, stack becomes []
stk.pop();                            // return -1 --> Stack is empty return -1.


Constraints:

1 <= maxSize, x, k <= 1000
0 <= val <= 100
At most 1000 calls will be made to each method of increment, push and pop each separately.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
	int *val;
	size_t len;
	size_t cap;
} Stack;

int
stackinit(Stack *s, size_t maxsize)
{
	s->val = calloc(maxsize, sizeof(*s->val));
	if (!s->val)
		return -errno;

	s->len = 0;
	s->cap = maxsize;
	return 0;
}

void
stackfree(Stack *s)
{
	if (!s)
		return;
	free(s->val);
}

int
stackpush(Stack *s, int val)
{
	if (s->len >= s->cap)
		return -ENOMEM;

	s->val[s->len++] = val;
	return 0;
}

int
stackpop(Stack *s)
{
	if (s->len == 0)
		return -1;
	return s->val[--s->len];
}

void
stackinc(Stack *s, size_t k, int inc)
{
	size_t i;

	if (k > s->len)
		k = s->len;
	for (i = 0; i < k; i++)
		s->val[i] += inc;
}

int
main(void)
{
	Stack s[1];

	assert(stackinit(s, 3) >= 0);
	assert(stackpush(s, 1) >= 0);
	assert(stackpush(s, 2) >= 0);
	assert(stackpop(s) == 2);
	assert(stackpush(s, 2) >= 0);
	assert(stackpush(s, 3) >= 0);
	assert(stackpush(s, 4) < 0);
	stackinc(s, 5, 100);
	stackinc(s, 2, 100);
	assert(stackpop(s) == 103);
	assert(stackpop(s) == 202);
	assert(stackpop(s) == 201);
	assert(stackpop(s) == -1);
	stackfree(s);

	return 0;
}
