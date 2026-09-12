/*

This kata will return a string that represents the difference of two perfect squares as the sum of consecutive odd numbers.

Specifications:

• The first input minus the second input reveals the exact number of consecutive odd numbers required for the solution - you can check this in the examples below.

• The first input will always be larger than the second.

• All inputs will be valid so no need for error checking.

• Outputs will always be positive.

• Inputs will range between 0 and 200, (inclusive).

• In the returned string there are spaces before and after the plus sign, the minus sign and the equals sign but nowhere else.

Examples:

squaresToOdd(9, 5) --> "9^2 - 5^2 = 11 + 13 + 15 + 17 = 56"

squaresToOdd(10, 7) --> "10^2 - 7^2 = 15 + 17 + 19 = 51"

squaresToOdd(100, 98) --> "100^2 - 98^2 = 197 + 199 = 396"

squaresToOdd(100, 99) --> "100^2 - 99^2 = 199 = 199"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
sq2odd(int s0, int s1, char *b)
{
	int i, n, s;
	char *p;

	p = b;
	p += sprintf(p, "%d^2 - %d^2 = ", s0, s1);
	for (i = s = 0; i < s0 - s1; i++) {
		n = (s1 * 2) + 1 + (i * 2);
		s += n;
		if (i == 0)
			p += sprintf(p, "%d", n);
		else
			p += sprintf(p, " + %d", n);
	}
	sprintf(p, " = %d", s);
	return b;
}

void
test(int s0, int s1, const char *r)
{
	char b[128];

	sq2odd(s0, s1, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(9, 5, "9^2 - 5^2 = 11 + 13 + 15 + 17 = 56");
	test(10, 7, "10^2 - 7^2 = 15 + 17 + 19 = 51");
	test(100, 98, "100^2 - 98^2 = 197 + 199 = 396");
	test(100, 99, "100^2 - 99^2 = 199 = 199");

	return 0;
}
