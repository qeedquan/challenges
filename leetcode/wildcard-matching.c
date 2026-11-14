/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/

#include <assert.h>
#include <stdio.h>

bool
match(const char *s, const char *p)
{
	const char *last_s, *last_p;

	last_s = NULL;
	last_p = NULL;
	while (*s != '\0') {
		if (*p == '*') {
			p++;
			if (*p == '\0')
				return true;
			last_s = s;
			last_p = p;
		} else if (*p == '?' || *s == *p) {
			s++;
			p++;
		} else if (last_s != NULL) {
			p = last_p;
			s = ++last_s;
		} else
			return false;
	}

	while (*p == '*')
		p++;

	return *p == '\0';
}

int
main()
{
	assert(match("aa", "a") == false);
	assert(match("aa", "aa") == true);
	assert(match("aaa", "aa") == false);
	assert(match("aa", "*") == true);
	assert(match("aa", "a*") == true);
	assert(match("ab", "?*") == true);
	assert(match("aab", "c*a*b") == false);
	assert(match("cb", "?a") == false);

	return 0;
}
