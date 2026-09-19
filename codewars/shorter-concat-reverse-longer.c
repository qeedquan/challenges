/*

Given 2 strings, a and b, return a string of the form: shorter+reverse(longer)+shorter.

In other words, the shortest string has to be put as prefix and as suffix of the reverse of the longest.

Strings a and b may be empty, but not null (In C# strings may also be null. Treat them as if they are empty.).
If a and b have the same length treat a as the longer producing b+reverse(a)+b

*/

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void
swap(void *a, void *b, size_t n)
{
	char t[sizeof(max_align_t)];

	memmove(t, a, n);
	memmove(a, b, n);
	memmove(b, t, n);
}

void
scrl(const char *a, const char *b, char *s)
{
	size_t i, n, m;

	n = strlen(a);
	m = strlen(b);
	if (n >= m) {
		swap(&a, &b, sizeof(a));
		swap(&n, &m, sizeof(n));
	}
	s += sprintf(s, "%s", a);
	for (i = m; i > 0; i--)
		*s++ = b[i - 1];
	s += sprintf(s, "%s", a);
}

void
test(const char *a, const char *b, const char *r)
{
	char s[128];

	scrl(a, b, s);
	puts(s);
	assert(!strcmp(s, r));
}

int
main()
{
	test("first", "abcde", "abcdetsrifabcde");
	test("hello", "bau", "bauollehbau");
	test("abcde", "fghi", "fghiedcbafghi");

	return 0;
}
