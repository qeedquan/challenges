/*

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".


Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

*/

#include <assert.h>

bool matchhere(const char *regexp, const char *text);
bool matchstar(int c, const char *regexp, const char *text);

bool
match(const char *regexp, const char *text)
{
	if (regexp[0] == '^')
		return matchhere(regexp + 1, text);
	do {
		if (matchhere(regexp, text))
			return true;
	} while (*text++ != '\0');
	return false;
}

bool
matchhere(const char *regexp, const char *text)
{
	if (regexp[0] == '\0')
		return true;
	if (regexp[1] == '*')
		return matchstar(regexp[0], regexp + 2, text);
	if (regexp[0] == '$' && regexp[1] == '\0')
		return *text == '\0';
	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
		return matchhere(regexp + 1, text + 1);
	return false;
}

bool
matchstar(int c, const char *regexp, const char *text)
{
	do {
		if (matchhere(regexp, text))
			return true;
	} while (*text != '\0' && (*text++ == c || c == '.'));
	return false;
}

int
main()
{
	assert(match("aa", "a") == false);
	assert(match("a*", "a") == true);
	assert(match("a*", "aa") == true);
	assert(match(".*", "ab") == true);

	return 0;
}
