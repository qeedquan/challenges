/*

No Story

No Description

Only by Thinking and Testing

Look at the results of the testcases, and guess the code!

*/

#include <assert.h>
#include <string.h>

void
solve(int a[4], int b[4], int c[4])
{
	c[0] = (a[0] * b[0]) + (a[1] * b[2]);
	c[1] = (a[0] * b[1]) + (a[1] * b[3]);
	c[2] = (a[2] * b[0]) + (a[3] * b[2]);
	c[3] = (a[2] * b[1]) + (a[3] * b[3]);
}

void
test(int a[4], int b[4], int r[4])
{
	int c[4];

	solve(a, b, c);
	assert(!memcmp(r, c, sizeof(c)));
}

int
main()
{
	int a1[] = {0, 0, 0, 0};
	int b1[] = {0, 0, 0, 0};
	int c1[] = {0, 0, 0, 0};

	int a2[] = {22, 88, 0, 0};
	int b2[] = {0, 100, 0, 100};
	int c2[] = {0, 11000, 0, 0};

	int a3[] = {0, 0, 96, 49};
	int b3[] = {86, 0, 53, 0};
	int c3[] = {0, 0, 10853, 0};

	int a4[] = {0, 0, 83, 88};
	int b4[] = {0, 27, 0, 99};
	int c4[] = {0, 0, 0, 10953};

	test(a1, b1, c1);
	test(a2, b2, c2);
	test(a3, b3, c3);
	test(a4, b4, c4);

	return 0;
}
