/*

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.



Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true


Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

Follow up: Could you solve it using only O(s2.length) additional memory space?

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool
interleaved(const char *s1, const char *s2, const char *s3)
{
	bool *p, r;
	size_t i, j;
	size_t m, n;

	m = strlen(s1);
	n = strlen(s2);
	if (m + n != strlen(s3))
		return false;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return false;

	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (i == 0 && j == 0)
				p[j] = true;
			else if (i == 0)
				p[j] = p[j - 1] && (s2[j - 1] == s3[j - 1]);
			else if (j == 0)
				p[j] = p[j] && (s1[i - 1] == s3[i - 1]);
			else {
				p[j] = (p[j] && (s1[i - 1] == s3[i + j - 1])) ||
				       (p[j - 1] && (s2[j - 1] == s3[i + j - 1]));
			}
		}
	}
	r = p[n];

	free(p);
	return r;
}

int
main(void)
{
	assert(interleaved("aabcc", "dbbca", "aadbbcbcac") == true);
	assert(interleaved("aabcc", "dbbca", "aadbbbaccc") == false);
	assert(interleaved("", "", "") == true);

	return 0;
}
