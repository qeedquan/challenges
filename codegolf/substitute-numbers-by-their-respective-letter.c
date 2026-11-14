/*

Create a function or program that takes a number as input, and outputs a string where ASCII-code points for the lower and upper case alphabet are substituted by their character equivalents.

The upper case alphabet use the code points: 65-90
The lower case alphabet use the code points: 97-122
If any adjacent digits in the input equals the code point of a letter, then that letter shall replace the digits in the output string.

Rules:

The input will be a positive integer with between 1 and 99 digits
You can assume only valid input is given
You start substituting at the beginning of the integer (976 -> a6, not 9L)
The input can be on any suitable format (string representation is OK)
The output can be on any suitable format
Standard rules apply
Examples:

1234567
12345C

3456789
345CY

9865432
bA432

6566676869707172737475767778798081828384858687888990
ABCDEFGHIJKLMNOPQRSTUVWXYZ

6711110010100071111108102
Code000Golf
Shortest code in bytes win!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
xgetc(const char *s, size_t *n)
{
	int a, b, c;

	*n = 1;
	if (!isdigit(s[0]) || !isdigit(s[1]))
		return s[0];

	a = ((s[0] - '0') * 10) + (s[1] - '0');
	b = 0;
	if (isdigit(s[2]))
		b = (a * 10) + (s[2] - '0');

	if (('A' <= a && a <= 'Z') || ('a' <= a && a <= 'c')) {
		c = a;
		*n = 2;
	} else if ('d' <= b && b <= 'z') {
		c = b;
		*n = 3;
	} else
		c = s[0];

	return c;
}

char *
sub(const char *s, char *b)
{
	size_t i, j, k;

	for (i = j = 0; s[i]; i += k)
		b[j++] = xgetc(s + i, &k);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[256];

	sub(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1234567", "12345C");
	test("3456789", "345CY");
	test("9865432", "bA432");
	test("6566676869707172737475767778798081828384858687888990", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	test("6711110010100071111108102", "Code000Golf");

	return 0;
}
