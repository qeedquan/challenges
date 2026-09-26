/*

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...


Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"


Constraints:

1 <= columnNumber <= 2^31 - 1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
rev(char *s, size_t n)
{
	size_t i;
	char t;

	for (i = 0; i < n / 2; i++) {
		t = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = t;
	}
	return s;
}

char *
col2title(long n, char *b)
{
	size_t i;
	long c;

	for (i = 0; n > 0;) {
		c = n % 26;
		if (c == 0)
			c = 26;

		b[i++] = c - 1 + 'A';
		n = (n / 26) - (c == 26);
	}
	b[i] = '\0';

	return rev(b, i);
}

void
test(int n, const char *r)
{
	char b[128];

	col2title(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "A");
	test(28, "AB");
	test(701, "ZY");
	test(702, "ZZ");
	test(256, "IV");
	test(110, "DF");
	test(55, "BC");
	test(52, "AZ");
	test(466, "QX");
	test(703, "AAA");
	test(728, "AAZ");
	test(18272, "ZZT");
	test(348059, "STVW");

	return 0;
}
