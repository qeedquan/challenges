/*

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 10^5
s consists of uppercase and lowercase English letters and digits.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
cmp(const void *a, const void *b, void *ud)
{
	size_t *h;
	int x, y;

	h = ud;
	x = *(char *)a & 0xff;
	y = *(char *)b & 0xff;

	if (h[x] > h[y])
		return -1;
	if (h[x] < h[y])
		return 1;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

char *
freqsort(char *s)
{
	size_t h[256];
	size_t i;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	qsort_r(s, i, sizeof(*s), cmp, h);
	return s;
}

void
test(char *s, const char *r)
{
	freqsort(s);
	printf("%s\n", s);
	assert(!strcmp(s, r));
}

int
main(void)
{
	char s1[] = "tree";
	char s2[] = "cccaaa";
	char s3[] = "Aabb";

	test(s1, "eert");
	test(s2, "aaaccc");
	test(s3, "bbAa");

	return 0;
}
