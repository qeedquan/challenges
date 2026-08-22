/*

You are given a string array words.

Find the maximum distance between two distinct indices i and j such that:

words[i] != words[j], and
the distance is defined as j - i + 1.
Return the maximum distance among all such pairs. If no valid pair exists, return 0.

Example 1:

Input: words = ["leetcode","leetcode","codeforces"]

Output: 3

Explanation:

In this example, words[0] and words[2] are not equal, and they have the maximum distance 2 - 0 + 1 = 3.

Example 2:

Input: words = ["a","b","c","a","a"]

Output: 4

Explanation:

In this example words[1] and words[4] have the largest distance of 4 - 1 + 1 = 4.

Example 3:

Input: words = ["z","z","z"]

Output: 0

Explanation:

In this example all the words are equal, thus the answer is 0.

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
maxdistance(const char **s, size_t n)
{
	size_t i;

	if (n == 0)
		return 0;

	for (i = 0; i <= n / 2; i++) {
		if (strcmp(s[n - i - 1], s[i]) || strcmp(s[i], s[n - i - 1]))
			return n - i;
	}
	return 0;
}

int
main()
{
	const char *s1[] = { "leetcode", "leetcode", "codeforces" };
	const char *s2[] = { "a", "b", "c", "a", "a" };
	const char *s3[] = { "z", "z", "z" };

	assert(maxdistance(s1, nelem(s1)) == 3);
	assert(maxdistance(s2, nelem(s2)) == 4);
	assert(maxdistance(s3, nelem(s3)) == 0);

	return 0;
}
