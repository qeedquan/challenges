/*

Trigrams are a special case of the n-gram, where n is 3. One trigram is a continous sequence of 3 chars in phrase. Wikipedia

return all trigrams for the given phrase
replace spaces with underscore (_)
return an empty string for phrases shorter than 3
Example:

"the quick red" --> "the he_ e_q _qu qui uic ick ck_ k_r _re red"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
trigram(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i] && s[i + 1] && s[i + 2]; i++) {
		b[j++] = isspace(s[i]) ? '_' : s[i];
		b[j++] = isspace(s[i + 1]) ? '_' : s[i + 1];
		b[j++] = isspace(s[i + 2]) ? '_' : s[i + 2];
		b[j++] = ' ';
	}
	if (j)
		j--;
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	trigram(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("the quick red", "the he_ e_q _qu qui uic ick ck_ k_r _re red");
	test("yh", "");
	return 0;
}
