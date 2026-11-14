/*

Challenge
You will be given a string that can contain lowercase letters, uppercase letters, or spaces. You have to turn the vowels (a, e, i, o, u) in the string to upper case and consonants to lower case. This applies whether or not the letter was originally upper case or lower case. Spaces remain as is. Note that "y" is a consonant.

Examples
Hello World -> hEllO wOrld
abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVXWYZ -> AbcdEfghIjklmnOpqrstUvwxyz AbcdEfghIjklmnOpqrstUvxwyz

Info
The input string can contain letters A to Z, lowercase or uppercase, and spaces.

Input
The string

Output
The formatted string (Vowels uppercase and consonants lowercase).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
vucd(const char *s, char *b)
{
	size_t i;

	for (i = 0; (b[i] = s[i]); i++) {
		if (strchr("aeiou", tolower(s[i])))
			b[i] = toupper(s[i]);
		else
			b[i] = tolower(s[i]);
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	vucd(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello World", "hEllO wOrld");
	test("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVXWYZ", "AbcdEfghIjklmnOpqrstUvwxyz AbcdEfghIjklmnOpqrstUvxwyz");

	return 0;
}
