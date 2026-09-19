/*

I define the n-th ternary as a ternary that returns n and has the form:

1 ? 2 ? 3 ? n - 1 ? n : 0 : 0 : 0  # n - 1 zeroes
Write a function or complete program that given an input n will output or return the n-th ternary. Code-Golf.

Testcases

0 #=> undefined behaviour
1 #=> 1
2 #=> 1 ? 2 : 0
3 #=> 1 ? 2 ? 3 : 0 : 0
10 #=> 1 ? 2 ? 3 ? 4 ? 5 ? 6 ? 7 ? 8 ? 9 ? 10 : 0 : 0 : 0 : 0 : 0 : 0 : 0 : 0 : 0
The 1000-th ternary I think there is some kind of zen harmony to it.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
ternary(unsigned n, char *b)
{
	unsigned i;
	size_t l;

	*b = '\0';
	if (n < 1)
		return b;

	if (n == 1) {
		strcpy(b, "1");
		return b;
	}

	l = 0;
	for (i = 1; i <= n; i++)
		l += sprintf(b + l, "%u ? ", i);
	b[l - 2] = ':';

	for (i = 0; i < n - 1; i++)
		l += sprintf(b + l, "0 : ");
	b[l - 3] = '\0';

	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	ternary(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0, "");
	test(1, "1");
	test(2, "1 ? 2 : 0");
	test(3, "1 ? 2 ? 3 : 0 : 0");
	test(10, "1 ? 2 ? 3 ? 4 ? 5 ? 6 ? 7 ? 8 ? 9 ? 10 : 0 : 0 : 0 : 0 : 0 : 0 : 0 : 0 : 0");

	return 0;
}
