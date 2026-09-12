/*

Output any 200 words from Wordnik without using external sources. Any case. No repeated or extra words. Code golf.
https://raw.githubusercontent.com/wordnik/wordlist/refs/heads/main/wordlist-20210729.txt

*/

#include <stdio.h>

// ported from @Albert.Lang solution
void
output()
{
	static const char c0[] = "aeiou";
	static const char c1[] = "vlnslnsfgprtfgprtfgprtbdhmbdhmbdhmbdhmbd";
	static const char c2[] = "ggtndbgrttttnnsmngepdgtptssnpmngnggemddb";

	size_t i, j;

	for (i = 0; c0[i]; i++) {
		for (j = 0; c1[j] && c2[j]; j++) {
			printf("%c%c%c\n", c1[j], c0[i], c2[j]);
		}
	}
}

int
main()
{
	output();
	return 0;
}
