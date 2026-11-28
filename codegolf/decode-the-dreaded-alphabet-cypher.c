/*

This challenge is inspired by one of my other challenges: Pointlessly make your way down the alphabet

That challenge asked you to take a string of text, and for each letter produce a sequence of letters moving down the alphabet to 'a'.

For this challenge I'd like to decode the output of that challenge (minus the line breaks), to find a human-readable string from a much longer human readable string.

Here is some text which has been encoded using the Dreaded Alphabet Cypher™️

hgfedcbaedcbalkjihgfedcbalkjihgfedcbaonmlkjihgfedcba wvutsrqponmlkjihgfedcbaonmlkjihgfedcbarqponmlkjihgfedcbalkjihgfedcbadcba

It consists of descending alphabetical sequences, ending in an 'a'. The first character in each of these sequences is a letter in the decoded text. (A space is still a space).

The challenge
Write code to convert a Dreaded Alphabet Cypher™️ encoded string into a decoded, human-readable string.
No need to validate if it is a Dreaded Alphabet Cypher™️ string, I'm not interested in how it handles invalid input.
Use any language you please.
Please include a link to an online iterpreter.
The input will only consist of lower-case letters and spaces. No upper cases, punctuation etc.
Code golf, try to write short code, standard loopholes etc.
Test Cases
Input:

hgfedcbaedcbalkjihgfedcbalkjihgfedcbaonmlkjihgfedcba wvutsrqponmlkjihgfedcbaonmlkjihgfedcbarqponmlkjihgfedcbalkjihgfedcbadcba
Output:

hello world
Input:

abacbadcbaedcbafedcbagfedcbahgfedcbaihgfedcbajihgfedcbakjihgfedcbalkjihgfedcbamlkjihgfedcbanmlkjihgfedcbaonmlkjihgfedcbaponmlkjihgfedcbaqponmlkjihgfedcbarqponmlkjihgfedcbasrqponmlkjihgfedcbatsrqponmlkjihgfedcbautsrqponmlkjihgfedcbavutsrqponmlkjihgfedcbawvutsrqponmlkjihgfedcbaxwvutsrqponmlkjihgfedcbayxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba
Output:

abcdefghijklmnopqrstuvwxyz
(beware the multiple a's)

Input:

aarqponmlkjihgfedcbaonmlkjihgfedcbanmlkjihgfedcba a aarqponmlkjihgfedcbaonmlkjihgfedcbanmlkjihgfedcbasrqponmlkjihgfedcbaonmlkjihgfedcbanmlkjihgfedcba hgfedcbaasrqponmlkjihgfedcba anmlkjihgfedcba aarqponmlkjihgfedcbadcbavutsrqponmlkjihgfedcbaarqponmlkjihgfedcbakjihgfedcba
Output:

aaron a aaronson has an aardvark
Input:

hgfedcbaaponmlkjihgfedcbaponmlkjihgfedcbayxwvutsrqponmlkjihgfedcba gfedcbaonmlkjihgfedcbalkjihgfedcbafedcbaihgfedcbanmlkjihgfedcbagfedcba
Output (is a secret, shh)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
undread(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i];) {
		b[j++] = s[i++];
		while (s[i - 1] > 'a')
			i++;
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[512];

	undread(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("hgfedcbaedcbalkjihgfedcbalkjihgfedcbaonmlkjihgfedcba wvutsrqponmlkjihgfedcbaonmlkjihgfedcbarqponmlkjihgfedcbalkjihgfedcbadcba", "hello world");
	test("abacbadcbaedcbafedcbagfedcbahgfedcbaihgfedcbajihgfedcbakjihgfedcbalkjihgfedcbamlkjihgfedcbanmlkjihgfedcbaonmlkjihgfedcbaponmlkjihgfedcbaqponmlkjihgfedcbarqponmlkjihgfedcbasrqponmlkjihgfedcbatsrqponmlkjihgfedcbautsrqponmlkjihgfedcbavutsrqponmlkjihgfedcbawvutsrqponmlkjihgfedcbaxwvutsrqponmlkjihgfedcbayxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba", "abcdefghijklmnopqrstuvwxyz");
	test("aarqponmlkjihgfedcbaonmlkjihgfedcbanmlkjihgfedcba a aarqponmlkjihgfedcbaonmlkjihgfedcbanmlkjihgfedcbasrqponmlkjihgfedcbaonmlkjihgfedcbanmlkjihgfedcba hgfedcbaasrqponmlkjihgfedcba anmlkjihgfedcba aarqponmlkjihgfedcbadcbavutsrqponmlkjihgfedcbaarqponmlkjihgfedcbakjihgfedcba", "aaron a aaronson has an aardvark");
	test("hgfedcbaaponmlkjihgfedcbaponmlkjihgfedcbayxwvutsrqponmlkjihgfedcba gfedcbaonmlkjihgfedcbalkjihgfedcbafedcbaihgfedcbanmlkjihgfedcbagfedcba", "happy golfing");

	return 0;
}
