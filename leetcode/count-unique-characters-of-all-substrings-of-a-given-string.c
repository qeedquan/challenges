/*

Let's define a function countUniqueChars(s) that returns the number of unique characters in s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Example 1:

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

Example 2:

Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.

Example 3:

Input: s = "LEETCODE"
Output: 92

Constraints:

1 <= s.length <= 10^5
s consists of uppercase English letters only.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

vlong
uniqs(const char *s)
{
	static const vlong mod = 1000000007;

	vlong p[256][2];
	vlong i, r;
	int c;

	for (i = 0; i < 256; i++) {
		p[i][0] = -1;
		p[i][1] = -1;
	}

	r = 0;
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		r = (r + (i - p[c][1]) * (p[c][1] - p[c][0])) % mod;
		p[c][0] = p[c][1];
		p[c][1] = i;
	}

	for (c = 'A'; c <= 'Z'; c++)
		r = (r + (i - p[c][1]) * (p[c][1] - p[c][0])) % mod;

	return r;
}

int
main()
{
	assert(uniqs("ABC") == 10);
	assert(uniqs("ABA") == 8);
	assert(uniqs("LEETCODE") == 92);

	return 0;
}
