/*

Write a function that takes a string and returns an array of the repeated characters (letters, numbers, whitespace) in the string.

If a charater is repeated more than once, only show it once in the result array.

Characters should be shown by the order of their first repetition. Note that this may be different from the order of first appearance of the character.

Characters are case sensitive.

For F# return a "char list"

Examples:
remember("apple") => returns ["p"]
remember("apPle") => returns []          // no repeats, "p" != "P"
remember("pippi") => returns ["p","i"]   // show "p" only once
remember('Pippi') => returns ["p","i"]   // "p" is repeated first

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
remember(const char *s, char *b)
{
	size_t h[256];
	char *p;
	int c;

	memset(h, 0, sizeof(h));
	for (p = b; *s; s++) {
		c = *s & 0xff;
		h[c] += 1;
		if (h[c] == 2)
			*p++ = c;
	}
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	remember(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("apple", "p");
	test("apPle", "");
	test("pippi", "pi");
	test("Pippi", "pi");

	return 0;
}
