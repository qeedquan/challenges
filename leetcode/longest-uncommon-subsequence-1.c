/*

Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Note:

    Both strings' lengths will not exceed 100.
    Only letters from a ~ z will appear in input strings.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

ssize_t
lus(const char *s, const char *t)
{
	if (!strcmp(s, t))
		return -1;
	return max(strlen(s), strlen(t));
}

int
main(void)
{
	assert(lus("aba", "cdc") == 3);
	assert(lus("aaa", "bbb") == 3);
	assert(lus("aaa", "aaa") == -1);
	assert(lus("abcd", "abc") == 4);
	assert(lus("abc", "aebdc") == 5);
	assert(lus("aebdc", "aeb") == 5);

	return 0;
}
