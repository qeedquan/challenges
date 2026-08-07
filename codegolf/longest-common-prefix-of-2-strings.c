/*

Write a program that takes 2 strings as input, and returns the longest common prefix. This is code-golf, so the answer with the shortest amount of bytes wins.

Test Case 1:

"global" , "glossary"
"glo"


Test Case 2:

"department" , "depart"
"depart"

Test Case 3:

"glove", "dove"
""

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
lcp(const char *s, const char *t, char *b)
{
	size_t i;

	for (i = 0; s[i] && s[i] == t[i]; i++)
		b[i] = s[i];
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	lcp(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("global", "glossary", "glo");
	test("department", "depart", "depart");
	test("glove", "dove", "");

	return 0;
}
