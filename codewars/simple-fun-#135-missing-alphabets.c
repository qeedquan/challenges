/*

Task
Given string s, which contains only letters from a to z in lowercase.

A set of alphabet is given by abcdefghijklmnopqrstuvwxyz.

2 sets of alphabets mean 2 or more alphabets.

Your task is to find the missing letter(s). You may need to output them by the order a-z. It is possible that there is more than one missing letter from more than one set of alphabet.

If the string contains all of the letters in the alphabet, return an empty string ""

Example
For s='abcdefghijklmnopqrstuvwxy'

The result should be 'z'

For s='aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy'

The result should be 'zz'

For s='abbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxy'

The result should be 'ayzz'

For s='codewars'

The result should be 'bfghijklmnpqtuvxyz'

Input/Output
[input] string s
Given string(s) contains one or more set of alphabets in lowercase.

[output] a string
Find the letters contained in each alphabet but not in the string(s). Output them by the order a-z. If missing alphabet is repeated, please repeat them like "bbccdd", not "bcdbcd"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char *
missing(const char *input, char *output)
{
	size_t count[256];
	size_t repeats;
	size_t index;
	int symbol;
	char *buffer;

	memset(count, 0, sizeof(count));
	for (repeats = 0; *input; input++) {
		symbol = *input & 0xff;
		count[symbol] += 1;
		repeats = max(repeats, count[symbol]);
	}

	buffer = output;
	for (symbol = 'a'; symbol <= 'z'; symbol++) {
		for (index = count[symbol]; index < repeats; index++)
			*buffer++ = symbol;
	}
	*buffer = '\0';

	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	missing(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("abcdefghijklmnopqrstuvwxy", "z");
	test("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "zz");
	test("abbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxy", "ayzz");
	test("codewars", "bfghijklmnpqtuvxyz");

	return 0;
}
