/*

Unscramble the eggs.

The string given to your function has had an "egg" inserted directly after each consonant. You need to return the string before it became eggcoded.

Example
unscrambleEggs("Beggegeggineggneggeregg"); => "Beginner"
//             "B---eg---in---n---er---"
Kata is supposed to be for beginners to practice regular expressions, so commenting would be appreciated.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
iscons(int c)
{
	return strchr("BCDFGJKLMNPQSTVXZHRWY", toupper(c)) != NULL;
}

char *
unscramble(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i];) {
		b[j++] = s[i++];
		if (iscons(s[i - 1]) && !strncmp(s + i, "egg", 3))
			i += 3;
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[64];

	unscramble(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Beggegeggineggneggeregg", "Beginner");
	test("ceggodegge heggeregge", "code here");
	test("FeggUNegg KeggATeggA", "FUN KATA");

	return 0;
}
