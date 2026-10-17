/*

Delete all lowercase Latin letters a from the given string.

Input
One single string containing no more than 1000 Latin letters and spaces.

Output
Print the string without lowercase Latin letters a, preserving the order of the other characters.

Examples

Input #1
abrakadabra

Answer #1
brkdbr

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
solve(char *s)
{
	char *p;

	for (p = s; *s; s++) {
		if (*s != 'a')
			*p++ = *s;
	}
	*p = '\0';
	return p;
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
	test("abrakadabra", "brkdbr");

	return 0;
}
