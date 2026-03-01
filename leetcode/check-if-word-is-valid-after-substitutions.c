/*

Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.

Example 1:

Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.

Example 2:

Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.

Example 3:

Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.

Constraints:

1 <= s.length <= 2 * 10^4
s consists of letters 'a', 'b', and 'c'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

bool
valid(const char *str)
{
	char *stk;
	size_t sp;
	size_t len;

	len = strlen(str);
	stk = xcalloc(len, sizeof(*stk));
	for (sp = 0; *str; str++) {
		if (*str == 'c') {
			if (sp >= 2 && stk[sp - 2] == 'a' && stk[sp - 1] == 'b')
				sp -= 2;
			else {
				sp = 1;
				goto out;
			}
		} else
			stk[sp++] = *str;
	}

out:
	free(stk);
	return sp == 0;
}

int
main()
{
	assert(valid("aabcbc") == true);
	assert(valid("abcabcababcc") == true);
	assert(valid("abccba") == false);

	return 0;
}
