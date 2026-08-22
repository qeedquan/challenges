/*

Problem
In DNA strings, symbols 'A' and 'T' are complements of each other, as are 'C' and 'G'.

The reverse complement of a DNA string s is the string sc formed by reversing the symbols of s, then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC").

Given: A DNA string s of length at most 1000 bp.

Return: The reverse complement s^c of s.

Sample Dataset
AAAACCCGGT
Sample Output
ACCGGGTTTT

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
reverse(char *b, size_t n)
{
	size_t i;
	char t;

	for (i = 0; i < n / 2; i++) {
		t = b[n - i - 1];
		b[n - i - 1] = b[i];
		b[i] = t;
	}
}

char *
complement(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		switch (s[i]) {
		case 'A':
			b[i] = 'T';
			break;
		case 'T':
			b[i] = 'A';
			break;
		case 'C':
			b[i] = 'G';
			break;
		case 'G':
			b[i] = 'C';
			break;
		}
	}
	b[i] = '\0';

	reverse(b, i);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	complement(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("AAAACCCGGT", "ACCGGGTTTT");
	return 0;
}
