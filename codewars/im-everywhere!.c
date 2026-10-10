/*

Overview
Many people know that Apple uses the letter "i" in almost all of its devices to emphasize its personality.

And so John, a programmer at Apple, was given the task of making a program that would add that letter to every word. Let's help him do it, too.

Task:
Your task is to make a function that takes the value of word and returns it with an "i" at the beginning of the word. For example we get the word "Phone", so we must return "iPhone". But we have a few rules:

The word should not begin with the letter "I", for example Inspire.
The number of vowels should not be greater than or equal to the number of consonants, for example East or Peace. ("y" is considered a consonant)
The first letter should not be lowercase, for example road.

If the word does not meet the rules, we return "Invalid word".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
iword(const char *s, char *b)
{
	size_t i;
	int c, v;

	if (s[0] == 'I' || islower(s[0]))
		goto error;

	c = v = 0;
	for (i = 0; s[i]; i++) {
		if (strchr("aeiou", tolower(s[i])))
			v++;
		else if (isalpha(s[i]))
			c++;
	}
	if (v >= c)
		goto error;

	sprintf(b, "i%s", s);

	if (0) {
	error:
		strcpy(b, "Invalid word");
	}

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	iword(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Phone", "iPhone");
	test("World", "iWorld");
	test("Human", "iHuman");
	test("Programmer", "iProgrammer");

	test("", "Invalid word");
	test("Inspire", "Invalid word");
	test("East", "Invalid word");
	test("Peace", "Invalid word");
	test("road", "Invalid word");

	return 0;
}
