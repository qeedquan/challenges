/*

A very passive-aggressive co-worker of yours was just fired. While he was gathering his things, he quickly inserted a bug into your system which renamed everything to what looks like jibberish. He left two notes on his desk, one reads: "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" while the other reads: "Uif usjdl up uijt lbub jt tjnqmf kvtu sfqmbdf fwfsz mfuufs xjui uif mfuufs uibu dpnft cfgpsf ju".

Rather than spending hours trying to find the bug itself, you decide to try and decode it.

If the input is not a string, your function must return "Input is not a string". Your function must be able to handle capital and lower case letters. You will not need to worry about punctuation.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
decrypt(const char *s, char *b)
{
	static const char sym[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	size_t i;
	char *p;
	int c;

	for (i = 0; (c = s[i]); i++) {
		if (c == 'A')
			c = 'z';
		else if ((p = strchr(sym, c)))
			c = sym[p - sym - 1];
		b[i] = c;
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	decrypt(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Ifmmp", "Hello");
	test("Uif usjdl up uijt lbub jt tjnqmf", "The trick to this kata is simple");
	return 0;
}
