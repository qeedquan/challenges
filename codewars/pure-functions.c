/*

A function is pure when:

It always return the same value given the same arguments (it doesn't update or depend on out of the scope variables);
Evaluation of the result does not cause side effect (mutations...) or output
Task
You are given a function that is impure, and your job is to purify it. This function must return a new array where each value is itself plus 2 times the "modifier", which is provided as a property of the options object.

Example:

Array = 1, 2, 3
Modifier = 5

Should return = 11, 12, 13q

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(int *a, size_t n, int m, int *r)
{
	size_t i;

	for (i = 0; i < n; i++)
		r[i] = a[i] + (2 * m);
}

int
main()
{
	int a1[] = {1, 2, 3};
	int r1[] = {11, 12, 13};

	int x[16];

	solve(a1, nelem(a1), 5, x);
	assert(!memcmp(x, r1, sizeof(r1)));
	return 0;
}
