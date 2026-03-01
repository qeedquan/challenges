/*

Complete the function scramble(str1, str2) that returns true if a portion of str1
characters can be rearranged to match str2, otherwise returns false.

## Notes:

* Only lower case letters will be used (a-z). No punctuation or digits will be included.
* Performance needs to be considered.

## Examples

scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> False

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
scramble(const char *s1, const char *s2)
{
	size_t h[256];
	const char *s;
	int c;

	memset(h, 0, sizeof(h));
	for (s = s1; (c = *s & 0xff); s++)
		h[c]++;

	for (s = s2; (c = *s & 0xff); s++) {
		if (!h[c])
			return false;
		h[c]--;
	}
	return true;
}

int
main()
{
	assert(scramble("rkqodlw", "world") == true);
	assert(scramble("cedewaraaossoqqyt", "codewars") == true);
	assert(scramble("katas", "steak") == false);
	assert(scramble("katas", "steak") == false);
	assert(scramble("scriptjavx", "javascript") == false);
	assert(scramble("scriptingjava", "javascript") == true);
	assert(scramble("scriptsjava", "javascripts") == true);
	assert(scramble("javscripts", "javascript") == false);
	assert(scramble("aabbcamaomsccdd", "commas") == true);
	assert(scramble("commas", "commas") == true);
	assert(scramble("sammoc", "commas") == true);

	return 0;
}
