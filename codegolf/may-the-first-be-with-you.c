/*

Write a program to replace all occurrences of "force" with "first" and all occurrences of "first" with "force", keeping the original case for all character positions:

"ForcefoRcefOrcE" -> "FirstfiRstfIrsT"
"FirstfiRstfIrsT" -> "ForcefoRcefOrcE"
The rest of the string must stay unchanged, and so running your program twice shall return the original string:

"thirst of forces" -> "thirst of firsts" -> "thirst of forces"
Your program should work on any initial string. So as a hint, you better avoid using magic characters as intermediate representation, because if you try a three pass replacement ("force" -> "zzzzz", "first" -> "force", "zzzzz" -> "first"), it will fail on strings containing "zzzzz".

You should support the full range of characters allowed in a definition of a String by your programming language (in most cases, it's Unicode). Example, using JSON-style representation for non-printable characters (\u + 4 digits):

"\u0000\u0001\u0002\u0003the Force of the firsT"
                     |
                     V
"\u0000\u0001\u0002\u0003the First of the forcE"

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
concat(const char *s, char *b, const char *r)
{
	size_t i;

	for (i = 0; r[i]; i++) {
		b[i] = r[i];
		if (isupper(s[i]))
			b[i] = toupper(b[i]);
	}

	return i;
}

char *
firstforce(const char *s, char *b)
{
	size_t i, j, l;

	for (i = j = 0; s[i]; i++) {
		l = 0;
		if (!strncasecmp(s + i, "force", 5))
			l = concat(s + i, b + j, "first");
		else if (!strncasecmp(s + i, "first", 5))
			l = concat(s + i, b + j, "force");
		else
			b[j++] = s[i];

		if (l) {
			i += l - 1;
			j += l;
		}
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	firstforce(s, b);
	printf("%s\n", b);
	printf("%s\n\n", r);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("ForcefoRcefOrcE", "FirstfiRstfIrsT");
	test("FirstfiRstfIrsT", "ForcefoRcefOrcE");
	test("thirst of forces", "thirst of firsts");
	test("thirst of firsts", "thirst of forces");

	return 0;
}
