/*

Write a function

vowel2index(str)
that takes in a string and replaces all the vowels [a,e,i,o,u] with their respective positions within that string.
E.g:

vowel2index('this is my string') == 'th3s 6s my str15ng'
vowel2index('Codewars is the best site in the world') == 'C2d4w6rs 10s th15 b18st s23t25 27n th32 w35rld'
vowel2index('') == ''
Your function should be case insensitive to the vowels.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
vowel2index(const char *s, char *b)
{
	size_t i;
	char *p;

	p = b;
	for (i = 0; s[i]; i++) {
		if (strchr("aeiou", tolower(s[i])))
			p += sprintf(p, "%zu", i + 1);
		else
			*p++ = s[i];
	}
	*p = '\0';
	return p;
}

void
test(const char *s, const char *r)
{
	char b[128];

	vowel2index(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("this is my string", "th3s 6s my str15ng");
	test("Codewars is the best site in the world", "C2d4w6rs 10s th15 b18st s23t25 27n th32 w35rld");
	test("", "");
	return 0;
}
