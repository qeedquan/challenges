/*

No Story

No Description

Only by Thinking and Testing

Look at the results of the testcases, and guess the code!

*/

#include <assert.h>

int
solve(int a[4])
{
	return (a[0] * a[3]) + (a[1] * a[2]);
}

void
test(int a[4], int r)
{
	assert(solve(a) == r);
}

int
main()
{
	int a1[] = {0, 0, 0, 0};
	int a2[] = {0, 0, 0, 1};
	int a3[] = {0, 0, 1, 1};
	int a4[] = {0, 1, 0, 1};
	int a5[] = {0, 1, 1, 0};
	int a6[] = {1, 0, 0, 1};

	test(a1, 0);
	test(a2, 0);
	test(a3, 0);
	test(a4, 0);
	test(a5, 1);
	test(a6, 1);

	return 0;
}
