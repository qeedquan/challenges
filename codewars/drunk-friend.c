/*

You're hanging out with your friends in a bar, when suddenly one of them is so drunk, that he can't speak, and when he wants to say something, he writes it down on a paper. However, none of the words he writes make sense to you. He wants to help you, so he points at a beer and writes "yvvi". You start to understand what he's trying to say, and you write a script, that decodes his words.

Keep in mind that numbers, as well as other characters, can be part of the input, and you should keep them like they are. You should also test if the input is a string. If it is not, return "Input is not a string".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
decode(const char *s, char *b)
{
	size_t i;
	int c;

	if (!s) {
		sprintf(b, "Input is not a string");
		return b;
	}

	for (i = 0; s[i]; i++) {
		b[i] = s[i];

		c = tolower(s[i]);
		if ('a' <= c && c <= 'z') {
			if (isupper(s[i]))
				b[i] = 'A' + 'z' - c;
			else
				b[i] = 'a' + 'z' - c;
		}
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	decode(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("yvvi", "beer");
	test("Blf zoivzwb szw 10 yvvih", "You already had 10 beers");
	test("Ovg'h hdrn rm gsv ulfmgzrm!", "Let's swim in the fountain!");
	test("Tl slnv, blf'iv wifmp", "Go home, you're drunk");

	return 0;
}
