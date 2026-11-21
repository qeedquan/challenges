/*

You will be given two inputs: a string of words and a letter. For each string, return the alphabetic character after every instance of letter(case insensitive).

If there is a number, punctuation or underscore following the letter, it should not be returned.

If letter = 'r':
comes_after("are you really learning Ruby?") # => "eenu"
comes_after("Katy Perry is on the radio!")   # => "rya"
comes_after("Pirates say arrrrrrrrr.")       # => "arrrrrrrr"
comes_after("r8 your friend")                # => "i"

Return an empty string if there are no instances of letter in the given string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
ischar(int c)
{
	return !(c == '_' || isspace(c) || ispunct(c) || isdigit(c));
}

char *
comesafter(const char *s, int c, char *b)
{
	size_t i;
	char *p;

	c = tolower(c);
	p = b;
	for (i = 0; s[i]; i++) {
		if (c == tolower(s[i]) && ischar(s[i + 1]))
			*p++ = s[i + 1];
	}
	*p = '\0';

	return b;
}

void
test(const char *s, int c, const char *r)
{
	char b[128];

	comesafter(s, c, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("are you really learning Ruby?", 'r', "eenu");
	test("Katy Perry is on the radio!", 'r', "rya");
	test("Pirates say arrrrrrrrr.", 'r', "arrrrrrrr");
	test("r8 your friend", 'r', "i");

	return 0;
}
