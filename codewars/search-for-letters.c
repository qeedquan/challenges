/*

Create a function which accepts one arbitrary string as an argument, and return a string of length 26.

The objective is to set each of the 26 characters of the output string to either '1' or '0' based on the fact whether the Nth letter of the alphabet is present in the input (independent of its case).

So if an 'a' or an 'A' appears anywhere in the input string (any number of times), set the first character of the output string to '1',
otherwise to '0'. if 'b' or 'B' appears in the string, set the second character to '1', and so on for the rest of the alphabet.

For instance:

"a   **&  cZ"  =>  "10100000000000000000000001"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef unsigned long ulong;

char *
letters(const char *s, char *b)
{
	size_t i;
	ulong f;
	int c;

	f = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if ('a' <= c && c <= 'z')
			f |= 1UL << (c - 'a');
	}

	for (i = 0; i < 26; i++) {
		if (f & (1UL << i))
			b[i] = '1';
		else
			b[i] = '0';
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	letters(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("a   **&  cZ", "10100000000000000000000001");
	return 0;
}
