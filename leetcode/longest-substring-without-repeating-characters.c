/*

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

ssize_t
longest(const char *s)
{
	ssize_t i, l, r;
	ssize_t p[256];
	int c;

	l = -1;
	for (i = 0; i < 256; i++)
		p[i] = -1;

	r = 0;
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (p[c] != -1 && l < p[c])
			l = p[c];

		r = max(r, i - l);
		p[c] = i;
	}
	return r;
}

int
main()
{
	assert(longest("abcabcbb") == 3);
	assert(longest("bbbbb") == 1);
	assert(longest("pwwkew") == 3);
	assert(longest("bbabcdb") == 4);

	return 0;
}
