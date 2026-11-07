/*

Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true

*/

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
permutable(const char *s)
{
	size_t h[256];
	size_t i;
	int c, r;

	memset(h, 0, sizeof(h));
	r = 0;
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if ((++h[c] & 1) == 0)
			r--;
		else
			r++;
	}
	return r <= 1;
}

int
main(void)
{
	assert(permutable("code") == false);
	assert(permutable("aab") == true);
	assert(permutable("carerac") == true);
	assert(permutable("asdsa") == true);

	return 0;
}
