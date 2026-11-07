/*

Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.

It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.

Example 1:

Input: s = "?zs"
Output: "azs"
Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
Example 2:

Input: s = "ubv?w"
Output: "ubvaw"
Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".


Constraints:

1 <= s.length <= 100
s consist of lowercase English letters and '?'.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
xchar(const char *s, size_t i)
{
	int c;

	if (s[i] != '?')
		return s[i];

	for (c = 'a'; c <= 'z'; c++) {
		if (!((i > 0 && c == s[i - 1]) || c == s[i + 1]))
			return c;
	}
	return s[i];
}

char *
modify(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++)
		b[i] = xchar(s, i);
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	modify(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("?zs", "azs");
	test("ubv?w", "ubvaw");
	test("a?b", "acb");

	return 0;
}
