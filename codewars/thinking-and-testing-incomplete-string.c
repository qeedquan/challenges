/*

No Story

No Description

Only by Thinking and Testing

Look at result of testcase, guess the code!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
testit(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i] && s[i + 1]; i += 2)
		b[j++] = (s[i] + s[i + 1]) / 2;

	if (s[i])
		b[j++] = s[i];

	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	testit(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("", "");
	test("a", "a");
	test("b", "b");

	test("aa", "a");
	test("ab", "a");
	test("bc", "b");

	test("aaaa", "aa");
	test("aaaaaa", "aaa");
	return 0;
}
