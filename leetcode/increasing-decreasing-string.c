/*

You are given a string s. Reorder the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

Example 1:

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
copyto(char *b, size_t h[256], size_t i, size_t j)
{
	size_t n;

	n = 0;
	while (i != j) {
		if (h[i]) {
			b[n++] = i;
			h[i]--;
		}

		if (i < j)
			i++;
		else if (i > j)
			i--;
	}
	return n;
}

char *
ids(const char *s, char *b)
{
	size_t h[256];
	size_t i, j, k;
	char *p;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	p = b;
	do {
		j = copyto(p, h, 0, nelem(h));
		p += j;

		k = copyto(p, h, nelem(h) - 1, 0);
		p += k;
	} while (j && k);
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	ids(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("aaaabbbbcccc", "abccbaabccba");
	test("rat", "art");
	test("", "");

	return 0;
}
