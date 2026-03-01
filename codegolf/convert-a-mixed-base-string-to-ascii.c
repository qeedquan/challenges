/*

Given an input of a string with bytes that may be in either binary, octal, or hex, output the string's ASCII equivalent.

Input will be provided in the following format, for example:

501200100001147
which represents

0x50 0o120 0b01000011 0x47
which is equivalent (in ASCII) to

PPCG
Binary, octal, and hex will always be provided with 8, 3, and 2 digits respectively.

For the purposes of this challenge, only printable ASCII must be supported. This is the range 32..126 inclusive. Therefore, it is impossible for there to be ambiguity. Note that

A string represents binary if and only if it starts with a 0 and its second character is either a 0 or a 1. All printable ASCII characters have their high bit off in binary (i.e. start with a 0), and none of them start with 00 or 01 in either hex or octal.

With binary out of the way, note that all printable ASCII characters start with 2-7 in hex and 0-1 in octal. Therefore, it is possible to unambiguously distinguish between hex and octal as well.

You may assume that hex input is provided as either lowercase or uppercase, whichever is more convenient.

Regex makes the parsing portion of the challenge semi-trivial. I don't want to ban the use of regex outright, but if you have a non-regex solution longer than its regex-using counterpart, feel free to post it along with the "real" answer anyway, since I'd be interested to see it as well. :)

Since this is code-golf, the shortest code in bytes will win.

Test cases:

In                   Out
-----------------------------------
501200100001147    | PPCG
5C01101111100      | \o@
313206306400110101 | 12345
2A200530402C       | * + ,
0011111100111111   | ??
<empty string>     | <empty string>

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
lex(const char **s, int *c)
{
	static const struct Base {
		int type;
		int len;
		int base;
		char sym[32];
	} tab[] = {
	    {'x', 2, 16, "0123456789abcdefABCDEF"},
	    {'o', 3, 8, "01234567"},
	    {'b', 8, 2, "01"},
	};

	const struct Base *b;
	const char *p;
	char t[16];
	int i;

	p = *s;
	if (p[0] == '\0')
		return EOF;

	if ('2' <= p[0] && p[0] <= '7')
		b = tab + 0;
	else if (p[0] == '0' && strchr("01", p[1]))
		b = tab + 2;
	else if ('0' <= p[0] && p[0] <= '1')
		b = tab + 1;
	else
		return 'z';

	for (i = 0; i < b->len; i++) {
		if (!strchr(b->sym, p[i]))
			return 'z';
		t[i] = p[i];
	}
	t[i] = '\0';

	*c = strtol(t, NULL, b->base);
	*s = p + i;
	return b->type;
}

char *
conv(const char *s, char *b)
{
	char *p;
	int c;
	int t;

	p = b;
	for (;;) {
		t = lex(&s, &c);
		if (t == EOF)
			break;

		switch (t) {
		case 'x':
		case 'o':
		case 'b':
			*p++ = c;
			break;

		default:
			return NULL;
		}
	}
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[32], *p;

	assert(p = conv(s, b));
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main()
{
	test("501200100001147", "PPCG");
	test("5C01101111100", "\\o@");
	test("313206306400110101", "12345");
	test("2A200530402C", "* + ,");
	test("0011111100111111", "??");
	test("", "");

	return 0;
}
