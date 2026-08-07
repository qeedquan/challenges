/*

Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:

    For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
    Sum these products for all characters in the string.

Return the reverse degree of s.

Example 1:

Input: s = "abc"

Output: 148

Explanation:

The reversed degree is 26 + 50 + 72 = 148.

Example 2:

Input: s = "zaza"

Output: 160

Explanation:

Constraints:

    1 <= s.length <= 1000
    s contains only lowercase English letters.

Hint 1
Simulate the operations as described.

*/

#include <assert.h>
#include <stdio.h>

int
revdeg(const char *s)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; s[i]; i++)
		r += (i + 1) * (26 - (s[i] - 'a'));
	return r;
}

int
main()
{
	assert(revdeg("abc") == 148);
	assert(revdeg("zaza") == 160);

	return 0;
}
