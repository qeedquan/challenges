/*

You are given a string s consisting only of the characters 'a' and 'b'.

You are allowed to repeatedly remove any substring where the number of 'a' characters is equal to the number of 'b' characters. After each removal, the remaining parts of the string are concatenated together without gaps.

Return an integer denoting the minimum possible length of the string after performing any number of such operations.

Example 1:

Input: s = "aabbab"

Output: 0

Explanation:

The substring "aabbab" has three 'a' and three 'b'. Since their counts are equal, we can remove the entire string directly. The minimum length is 0.

Example 2:

Input: s = "aaaa"

Output: 4

Explanation:

Every substring of "aaaa" contains only 'a' characters. No substring can be removed as a result, so the minimum length remains 4.

Example 3:

Input: s = "aaabb"

Output: 1

Explanation:

First, remove the substring "ab", leaving "aab". Next, remove the new substring "ab", leaving "a". No further removals are possible, so the minimum length is 1.

Constraints:

1 <= s.length <= 10^5
s[i] is either 'a' or 'b'.

Hint 1
Remove the longest possible balanced substring initially

Hint 2
Let the count of a's be count_a and the count of b's be count_b. Can we derive the final length from these?

Hint 3
The answer is abs(count_a - count_b)

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
length(const char *s)
{
	size_t a, b;

	for (a = b = 0; *s; s++) {
		a += (*s == 'a');
		b += (*s == 'b');
	}
	return max(a, b) - min(a, b);
}

int
main()
{
	assert(length("aabbab") == 0);
	assert(length("aaaa") == 4);
	assert(length("aaabb") == 1);

	return 0;
}
