/*

Given a string as input, return a new string with each letter pushed to the right by its respective index in the alphabet.

We all know that A is a slow and Z is a fast letter. This means that Z gets shifted to the right by 25 spaces, A doesn't get shifted at all, and B gets shifted by 1 space.

You can assume the following things about your input:

It will only contain uppercase letters from A to Z, no whitespaces or punctuation;
Input strings will not exceed 100 characters (although your output string might!)
Note that if 2 or more letters fall onto the same space after shifting, the latest character will be used. For example: "BA" -> " A"

Examples
"AZ"   -->  "A                         Z"
"ABC"  -->  "A B C"
"ACE"  -->  "A  C  E"
"CBA"  -->  "  A"
"HELLOWORLD"  -->  "     E H    DLL   OLO   R  W"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char *
speedify(const char *s, char *b)
{
	size_t i, m;

	for (i = m = 0; s[i]; i++)
		m = max(m, i + s[i] - 'A');

	memset(b, ' ', m);
	for (i = 0; s[i]; i++)
		b[i + s[i] - 'A'] = s[i];
	b[m + 1] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	speedify(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("AZ", "A                         Z");
	test("ABC", "A B C");
	test("ACE", "A  C  E");
	test("CBA", "  A");
	test("HELLOWORLD", "     E H    DLL   OLO   R  W");
	return 0;
}
