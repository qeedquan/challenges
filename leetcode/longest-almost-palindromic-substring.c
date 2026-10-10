/*

You are given a string s consisting of lowercase English letters.

A substring is almost-palindromic if it becomes a palindrome after removing exactly one character from it.

Return an integer denoting the length of the longest almost-palindromic substring in s.

Example 1:

Input: s = "abca"

Output: 4

Explanation:

Choose the substring "abca".

Remove "abca".
The string becomes "aba", which is a palindrome.
Therefore, "abca" is almost-palindromic.

Example 2:

Input: s = "abba"

Output: 4

Explanation:

Choose the substring "abba".

Remove "abba".
The string becomes "aba", which is a palindrome.
Therefore, "abba" is almost-palindromic.

Example 3:

Input: s = "zzabba"

Output: 5

Explanation:

Choose the substring "zzabba".

Remove "zabba".
The string becomes "abba", which is a palindrome.
Therefore, "zabba" is almost-palindromic.


Constraints:

2 <= s.length <= 2500
s consists of only lowercase English letters.

Hint 1
Solve greedily

Hint 2
Fix the center (consider both odd and even centers) and expand outwards

Hint 3
On the first mismatch, try skipping the left character and continue expanding, and also try skipping the right character; take the longer result

Hint 4
Track the maximum length found across all centers

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

vlong
min(vlong a, vlong b)
{
	return (a < b) ? a : b;
}

vlong
max(vlong a, vlong b)
{
	return (a > b) ? a : b;
}

vlong
length(const char *s, vlong n, vlong l, vlong r)
{
	vlong l1, l2;
	vlong r1, r2;

	while (l >= 0 && r < n && s[l] == s[r]) {
		l -= 1;
		r += 1;
	}

	l1 = l - 1;
	r1 = r;
	l2 = l;
	r2 = r + 1;
	while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
		l1 -= 1;
		r1 += 1;
	}
	while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
		l2 -= 1;
		r2 += 1;
	}

	return min(n, max(r1 - l1 - 1, r2 - l2 - 1));
}

vlong
almost_palindromic(const char *s)
{
	vlong i, n, r;

	n = strlen(s);
	r = 0;
	for (i = 0; i < n; i++)
		r = max(r, max(length(s, n, i, i), length(s, n, i, i + 1)));
	return r;
}

int
main()
{
	assert(almost_palindromic("abca") == 4);
	assert(almost_palindromic("abba") == 4);
	assert(almost_palindromic("zzabba") == 5);

	return 0;
}
