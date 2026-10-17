/*

Return an output string that translates an input string s/$s by replacing each character in s/$s with a number representing the number of times that character occurs in s/$s and separating each number with the character(s) sep/$sep.

freqSeq("hello world", "-"); // => "1-1-3-3-2-1-1-2-1-3-1"
freqSeq("19999999", ":"); // => "1:7:7:7:7:7:7:7"
freqSeq("^^^**$", "x"); // => "3x3x3x2x2x1"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
freqseq(const char *s, const char *e, char *b)
{
	size_t h[256];
	size_t i;
	char *p;
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; (c = s[i] & 0xff); i++)
		h[c]++;

	p = b;
	for (i = 0; (c = s[i] & 0xff); i++)
		p += sprintf(p, "%zu%s", h[c], e);

	if (p != b)
		p[-1] = '\0';
	return b;
}

void
test(const char *s, const char *e, const char *r)
{
	char b[128];

	freqseq(s, e, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("hello world", "-", "1-1-3-3-2-1-1-2-1-3-1");
	test("19999999", ":", "1:7:7:7:7:7:7:7");
	test("^^^**$", "x", "3x3x3x2x2x1");

	return 0;
}
