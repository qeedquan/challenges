/*

Create a function that takes any sentence and redistributes the spaces (and adds additional spaces if needed) so that each word starts with a vowel. The letters should all be in the same order but every vowel in the sentence should be the start of a new word. The first word in the new sentence may start without a vowel. It should return a string in all lowercase with no punctuation (only alphanumeric characters).

EXAMPLES
'It is beautiful weather today!' => 'it isb e a ut if ulw e ath ert od ay'
'Coding is great' => 'c od ing isgr e at'
'my number is 0208-533-2325' => 'myn umb er is02085332325'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

void
vowelstart(const char *s, char *b)
{
	char *p;

	p = b;
	for (;;) {
		while (*s && !isalpha(*s))
			s++;

		if (!*s)
			break;

		*p++ = tolower(*s++);
		for (; *s && !isvowel(*s); s++) {
			if (isalnum(*s))
				*p++ = tolower(*s);
		}
		*p++ = ' ';
	}
	if (p != b)
		p[-1] = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	vowelstart(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("It is beautiful weather today!", "it isb e a ut if ulw e ath ert od ay");
	test("Coding is great", "c od ing isgr e at");
	test("my number is 0208-533-2325", "myn umb er is02085332325");
	test("oranges, apples, melon, pineapple", "or ang es appl esm el onp in e appl e");
	test("under_score", "und ersc or e");

	return 0;
}
