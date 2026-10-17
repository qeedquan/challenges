/*

Implement PatternToNumber
Convert a DNA string to a number.

Given: A DNA string Pattern.

Return: PatternToNumber(Pattern).

Sample Dataset
AGT
Sample Output
11

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
pat2num(const char *s)
{
	size_t i;
	uvlong r, v;

	r = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'A':
		default:
			v = 0;
			break;
		case 'C':
			v = 1;
			break;
		case 'G':
			v = 2;
			break;
		case 'T':
			v = 3;
			break;
		}
		r = (r * 4) + v;
	}
	return r;
}

int
main()
{
	assert(pat2num("AGT") == 11);
	assert(pat2num("ACCATTTATCCTCGATCAAGCGGA") == 23076177920616);
	return 0;
}
