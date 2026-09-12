/*

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0


Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
histogram(const char *s, size_t h[256])
{
	size_t i;

	memset(h, 0, sizeof(*h) * 256);
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;
}

int
makeable(const char *s, size_t h[256])
{
	size_t i;
	int c;

	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (!h[c])
			return 0;
		h[c]--;
	}
	return 1;
}

int
balloons(const char *s)
{
	size_t h[256];
	int n;

	histogram(s, h);

	n = 0;
	while (makeable("balloon", h))
		n++;

	return n;
}

int
main(void)
{
	assert(balloons("nlaebolko") == 1);
	assert(balloons("loonbalxballpoon") == 2);
	assert(balloons("leetcode") == 0);
	assert(balloons("balloonballoonballoon") == 3);

	return 0;
}
