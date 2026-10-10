/*

Remove all odd digits from the given string.

Input
The input consists of a single string containing letters and digits.

Output
Print the resulting string after removing all odd digits.

Examples
Input #1
a1b2c3d4567hfgh

Answer #1
ab2cd46hfgh

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
solve(char *s)
{
	char *p;

	for (p = s; *s; s++) {
		if (!strchr("13579", *s))
			*p++ = *s;
	}
	*p = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	strcpy(b, s);
	solve(b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("a1b2c3d4567hfgh", "ab2cd46hfgh");

	return 0;
}
