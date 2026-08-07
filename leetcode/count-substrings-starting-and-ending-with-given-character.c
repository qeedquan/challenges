/*

You are given a string s and a character c. Return the total number of substrings of s that start and end with c.

Example 1:

Input: s = "abada", c = "a"

Output: 6

Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".

Example 2:

Input: s = "zzz", c = "z"

Output: 6

Explanation: There are a total of 6 substrings in s and all start and end with "z".

Constraints:

1 <= s.length <= 10^5
s and c consist only of lowercase English letters.

Hint 1
Count the number of characters 'c' in string s, let’s call it m.

Hint 2
We can select 2 numbers i and j such that i <= j are the start and end indices of substring. Note that i and j can be the same.

Hint 3
The answer is m * (m + 1) / 2.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
substrings(const char *s, int c)
{
	vlong n;

	for (n = 0; *s; s++) {
		if (*s == c)
			n += 1;
	}
	return ((n + 1) * n) / 2;
}

int
main()
{
	assert(substrings("abada", 'a') == 6);
	assert(substrings("zzz", 'z') == 6);

	return 0;
}
