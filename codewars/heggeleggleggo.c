/*

Egg Talk.

Insert an "egg" after each consonant. If there are no consonants, there will be no eggs. Argument will consist of a string with only alphabetic characters and possibly some spaces.

eg:

hello => heggeleggleggo

eggs => egegggeggsegg

FUN KATA => FeggUNegg KeggATeggA

////

This Kata is designed for beginners to practice the basics of regular expressions. With this in mind a little bit of commenting in your solution could be very useful.

Check Eloquent Javascript p176

https://regex101.com/#javascript

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
replace(const char *s, char *b)
{
	size_t i;
	char *p;

	p = b;
	for (i = 0; s[i]; i++) {
		*p++ = s[i];
		if (!isspace(s[i]) && !strchr("aeiou", tolower(s[i])))
			p += sprintf(p, "egg");
	}
	*p = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	replace(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("hello", "heggeleggleggo");
	test("eggs", "egegggeggsegg");
	test("FUN KATA", "FeggUNegg KeggATeggA");
	return 0;
}
