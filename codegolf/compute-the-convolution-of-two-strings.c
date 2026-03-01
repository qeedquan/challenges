/*

While implementing polynomial multiplication in Itr I found the following interesting operation on strings

To compute the convolution of two strings (for instance Hello and World) first combine all pairs of letters with indices that add up to the same number (ordered by the index of the first element)

0 -> "HW"
1 -> "Ho" "eW"
2 -> "Hr" "eo" "lW"
3 -> "Hl" "er" "lo" "lW"
4 -> "Hd" "el" "lr" "lo" "oW"
5 -> "ed" "ll" "lr" "oo"
6 -> "ld" "ll" "or"
7 -> "ld" "ol"
8 -> "od"
and then concatenate all these letter pairs into a single string.
Which in this example gives HWHoeWHreolWHlerlolWHdellrlooWedlllrooldllorldolod.

Your task is to implement this operation:
Write a program of function that takes two strings as input and outputs their convolution.

Examples:
"" "Empty" -> ""         // empty string
"Hello" "World" -> "HWHoeWHreolWHlerlolWHdellrlooWedlllrooldllorldolod"
"Code" "Golf" -> "CGCooGCloodGCfoldoeGofdleodfelef"
"123" "ABC" -> "1A1B2A1C2B3A2C3B3C"
"split" " " -> "s p l i t " // note the trailing whitespace
"+-" "12345" -> "+1+2-1+3-2+4-3+5-4-5"
This is code-golf the shortest solution (per language) wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
convolve(const char *s, const char *t, char *b)
{
	size_t i, j, k;
	size_t n, m;
	char *p;

	p = b;
	n = strlen(s);
	m = strlen(t);
	for (i = 0; i < n + m; i++) {
		for (j = 0; j < i; j++) {
			k = i - j - 1;
			if (j < n && k < m) {
				*p++ = s[j];
				*p++ = t[k];
			}
		}
	}
	*p = '\0';
	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	convolve(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("", "Empty", "");
	test("Hello", "World", "HWHoeWHreolWHlerlolWHdellrlooWedlllrooldllorldolod");
	test("Code", "Golf", "CGCooGCloodGCfoldoeGofdleodfelef");
	test("123", "ABC", "1A1B2A1C2B3A2C3B3C");
	test("split", " ", "s p l i t ");
	test("+-", "12345", "+1+2-1+3-2+4-3+5-4-5");

	return 0;
}
