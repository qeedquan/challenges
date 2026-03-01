/*

The Ones' Complement of a binary number is the number obtained by swapping all the 0s for 1s and all the 1s for 0s. For example:

onesComplement(1001) = 0110
onesComplement(1001) = 0110

For any given binary number,formatted as a string, return the Ones' Complement of that number.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
oc(const char *s, char *b)
{
	char *p;

	for (p = b; *s; s++)
		*p++ = (*s == '0') ? '1' : '0';
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	oc(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("1001", "0110");
	test("0", "1");
	test("1", "0");
	test("01", "10");
	test("10", "01");
	test("1101", "0010");
	return 0;
}
