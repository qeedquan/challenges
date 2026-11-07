/*

Input
Input may be a string or an array/list of English letters (a-z, A-Z) of even length.

Output
The output should be a string or an array of characters in which each consecutive pair (A, B) is lowercased if the alphabetical index of A (ignoring case) is less than that of B; otherwise, both letters are uppercased.

Example
Consider this input:

TheQuickBrownFoxJumpsOverTheLazyDogs
Process the string in consecutive, non-overlapping pairs. If the first letter comes alphabetically before the second, lowercase both letters; otherwise, uppercase both letters. Ignore the original capitalization when comparing letters.

For example:

Th → TH because t > h.
eQ → eq because e < q.
ui → UI because u > i.
ck → ck because c < k.
The output is:

THeqUIckbrowNFoxjumpSOVErtHELAZYdogs
Rules and Scoring
The input is a nonempty string or array/list of English letters (a–z, A–Z) of even length.
Process the input in consecutive, non-overlapping pairs of letters.
For each pair (A, B), compare their alphabetical positions, ignoring their original case.
If A comes alphabetically before B, lowercase both letters; otherwise, uppercase both letters. Equal letters must therefore be uppercased.
Preserve the order of all characters.
You may submit a full program or a function. The output may be a string or an array/list of characters. The lowest byte count wins, and standard loopholes are disallowed.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
paircase(char *s)
{
	int c0, c1;
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i += 2) {
		c0 = tolower(s[i]);
		c1 = tolower(s[i + 1]);
		if (c0 < c1) {
			s[i] = c0;
			s[i + 1] = c1;
		} else {
			s[i] = toupper(s[i]);
			s[i + 1] = toupper(s[i + 1]);
		}
	}
	return s;
}

void
test(char *s, const char *r)
{
	paircase(s);
	puts(s);
	assert(!strcmp(s, r));
}

int
main()
{
	char s1[] = "TheQuickBrownFoxJumpsOverTheLazyDogs";
	char r1[] = "THeqUIckbrowNFoxjumpSOVErtHELAZYdogs";

	test(s1, r1);

	return 0;
}
