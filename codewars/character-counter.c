/*

You are going to be given a word. Your job will be to make sure that each character in that word has the exact same number of occurrences. You will return true if it is valid, or false if it is not.

For this kata, capitals are considered the same as lowercase letters. Therefore: "A" == "a"

The input is a string (with no spaces) containing [a-z],[A-Z],[0-9] and common symbols. The length will be 0 < length < 100.

Examples
"abcabc" is a valid word because "a" appears twice, "b" appears twice, and"c" appears twice.
"abcabcd" is NOT a valid word because "a" appears twice, "b" appears twice, "c" appears twice, but "d" only appears once!
"123abc!" is a valid word because all of the characters only appear once in the word.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
valid(const char *input)
{
	size_t count[256];
	size_t index;
	size_t value;
	int symbol;

	memset(count, 0, sizeof(count));
	for (; *input; input++) {
		symbol = tolower(*input);
		count[symbol] += 1;
	}

	value = 0;
	for (index = 0; index < nelem(count); index++) {
		if (!count[index])
			continue;

		if (!value)
			value = count[index];
		else if (value != count[index])
			return false;
	}
	return true;
}

int
main()
{
	assert(valid("abcabc") == true);
	assert(valid("abcabcd") == false);
	assert(valid("123abc!") == true);
	assert(valid("") == true);
	assert(valid("a") == true);
	assert(valid("abcabc") == true);
	assert(valid("Abcabc") == true);
	assert(valid("abc123") == true);
	assert(valid("abcabcd") == false);
	assert(valid("abc!abc!") == true);
	assert(valid("abc:abc") == false);

	return 0;
}
