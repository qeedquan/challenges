/*

Write a function that takes a string and outputs a strings of 1's and 0's where vowels become 1's and non-vowels become 0's.

All non-vowels including non alpha characters (spaces,commas etc.) should be included.

Examples:

vowelOne( "abceios" ) // "1001110"

vowelOne( "aeiou, abc" ) // "1111100100"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
vowelone(const char *s, char *b)
{
	for (; *s; s++) {
		if (strchr("aeiou", tolower(*s)))
			*b++ = '1';
		else
			*b++ = '0';
	}
	*b = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	vowelone(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("abceios", "1001110");
	test("aeiou, abc", "1111100100");

	return 0;
}
