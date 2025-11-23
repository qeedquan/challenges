/*

Life isn't always easy as a small word amongst big words. If only they had a code warrior to help them out...

Your task is to make all words which are 3 characters or less into capitals. You should also remove any vowels from 'long' (4 characters or more) words.

For example:

"The quick brown fox jumps over the lazy dog"

Should become:

"THE qck brwn FOX jmps vr THE lzy DOG"

For the purposes of this kata, mid-word punctuation counts towards the character limit of a word.

e.g: "it's / I'm" should become: "t's / I'M"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
smallword(const char *s, char *b)
{
	const char *t;
	size_t n;

	while (*s) {
		while (isspace(*s))
			*b++ = *s++;

		t = s;
		while (*t && !isspace(*t))
			t++;

		for (n = t - s; s != t; s++) {
			if (n <= 3)
				*b++ = toupper(*s);
			else if (*s && !strchr("aeiou", tolower(*s)))
				*b++ = *s;
		}
	}
	*b = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	smallword(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("The quick brown fox jumps over the lazy dog", "THE qck brwn FOX jmps vr THE lzy DOG");
	test("it's / I'm", "t's / I'M");

	return 0;
}
