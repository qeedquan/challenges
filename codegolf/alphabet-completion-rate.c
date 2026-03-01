/*

Introduction
How much of the English alphabet does a given string use? The previous sentence uses 77%. It has 20 unique letters (howmucftenglisapbdvr), and 20/26 ≃ 0.77.

Challenge
For an input string, return the percentage of letters of the English alphabet present in the string.

The answer can be in percentage or in decimal form.

The input string can have upper and lower case, as well as punctuation. However you can assume they have no diacritics or accentuated characters.

Test cases
Input

"Did you put your name in the Goblet of Fire, Harry?" he asked calmly.
Some valid outputs

77%, 76.9, 0.7692
Input:

The quick brown fox jumps over the lazy dog
All valid outputs:

100%, 100, 1
The expected output for "@#$%^&*?!" and "" is 0.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double
completion(const char *s)
{
	size_t h[256];
	size_t i;
	double c;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[tolower(s[i]) & 0xff] = 1;

	c = 0;
	for (i = 'a'; i <= 'z'; i++)
		c += h[i];
	return c / 26;
}

void
test(const char *s, double r)
{
	double c;

	c = completion(s);
	printf("%f\n", c);
	assert(fabs(c - r) < 1e-3);
}

int
main(void)
{
	test("How much of the English alphabet does a given string use?", 0.77);
	test("\"Did you put your name in the Goblet of Fire, Harry?\" he asked calmly.", 0.7692);
	test("The quick brown fox jumps over the lazy dog", 1);
	test("@#$%^&*?!", 0);

	return 0;
}
