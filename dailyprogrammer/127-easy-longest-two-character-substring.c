/*

This programming challenge is a classic interview question for software engineers: given a string, find the longest sub-string that contains, at most, two characters.

Author: /u/Regul
Formal Inputs & Outputs
Input Description

Through standard console input, you will be given a string to search, which only contains lower-case alphabet letters.
Output Description

Simply print the longest sub-string of the given string that contains, at most, two unique characters.
If you find multiple sub-strings that match the description, print the last sub-string (furthest to the right).
Sample Inputs & Outputs
Sample Inputs

abbccc
abcabcabcabccc
qwertyytrewq

Sample Outputs

bbccc
bccc
tyyt

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
eat1(const char *s, char *c)
{
	size_t i;

	i = 0;
	while (s[0] && s[0] == s[i])
		i++;

	*c = s[0];
	return i;
}

size_t
eat2(const char *s, char c0, char c1, size_t *nc)
{
	size_t i;
	char c;

	*nc = 0;
	c = s[0];
	for (i = 0; s[i] && (s[i] == c0 || s[i] == c1); i++) {
		if (c != s[i]) {
			c = s[i];
			*nc = 1;
		} else
			*nc += 1;
	}
	return i;
}

char *
sub2(const char *s, char *b)
{
	size_t n0, n1, n2, n3, nm, nl;
	char c0, c1;

	*b = '\0';
	nm = 0;
	n0 = eat1(s, &c0);
	while (*s) {
		n1 = eat1(s + n0, &c1);
		n2 = eat2(s + n0 + n1, c0, c1, &n3);
		if (!n3)
			n3 = n1;

		nl = n0 + n1 + n2;
		if (nl > nm) {
			memcpy(b, s, nl);
			b[nl] = '\0';
			nm = nl;
		}

		s += nl - n3;
		n0 = n3;
		c0 = c1;
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	sub2(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abbccc", "bbccc");
	test("abcabcabcabccc", "bccc");
	test("qwertyytrewq", "tyyt");

	return 0;
}
