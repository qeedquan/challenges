/*

Given an input string containing only alphanumeric ASCII characters and starting with a letter, swap each letter run with the digit run which follows.

A run is a sequence of consecutive letters or digits. Note that in the case where the input string ends with a run of letters, this run is left untouched.

Walk-through example

For instance, given the input string uV5Pt3I0:

Separate runs of letters and runs of digits: uV 5 Pt 3 I 0
Identify pairs of runs: (uV 5) (Pt 3) (I 0)
Swap pairs of runs: (5 uV) (3 Pt) (0 I)
Concatenate: 5uV3Pt0I

Examples

uV5Pt3I0 -> 5uV3Pt0I
J0i0m8 -> 0J0i8m
abc256 -> 256abc
Hennebont56Fr -> 56HennebontFr
Em5sA55Ve777Rien -> 5Em55sA777VeRien
nOoP -> nOoP

This is code-golf so the shortest answer in bytes wins. Explanations are encouraged.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
swapld(const char *s, char *b)
{
	size_t i, j, k, l;

	for (i = l = 0; s[i]; i = k) {
		j = i;
		while (s[j] && !isdigit(s[j]))
			j++;

		k = j;
		while (s[k] && isdigit(s[k]))
			k++;

		memmove(b + l, s + j, k - j);
		l += k - j;

		memmove(b + l, s + i, j - i);
		l += j - i;
	}
	b[l] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	swapld(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("uV5Pt3I0", "5uV3Pt0I");
	test("J0i0m8", "0J0i8m");
	test("abc256", "256abc");
	test("Hennebont56Fr", "56HennebontFr");
	test("Em5sA55Ve777Rien", "5Em55sA777VeRien");
	test("nOoP", "nOoP");
	test("", "");

	return 0;
}
