/*

Concept
Remembering numbers can be difficult. Remembering a word may be easier. In order to memorize big numbers, I created a way to pronounce them in a leetspeak-like way.

Rules
Each digit is first replaced by its corresponding letter:

0 => O
1 => I
2 => R
3 => E
4 => A
5 => S
6 => G
7 => T
8 => B
9 => P
After the replacement, two additional things are done to improved pronunciation:

Between two consonants, a U is added.

Between two vowels, a N is added.

Examples/test cases
512431 => SIRANENI
834677081 => BENAGUTUTOBI
3141592 => ENINANISUPUR
1234567890 => IRENASUGUTUBUPO
6164817 => GIGABIT
What's impossible
Letters and numbers mixed in the same word
Two successive consonants or two successive vowels
Letters that are not in the list above
Other characters

Rules
The goal of this code-golf is to create a 2-way translator for this concept.

Your program must first understand by itself if it's letter-to-number or number-to-letter translation.
It must check for the entry to be properly formed.
If everything is correct, display the translation.
Else, display an error message, nothing, return a falsey value or crash the program.

Details
The input number/string can be entered in whatever format you want (stdin, argument, ...)
This is code-golf, so shortest answer wins.
Standard loopholes are forbidden.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

char *
pronounce(const char *s, char *b)
{
	static const char sym[256] = {
	    ['0'] = 'O',
	    ['1'] = 'I',
	    ['2'] = 'R',
	    ['3'] = 'E',
	    ['4'] = 'A',
	    ['5'] = 'S',
	    ['6'] = 'G',
	    ['7'] = 'T',
	    ['8'] = 'B',
	    ['9'] = 'P',
	};

	size_t i, j;
	int b0, b1;
	int c0, c1;

	for (i = j = 0; s[i]; i++) {
		c0 = s[i] & 0xff;
		c1 = s[i + 1] & 0xff;
		if (!sym[c0])
			return NULL;

		b[j++] = sym[c0];
		if (c1 == '\0')
			continue;

		b0 = isvowel(sym[c0]);
		b1 = isvowel(sym[c1]);
		if (b0 && b1)
			b[j++] = 'N';
		else if (!b0 && !b1)
			b[j++] = 'U';
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	pronounce(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("512431", "SIRANENI");
	test("834677081", "BENAGUTUTOBI");
	test("3141592", "ENINANISUPUR");
	test("1234567890", "IRENASUGUTUBUPO");
	test("6164817", "GIGABIT");

	return 0;
}
