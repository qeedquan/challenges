/*

Bob is a theoretical coder - he doesn't write code, but comes up with theories, formulas and algorithm ideas.
You are his secretary, and he has tasked you with writing the code for his newest project - a method for making the short form of a word.
Write a function shortForm(C# ShortForm, Python short_form) that takes a string and returns it converted into short form using the rule:
Remove all vowels, except for those that are the first or last letter.
Do not count 'y' as a vowel, and ignore case.
Also note, the string given will not have any spaces; only one word, and only Roman letters.

Example:

shortForm("assault");
short_form("assault")
ShortForm("assault");
// should return "asslt"


Also, FYI: I got all the words with no vowels from
https://en.wikipedia.org/wiki/English_words_without_vowels

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
shortform(char *s)
{
	size_t i, j;

	if (!s[0])
		return s;

	for (i = j = 1; s[i]; i++) {
		if (strchr("aeiou", tolower(s[i])) && s[i + 1])
			continue;
		s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}

int
main()
{
	char s1[] = "assault";

	assert(!strcmp(shortform(s1), "asslt"));

	return 0;
}
