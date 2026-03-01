/*

Task
Your Informatics teacher at school likes coming up with new ways to help you understand the material. When you started studying numeral systems, he introduced his own numeral system, which he's convinced will help clarify things. His numeral system has base 26, and its digits are represented by English capital letters - A for 0, B for 1, and so on.

The teacher assigned you the following numeral system exercise: given a one-digit number, you should find all unordered pairs of one-digit numbers whose values add up to the number.

Example
For number = 'G', the output should be ["A + G", "B + F", "C + E", "D + D"]

Translating this into the decimal numeral system we get: number = 6, so it is ["0 + 6", "1 + 5", "2 + 4", "3 + 3"].

Input/Output
[input] string(char in C#) number

A character representing a correct one-digit number in the new numeral system.

Constraints: 'A' ≤ number ≤ 'Z'.

[output] a string array

An array of strings in the format "letter1 + letter2", where "letter1" and "letter2" are correct one-digit numbers in the new numeral system. The strings should be sorted by "letter1".

Note that "letter1 + letter2" and "letter2 + letter1" are equal pairs and we don't consider them to be different.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
nns(int c, char r[][8])
{
	int a, b;
	size_t n;

	if (!('A' <= c && c <= 'Z'))
		return 0;

	c -= 'A';
	n = 0;
	for (a = 0; a < 26; a++) {
		b = c - a;
		if (b < a)
			break;
		sprintf(r[n++], "%c + %c", a + 'A', b + 'A');
	}
	return n;
}

void
test(int c, char r[][8], size_t nr)
{
	char s[12][8];
	size_t i, n;

	n = nns(c, s);
	assert(n == nr);
	for (i = 0; i < n; i++)
		assert(!strcmp(s[i], r[i]));
}

int
main()
{
	char r1[][8] = { "A + G", "B + F", "C + E", "D + D" };
	char r2[][8] = { "A + A" };
	char r3[][8] = { "A + D", "B + C" };
	char r4[][8] = { "A + E", "B + D", "C + C" };
	char r5[][8] = { "A + O", "B + N", "C + M", "D + L", "E + K", "F + J", "G + I", "H + H" };

	test('G', r1, nelem(r1));
	test('A', r2, nelem(r2));
	test('D', r3, nelem(r3));
	test('E', r4, nelem(r4));
	test('O', r5, nelem(r5));

	return 0;
}
