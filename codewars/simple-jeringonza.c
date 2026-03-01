/*

Hepellopo!

Jeringonza is a Spanish language game, similar to Pig Latin, played by children in Spain and all over Hispanic America. It consists of adding the letter p after each vowel (a, e, i, o or u) of a word, and repeating the vowel. For example, jeringonza becomes jeperipingoponzapa (or j-epe-r-ipi-ng-opo-nz-apa).

For the purposes of this kata, the input and output are both strings and no input strings will be empty. Also, the added 'p' should match the case of the vowel. So opo for o and EPE for E.

(If you're interested - there's a few extra components in jeringonza, such as how to deal with stressed vowels, but for the purposes of this kata we're keeping it simple)

Gopoopod lupuck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
jeringonza(const char *s, char *b)
{
	char *p;

	for (p = b; *s; s++) {
		*p++ = *s;
		if (strchr("aeiou", tolower(*s))) {
			*p++ = isupper(*s) ? 'P' : 'p';
			*p++ = *s;
		}
	}
	*p = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	jeringonza(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("jeringonza", "jeperipingoponzapa");
	test("jeringonza", "jeperipingoponzapa");
	test("jEringonzA", "jEPEripingoponzAPA");
	test("Played in Spain and across Latin America", "Plapayeped ipin Spapaipin apand apacroposs Lapatipin APAmeperipicapa");
	test("The quick brown fox jumped over the lazy dog", "Thepe qupuipick bropown fopox jupumpeped opoveper thepe lapazy dopog");
	test("Please give this kata some love if you enjoyed it", "Plepeapasepe gipivepe thipis kapatapa sopomepe lopovepe ipif yopoupu epenjopoyeped ipit");

	return 0;
}
