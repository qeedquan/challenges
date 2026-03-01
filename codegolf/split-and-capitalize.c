/*

Challenge :
Given a string split at specific positions and capitalize the first character of the given word. Capitalize the first word's first char if and only if it was already capitalized

Input :
A string s and a character c.

Ouput :
The string with each occurrence of c replaced with the first char capitalized

Examples :
STRING(s)             CHARACTER(c)  RESULT
Hello_world           _             HelloWorld
me,no,like            ,             meNoLike
you-got-it            -             youGotIt
Am^I^clear            ^             AmIClear
go!full!caps          !             goFullCaps
weird&but&tRue        &             weirdButTRue
ProbleM1fixed1no      1             ProbleMFixedNo
!prob!!lem!s!Olved!!  !             ProbLemSOlved

Note :
Given input will always be valid. i.e : The first will always be a string with at least one instance of the character to replace at. The second will always will be a single character.
The length of the input string will be greater 4.
There will be at least one occurrence of the character to split at.

The input is guaranteed to contain only letters and the separator (Thanks @Arnauld)

Separator is anything that is not an alphabet (a-z / A-Z) (suggested by @Dennis)
Winning criteria :
This is code-golf so shortest code in bytes for each language wins.

Thanks to @JonathanAllan for pointing out two mistakes.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
splitcap(const char *s, int c, char *b)
{
	size_t i, j;
	int f;

	f = 0;
	for (i = j = 0; s[i]; i++) {
		if (s[i] == c)
			f = 1;
		else {
			b[j++] = (f) ? toupper(s[i]) : s[i];
			f = 0;
		}
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, int c, const char *r)
{
	char b[128];

	splitcap(s, c, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Hello_world", '_', "HelloWorld");
	test("me,no,like", ',', "meNoLike");
	test("you-got-it", '-', "youGotIt");
	test("Am^I^clear", '^', "AmIClear");
	test("go!full!caps", '!', "goFullCaps");
	test("weird&but&tRue", '&', "weirdButTRue");
	test("ProbleM1fixed1no", '1', "ProbleMFixedNo");
	test("!prob!!lem!s!Olved!!", '!', "ProbLemSOlved");

	return 0;
}
