/*

A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique. 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".

Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".

Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".

Constraints:

    1 <= s.length <= 10^5
    s consists only of lowercase English letters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
fancy(const char *s, char *b)
{
	size_t i, j;
	char *p;

	p = b;
	for (i = 0; s[i]; i = j) {
		j = i;
		while (s[j] == s[i])
			j++;

		*p++ = s[i];
		if (j - i >= 2)
			*p++ = s[i];
	}
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	fancy(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("leeetcode", "leetcode");
	test("aaabaaaa", "aabaa");
	test("aab", "aab");
	test("abc", "abc");
	test("AAAAAAAAAAAAA", "AA");

	return 0;
}
