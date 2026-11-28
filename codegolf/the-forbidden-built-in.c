/*

In the standard loopholes, the following is forbidden:

Claiming that your answer is written in "MyOwnLanguage", where the command x means "read a sequence of numbers, split them into groups of three, and print the last numbers of those groups where the second number is less than the first"

Here, we are going to do the exact same thing.

Task
Given a sequence of positive integers, whose length is divisible by 3, split them into groups of three, and print the last numbers of those groups where the second number is less than the first.

Testcases
Input               Output
[]                  []
[1,2,3,4,5,6,7,8,9] []
[2,1,3,5,4,6,8,7,9] [3,6,9]
[3,1,4,1,5,9,2,6,5] [4]
[100,99,123]        [123]
[123,123,456]       []
[456,123,789]       [789]

Scoring
This is code-golf. Shortest answer in bytes wins.

Standard loopholes apply, so remember not to have a built-in command x that does this task.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
split3(int *a, size_t n, int *r)
{
	size_t i, j;

	for (i = j = 0; i + 2 < n; i += 3) {
		if (a[i + 1] < a[i])
			r[j++] = a[i + 2];
	}
	return j;
}

void
test(int *a, size_t n, int *r, size_t nr)
{
	int p[128];
	size_t np;

	np = split3(a, n, p);
	assert(np == nr);
	if (np)
		assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a2[] = {2, 1, 3, 5, 4, 6, 8, 7, 9};
	int a3[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
	int a4[] = {100, 99, 123};
	int a5[] = {123, 123, 456};
	int a6[] = {456, 123, 789};

	int r2[] = {3, 6, 9};
	int r3[] = {4};
	int r4[] = {123};
	int r6[] = {789};

	test(NULL, 0, NULL, 0);
	test(a1, nelem(a1), NULL, 0);
	test(a2, nelem(a2), r2, nelem(r2));
	test(a3, nelem(a3), r3, nelem(r3));
	test(a4, nelem(a4), r4, nelem(r4));
	test(a5, nelem(a5), NULL, 0);
	test(a6, nelem(a6), r6, nelem(r6));

	return 0;
}
