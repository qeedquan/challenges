/*

Definition
Given some string return an integer whose digits are the number ocurrences of a-z (case insensitive, in alphabetical order) in that string. Any character with 0 instances is skipped. Characters with 10 or more instances will define 2 or more digits of the returned integer. For example, aaaaaaaaaaaaaaaaaaaaaaaaaaad (27 a's followed by d) will return 271.

Input
A single string with one or more letters

Output
An integer or a string representing an integer

Test Cases
Input	Output
acfzzA	2112
Hello World!	1113211
---!&*#$	invalid input, any result is acceptable
---!&*#$a	1
aaaaaaaaaaaaaaaaaaaaaaaaaaad	271
aaaaaaaaaad	101
cccbba	123
abbccc	123

This is code-golf, so the shortest answer in bytes wins! Standard loopholes and rules apply. Tie goes to first poster.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
lettercount(const char *s, char *b)
{
	size_t h[256];
	size_t i, l;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[tolower(s[i]) & 0xff]++;

	l = 0;
	for (i = 'a'; i <= 'z'; i++) {
		if (h[i])
			l += sprintf(b + l, "%zu", h[i]);
	}
	if (!l)
		sprintf(b, "0");
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	lettercount(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("acfzzA", "2112");
	test("Hello World!", "1113211");
	test("---!&*#$", "0");
	test("---!&*#$a", "1");
	test("aaaaaaaaaaaaaaaaaaaaaaaaaaad", "271");
	test("aaaaaaaaaad", "101");
	test("cccbba", "123");
	test("abbccc", "123");

	return 0;
}
