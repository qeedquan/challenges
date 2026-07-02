/*

Task
Given positive integer n, if n is odd, repeat / that many times; if n is even, repeat \ that many times.

(Seriously, the testcases would be much clearer than this description, so just look at the testcases.)

Specs
Any reasonable input/output format.
Standard loopholes apply.

Testcases
n output
1 /
2 \\
3 ///
4 \\\\
5 /////
6 \\\\\\

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
squiggly(unsigned n, char *b)
{
	int c;

	c = (n & 1) ? '/' : '\\';
	memset(b, c, n);
	b[n] = '\0';

	return b;
}

void
test(unsigned n, const char *r)
{
	char b[128];

	squiggly(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "/");
	test(2, "\\\\");
	test(3, "///");
	test(4, "\\\\\\\\");
	test(5, "/////");
	test(6, "\\\\\\\\\\\\");

	return 0;
}
