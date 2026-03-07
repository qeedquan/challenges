/*

Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

Constraints:

    1 <= s.length <= 1000
    s consists of lowercase English letters.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
occurences(const char *s)
{
	size_t h[256];
	size_t i, m;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	for (i = m = 0; i < nelem(h); i++) {
		if (!m)
			m = h[i];

		if (h[i] && h[i] != m)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(occurences("abacbc") == true);
	assert(occurences("aaabb") == false);

	return 0;
}
