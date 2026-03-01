/*

You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word,
and every lowercase occurrence of c appears before the first uppercase occurrence of c.

Return the number of special letters in word.

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.

Example 3:

Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.


Constraints:

1 <= word.length <= 2 * 10^5
word consists of only lowercase and uppercase English letters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
count(const char *word)
{
	size_t first[256];
	size_t last[256];
	size_t position;
	size_t special;
	size_t i;
	int symbol;
	int lower;
	int upper;

	memset(first, 0, sizeof(first));
	memset(last, 0, sizeof(last));

	for (i = 0; word[i]; i++) {
		symbol = word[i] & 0xff;
		position = i + 1;
		if (first[symbol] == 0)
			first[symbol] = position;
		last[symbol] = position;
	}

	special = 0;
	for (i = 0; i < 26; i++) {
		lower = 'a' + i;
		upper = 'A' + i;
		if (last[lower] > 0 && first[upper] > 0 && last[lower] < first[upper])
			special += 1;
	}

	return special;
}

int
main()
{
	assert(count("aaAbcBC") == 3);
	assert(count("abc") == 0);
	assert(count("AbBCab") == 0);

	return 0;
}
