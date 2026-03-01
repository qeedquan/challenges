/*

Duolingo, the language learning app, has a lot of things going for it, but there is one major issue that drives me crazy.
It tells me how many days in a row I've used the app with a message like You're on a 7 day streak!
Setting aside hyphenation and whether the number should be spelled out, this works fine for most numbers, but is indisputably wrong when it says You're on a 8 day streak!
I'm not using it to learn English but this is still unfortunate behavior for a language app.

You're going to help out the Duolingo team by writing a complete program or function that figures out whether a given number should be preceded by a or an.
A number is preceded by a if its pronunciation in spoken English begins with a consonant or semivowel sound, and preceded by an if its pronunciation begins with a vowel sound.
Thus the only numbers preceded by an are those whose pronunciation begins with eight, eleven, eighteen, or eighty.

Presumably the Duolingo dev team left this bug in because they ran out of space for more source code in the app, so you need to make this code as short as possible in the hopes they can squeeze it in.

Your code must take an integer from 0 to 2,147,483,647 and output a or an. A trailing newline is optional. For the purposes of this challenge, 1863 is read as one thousand eight hundred and sixty-three, not eighteen hundred and sixty-three.

Test cases:

0 → a
8 → an
11 → an
18 → an
84 → an
110 → a
843 → an
1111 → a
1863 → a
8192 → an
11000 → an
18000 → an
110000 → a
180000 → a
1141592 → a
1897932 → a
11234567 → an
18675309 → an

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

/*

@xnor:

Adds an n if either:

The first digit is 8
The first two digits are 11 or 18, and the length is 2 modulo 3.

*/

const char *
streak(uvlong n)
{
	char b[sizeof(n) * CHAR_BIT];

	n = snprintf(b, sizeof(b), "%llu", n);
	if (b[0] == '8')
		return "an";
	if (b[0] == '1' && (b[1] == '1' || b[1] == '8') && n % 3 == 2)
		return "an";
	return "a";
}

void
test(uvlong n, const char *r)
{
	const char *s;

	s = streak(n);
	printf("%s\n", s);
	assert(!strcmp(s, r));
}

int
main(void)
{
	test(0, "a");
	test(8, "an");
	test(11, "an");
	test(18, "an");
	test(84, "an");
	test(110, "a");
	test(843, "an");
	test(1111, "a");
	test(1863, "a");
	test(8192, "an");
	test(11000, "an");
	test(18000, "an");
	test(110000ULL, "a");
	test(180000ULL, "a");
	test(1141592ULL, "a");
	test(1897932ULL, "a");
	test(11234567ULL, "an");
	test(18675309ULL, "an");

	return 0;
}
