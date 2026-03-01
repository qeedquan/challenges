/*

Given a word, your task is to compact it by saving its first character and removing any other vowel (aeiou).

Input
Your input can be the word in STDIN, a function argument or any other input format that doesn't break the standard loopholes. You can assume the input only consists of lower characters.

Output
Your output must be the word, compacted.

Examples
i -> i
ate -> at
potato -> ptt
ksboejqfgcrauxpwivtzndlhmy -> ksbjqfgcrxpwvtzndlhmy
Score
This is a code-golf, so shortest answer in bytes wins, good luck!

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
compactify(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (i == 0 || !isvowel(s[i]))
			b[j++] = s[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	compactify(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("i", "i");
	test("ate", "at");
	test("potato", "ptt");
	test("ksboejqfgcrauxpwivtzndlhmy", "ksbjqfgcrxpwvtzndlhmy");

	return 0;
}
