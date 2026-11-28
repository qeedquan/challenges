/*

Given a string input, write a program that prints a truthy value to STDOUT or equivalent if the input is a valid UUID, without using regexes.

A valid UUID is

32 hexadecimal digits, displayed in five groups separated by hyphens, in the form 8-4-4-4-12 for a total of 36 characters (32 alphanumeric characters and four hyphens).

Source

Test Cases
0FCE98AC-1326-4C79-8EBC-94908DA8B034
    => true
00000000-0000-0000-0000-000000000000
    => true
0fce98ac-1326-4c79-8ebc-94908da8b034
    => true
0FCE98ac-1326-4c79-8EBC-94908da8B034
    => true

{0FCE98AC-1326-4C79-8EBC-94908DA8B034}
    => false (the input is wrapped in brackets)
0GCE98AC-1326-4C79-8EBC-94908DA8B034
    => false (there is a G in the input)
0FCE98AC 1326-4C79-8EBC-94908DA8B034
    => false (there is a space in the input)
0FCE98AC-13264C79-8EBC-94908DA8B034
    => false (the input is missing a hyphen)
0FCE98AC-13264-C79-8EBC-94908DA8B034
    => false (the input has a hyphen in the wrong place)
0FCE98ACD-1326-4C79-8EBC-94908DA8B034
    => false (one of the groups is too long)
0FCE98AC-1326-4C79-8EBC-94908DA8B034-
    => false (has a trailing hyphen)
0FCE98AC-1326-4C79-8EBC-94908DA8B034-123
    => false (too many groups)
0FCE98AC13264C798EBC94908DA8B034
    => false (there is no grouping)

Rules
Regular Expressions are not allowed
Literal pattern matching which is like a regex is not allowed. For example, using [0-9a-fA-F] or other hexadecimal identifiers (we'll call this n) and then matching nnnnnnnn-nnnn-nnnn-nnnn-nnnnnnnnnnnn or n[8]-n[4]-n[4]-n[4]-n[12] is not allowed
The input may either be taken from STDIN or as an argument to a function
The input is case insensitive
It is safe to assume that the input will not contain linefeeds or newlines.
The input may contain any printable ASCII characters (spaces included)
A truthy value must be printed to STDOUT or equivalent if the input is a valid uuid
A falsey value must be printed to STDOUT or equivalent if the input is not a valid uuid
If using a function, instead of using STDOUT, the output can be the return value of the function
The truthy/falsey value cannot be printed to STDERR.
Standard loopholes apply
This is code-golf, so the shortest program in bytes wins. Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
match(const char *s)
{
	static const char sep[] = "-";
	static const char hex[] = "0123456789abcdefABCDEF";
	static const char fmt[] = "8-4-4-4-T";

	const char *f, *p;
	int i, n;

	for (f = fmt; *s && *f; f++) {
		p = hex;
		n = *f - '0';
		switch (*f) {
		case '-':
			p = sep;
			n = 1;
			break;
		case 'T':
			n = 12;
			break;
		}

		for (i = 0; i < n; i++) {
			if (!strchr(p, *s++))
				return false;
		}
	}
	return !*s && !*f;
}

int
main(void)
{
	assert(match("0FCE98AC-1326-4C79-8EBC-94908DA8B034") == true);
	assert(match("00000000-0000-0000-0000-000000000000") == true);
	assert(match("0fce98ac-1326-4c79-8ebc-94908da8b034") == true);
	assert(match("0FCE98ac-1326-4c79-8EBC-94908da8B034") == true);

	assert(match("{0FCE98AC-1326-4C79-8EBC-94908DA8B034}") == false);
	assert(match("0GCE98AC-1326-4C79-8EBC-94908DA8B034") == false);
	assert(match("0FCE98AC 1326-4C79-8EBC-94908DA8B034") == false);
	assert(match("0FCE98AC-13264C79-8EBC-94908DA8B034") == false);
	assert(match("0FCE98AC-13264-C79-8EBC-94908DA8B034") == false);
	assert(match("0FCE98ACD-1326-4C79-8EBC-94908DA8B034") == false);
	assert(match("0FCE98AC-1326-4C79-8EBC-94908DA8B034-") == false);
	assert(match("0FCE98AC-1326-4C79-8EBC-94908DA8B034-123") == false);
	assert(match("0FCE98AC13264C798EBC94908DA8B034") == false);

	return 0;
}
