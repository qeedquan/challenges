/*

You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.

Constraints:

1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.

Hint 1
The constraints are small. For all 52 characters, check if they are present in word.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
specials(const char *s)
{
	bool h[256];
	int i, j;
	int c, r;

	memset(h, 0, sizeof(h));
	for (; *s; s++)
		h[*s & 0xff] = true;

	r = 0;
	for (c = 0; c < 26; c++) {
		i = 'a' + c;
		j = 'A' + c;
		if (h[i] == h[j] && h[i])
			r += 1;
	}
	return r;
}

int
main()
{
	assert(specials("aaAbcBC") == 3);
	assert(specials("abc") == 0);
	assert(specials("abBCab") == 1);

	return 0;
}
