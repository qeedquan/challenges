/*

Complete the function which accepts a string and returns an array of character(s) that have the most spaces to their right and left.

Notes
the string can have leading/trailing spaces - you should not count them
the strings contain only unique characters from a to z
the order of characters in the returned array doesn't matter
Examples
"a b  c"                        -->  ['b']
"a bcs           d k"           -->  ['d']
"    a b  sc     p     t   k"   -->  ['p']
"a  b  c  de"                   -->  ['b', 'c']
"     a  b  c de        "       -->  ['b']
"abc"                           -->  ['a', 'b', 'c']

Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

size_t
skipws(const char **s)
{
	size_t i;

	for (i = 0; isspace(**s); i++)
		*s += 1;
	return i;
}

void
loneliest(const char *s, char *b)
{
	size_t h[256];
	size_t n0, n1;
	size_t m;
	char *p;
	int c;

	memset(h, 0, sizeof(h));
	n0 = m = 0;
	skipws(&s);
	while (*s) {
		c = *s++ & 0xff;
		n1 = skipws(&s);
		if (!*s)
			n1 = 0;

		h[c] = n0 + n1 + 1;
		n0 = n1;
		m = max(m, h[c]);
	}

	p = b;
	for (c = 0; c < 256; c++) {
		if (m && h[c] == m)
			*p++ = c;
	}
	*p = '\0';
}

void
test(const char *s, const char *r)
{
	char b[512];

	loneliest(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("a b  c", "b");
	test("a bcs           d k", "d");
	test("    a b  sc     p     t   k", "p");
	test("a  b  c  de", "bc");
	test("     a  b  c de        ", "b");
	test("a  b  c  de", "bc");
	test("     a  b  c de        ", "b");
	test("abc", "abc");
	test("", "");

	return 0;
}
