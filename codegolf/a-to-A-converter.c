/*

I'm currently scanning a bunch of handwritten documents and converting them to .txt files. Since I have a terrible handwriting the .jpg->.txt converter converts some of my umlauts to the "normal" letter encased by '

Task
Write a program or a function that:

Is given a string
you can choose any I/O codepage as long as
it supports the characters AEIOUaeiouÄËÏÖÜäëïöü'.
combining diacriticals are prohibited
the Input and Output codepages are the same.
the input will (beside spaces) only contain printable characters from your codepage.
There will only be one solution, thus things like 'a'e' won't appear
Converts all characters in the following set AEIOUaeiou to ÄËÏÖÜäëïöü
If, and only if, they are surrounded by ' characters:
Example: 'a''e' -> äë
If the from string is a single letter.
for example 'AE' does not change at all, outputting as-is.
If the from character is not a character out of AEIOUaeiou that character won't change.
Note: The from character / from string is the one between '.

Testcases
Input
Output
<empty line>

'A'sthetik
Ästhetik

Meinung ist wichtig!
Meinung ist wichtig!

Ich sagte: "Er sagte: 'Ich habe Hunger'"
Ich sagte: "Er sagte: 'Ich habe Hunger'"

Ich sagte: "Er sagte: ''A'sthetik'"
Ich sagte: "Er sagte: 'Ästhetik'"

Hämisch rieb er sich die H'a'nde
Hämisch rieb er sich die Hände

H'a''a'slich isn't a German word
Hääslich isn't a German word

since it's really called h'a'sslich
since it's really called hässlich

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const void *
symbol(int c)
{
	switch (c) {
	case 'A':
		return u8"Ä";
	case 'E':
		return u8"Ë";
	case 'I':
		return u8"Ï";
	case 'O':
		return u8"Ö";
	case 'U':
		return u8"Ü";
	case 'a':
		return u8"ä";
	case 'e':
		return u8"ë";
	case 'i':
		return u8"ï";
	case 'o':
		return u8"ö";
	case 'u':
		return u8"ü";
	}
	return NULL;
}

char *
convert(const char *s, char *b)
{
	const char *c;
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (s[i] != '\'') {
			b[j++] = s[i];
			continue;
		}

		c = symbol(s[i + 1]);
		if (!c || s[i + 2] != '\'') {
			b[j++] = s[i];
			continue;
		}

		j += sprintf(b + j, "%s", c);
		i += 2;
	}
	b[j] = '\0';

	return b;
}

void
test(const void *s, const void *r)
{
	char b[128];

	convert(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(u8"", u8"");
	test(u8"'A'sthetik", u8"Ästhetik");
	test(u8"Meinung ist wichtig!", u8"Meinung ist wichtig!");
	test(u8"Ich sagte: \"Er sagte: 'Ich habe Hunger'\"", u8"Ich sagte: \"Er sagte: 'Ich habe Hunger'\"");
	test(u8"Ich sagte: \"Er sagte: ''A'sthetik'\"", u8"Ich sagte: \"Er sagte: 'Ästhetik'\"");
	test(u8"Hämisch rieb er sich die H'a'nde", u8"Hämisch rieb er sich die Hände");
	test(u8"H'a''a'slich isn't a German word", u8"Hääslich isn't a German word");
	test(u8"since it's really called h'a'sslich", u8"since it's really called hässlich");

	return 0;
}
