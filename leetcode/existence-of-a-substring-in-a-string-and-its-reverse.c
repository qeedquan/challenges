/*

Given a string s, find any substring of length 2 which is also present in the reverse of s.

Return true if such a substring exists, and false otherwise.

Example 1:

Input: s = "leetcode"

Output: true

Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".

Example 2:

Input: s = "abcba"

Output: true

Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".

Example 3:

Input: s = "abcd"

Output: false

Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters.

Hint 1
Make a new string by reversing the string s.

Hint 2
For every substring of length 2 in s, check if there is a corresponding substring in the reverse of s.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
sub(const char *s)
{
	bool p[256][256];
	size_t i;
	int c0, c1;

	memset(p, 0, sizeof(p));
	for (i = 0; s[i] && s[i + 1]; i++) {
		c0 = s[i] & 0xff;
		c1 = s[i + 1] & 0xff;
		p[c0][c1] = true;
	}

	for (i = 0; s[i] && s[i + 1]; i++) {
		c0 = s[i + 1] & 0xff;
		c1 = s[i] & 0xff;
		if (p[c0][c1])
			return true;
	}

	return false;
}

int
main()
{
	assert(sub("leetcode") == true);
	assert(sub("abcba") == true);
	assert(sub("abcd") == false);

	return 0;
}
