/*

Given a string S, return the number of substrings that have only one distinct letter.

Example 1:

Input: S = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.

Example 2:

Input: S = "aaaaaaaaaa"
Output: 55

Constraints:

1 <= S.length <= 1000
S[i] consists of only lowercase English letters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
count(const char *s)
{
	size_t c, n;
	size_t l, r;

	n = strlen(s);
	c = n;
	l = 0;
	for (r = 1; r < n; r++) {
		if (s[r] == s[l])
			c += r - l;
		else
			l = r;
	}
	return c;
}

int
main()
{
	assert(count("aaaba") == 8);
	assert(count("aaaaaaaaaa") == 55);

	return 0;
}
