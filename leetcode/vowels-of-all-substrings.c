/*

Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.

A substring is a contiguous (non-empty) sequence of characters within a string.

Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.

Example 1:

Input: word = "aba"
Output: 6
Explanation:
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6.

Example 2:

Input: word = "abc"
Output: 3
Explanation:
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.

Example 3:

Input: word = "ltcd"
Output: 0
Explanation: There are no vowels in any substring of "ltcd".


Constraints:

1 <= word.length <= 10^5
word consists of lowercase English letters.

Hint:
Since generating substrings is not an option, can we count the number of substrings a vowel appears in?
How much does each vowel contribute to the total sum?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

uvlong
vowels(const char *s)
{
	size_t i, n;
	uvlong r;

	n = strlen(s);
	r = 0;
	for (i = 0; s[i]; i++) {
		if (strchr("aeiou", s[i]))
			r += (i + 1) * (n - i);
	}
	return r;
}

int
main(void)
{
	assert(vowels("aba") == 6);
	assert(vowels("abc") == 3);
	assert(vowels("ltcd") == 0);

	return 0;
}
