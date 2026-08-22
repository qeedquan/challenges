/*

In this challenge, you implement an interpreter for a simple stack-based programming language. Your language must provide the following instructions:

push a positive number
pop two numbers and push their sum
pop two numbers and push their difference (second number - first number)
pop a number and push it twice (dup)
pop two numbers and push them so that they are in opposite order (swap)
pop a number and discard it (drop)
You may assume instructions will never be called with less arguments on the stack than are needed.

The actual instructions can be chosen for each implementation, please specify how each instruction is called in the solution. Your program/function must output/return the stack after all instructions are performed sequentially. Output the stack in whatever format you prefer. The stack must be empty at the start of your program.

Examples
For these examples, the stack is represented bottom-to-top.

1 2 + -> [3]
1 drop -> []
10 2 - 3 + -> [11]
9 dup - -> [0]
1 2 3 -> [1 2 3]
1 dup 2 + -> [1 3]
3 2 5 swap -> [3 5 2]

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

int
token(const char **src, int *val)
{
	const char *ptr;
	char *endptr;
	int tok;

	ptr = *src;
	while (*ptr && isspace(*ptr))
		ptr++;

	tok = EOF;
	if (isdigit(*ptr)) {
		tok = 'i';
		*val = strtol(ptr, &endptr, 10);
		ptr = endptr;
	} else if (!strncmp(ptr, "dup", 3)) {
		tok = 'd';
		ptr += 3;
	} else if (!strncmp(ptr, "drop", 4)) {
		tok = 'r';
		ptr += 4;
	} else if (!strncmp(ptr, "swap", 4)) {
		tok = 's';
		ptr += 4;
	} else if (*ptr == '+' || *ptr == '-') {
		tok = *ptr;
		ptr += 1;
	}

	*src = ptr;
	return tok;
}

int *
interpret(const char *src, size_t *len)
{
	int *stk;
	int tok;
	int val;
	size_t sp;

	stk = calloc(sizeof(*stk), strlen(src) + 1);
	if (!stk)
		goto error;

	sp = 0;
	for (;;) {
		tok = token(&src, &val);
		if (tok == EOF)
			break;

		switch (tok) {
		case 'i':
			stk[sp++] = val;
			break;

		case '+':
			if (sp < 2)
				goto error;

			stk[sp - 2] += stk[sp - 1];
			sp--;
			break;

		case '-':
			if (sp < 2)
				goto error;

			stk[sp - 2] -= stk[sp - 1];
			sp--;
			break;

		case 'd':
			if (sp < 1)
				goto error;

			stk[sp] = stk[sp - 1];
			sp++;
			break;

		case 's':
			if (sp < 2)
				goto error;

			swap(&stk[sp - 1], &stk[sp - 2]);
			break;

		case 'r':
			if (sp < 1)
				goto error;

			sp--;
			break;
		}
	}

	if (0) {
	error:
		free(stk);
		stk = NULL;
		sp = 0;
	}

	*len = sp;
	return stk;
}

void
dump(int *arr, size_t len)
{
	size_t i;

	printf("[ ");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("]\n");
}

void
test(const char *src, int *res, size_t reslen)
{
	int *stk;
	size_t stklen;

	stk = interpret(src, &stklen);
	assert(stk != NULL);
	dump(stk, stklen);
	assert(stklen == reslen);
	if (stklen)
		assert(!memcmp(stk, res, sizeof(*res) * reslen));
	free(stk);
}

int
main()
{
	int res1[] = {3};
	int res2[] = {11};
	int res3[] = {0};
	int res4[] = {1, 2, 3};
	int res5[] = {1, 3};
	int res6[] = {3, 5, 2};

	test("1 2 +", res1, nelem(res1));
	test("1 drop", NULL, 0);
	test("10 2 - 3 +", res2, nelem(res2));
	test("9 dup -", res3, nelem(res3));
	test("1 2 3", res4, nelem(res4));
	test("1 dup 2 +", res5, nelem(res5));
	test("3 2 5 swap", res6, nelem(res6));

	return 0;
}
