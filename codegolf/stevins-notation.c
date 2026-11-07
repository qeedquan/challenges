/*

Stevin's Notation is a way to represent decimals in a non-fractional way.

The Flemish mathematician and engineer Simon Stevin is remembered for his study of decimal fractions. Although he was not the first to use decimal fractions (they are found in the work of the tenth-century Islamic mathematician al-Uqlidisi), it was his tract De Thiende (“The tenth”), published in 1585 and translated into English as Disme: The Art of Tenths, or Decimall Arithmetike Teaching (1608),[3] that led to their widespread adoption in Europe. Stevin, however, did not use the notation we use today. He drew circles around the exponents of the powers of one tenth: thus he wrote 7.3486 as 7⓪3①4②8③6④.

For example, the decimal number 32.567 can be expressed as 32 + 5/10 + 6/100 + 7/1000. In Stevin's Notation, circled numbers representing the denominator of the original decimal fraction were inserted after each number.

In lieu of formatting the output via parenthesis or using any unicode characters, we will simply output the associated power of ten number.

Therefore, the decimal number above would be written as 320516273.

Task

When given a decimal input, output a Stevin's Notation integer equivalent.

Test cases:

Input	Output
123	123
123.0	123
123.00000	123
123.456	1230415263
123.456000	1230415263
1.000009	10010203040596
0	0
0.0	0
0.0001	0001020314
123456789.123456789987654321	1234567890112233445566778899910811712613514415316217118

Notes

Inputs containing trailing 0 can be omitted from output.
For this challenge, we can assume the input will be positive.
This is code-golf, so shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
stevins(const char *s, char *b)
{
	size_t i, j, p, n;

	for (i = 0; s[i] && s[i] != '.'; i++)
		b[i] = s[i];
	b[i] = '\0';

	n = i + strlen(s + i);
	while (n > i && strchr("0.", s[n - 1]))
		n--;

	if (i < n) {
		b[i++] = '0';
		p = 1;
		for (j = i; i < n; i++)
			j += sprintf(b + j, "%c%zu", s[i], p++);
	}

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	stevins(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("123", "123");
	test("123.0", "123");
	test("123.00000", "123");
	test("123.456", "1230415263");
	test("123.456000", "1230415263");
	test("1.000009", "10010203040596");
	test("0", "0");
	test("0.0", "0");
	test("0.0001", "0001020314");
	test("123456789.123456789987654321", "1234567890112233445566778899910811712613514415316217118");

	return 0;
}
