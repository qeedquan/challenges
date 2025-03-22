/*

DropCaps means that the first letter of the starting word of the paragraph should be in caps and the remaining lowercase, just like you see in the newspaper.

But for a change, let"s do that for each and every word of the given String. Your task is to capitalize every word that has length greater than 2, leaving smaller words as they are.

*should work also on Leading and Trailing Spaces and caps.

"apple"            => "Apple"
"apple of banana"  => "Apple of Banana"
"one   space"      => "One   Space
"   space WALK   " => "   Space Walk   "

Note: you will be provided atleast one word and should take string as input and return string as output.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
dropcaps(const char *s, char *b)
{
	size_t i, j;

	i = 0;
	for (;;) {
		for (; isspace(s[i]); i++)
			b[i] = s[i];

		if (!s[i])
			break;

		for (j = i; s[j] && !isspace(s[j]); j++)
			b[j] = tolower(s[j]);

		if (j - i <= 2) {
			b[i] = s[i];
			b[i + 1] = s[i + 1];
		} else
			b[i] = toupper(s[i]);

		i = j;
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	dropcaps(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("apple", "Apple");
	test("apple of banana", "Apple of Banana");
	test("one   space", "One   Space");
	test("   space WALK   ", "   Space Walk   ");
	test("Apple Banana", "Apple Banana");
	test("Apple", "Apple");
	test("", "");
	test("of", "of");
	test("Revelation of the contents outraged American public opinion, and helped generate", "Revelation of The Contents Outraged American Public Opinion, And Helped Generate");
	test("more  than    one space between words", "More  Than    One Space Between Words");
	test("  leading spaces", "  Leading Spaces");
	test("trailing spaces   ", "Trailing Spaces   ");
	test("ALL CAPS CRAZINESS", "All Caps Craziness");
	test("rAnDoM CaPs CrAzInEsS", "Random Caps Craziness");
	test("ab", "ab");
	test("a b c d e f", "a b c d e f");
	test("x", "x");

	return 0;
}
