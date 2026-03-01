/*

Write a function that accepts two numbers a and b and returns whether a is smaller than, bigger than, or equal to b, as a string.

(5, 4)   ---> "5 is greater than 4"
(-4, -7) ---> "-4 is greater than -7"
(2, 2)   ---> "2 is equal to 2"

There is only one problem...

You cannot use if statements, and you cannot use the ternary operator ? :.

In fact the word if and the character ? are not allowed in your code.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
sign(int x)
{
	return (x > 0) - (x < 0);
}

char *
cmp(int x, int y, char *b)
{
	static const char *lut0[] = { "smaller", "equal", "greater" };
	static const char *lut1[] = { "than", "to", "than" };

	int s;

	s = sign(x - y) + 1;
	sprintf(b, "%d is %s %s %d", x, lut0[s], lut1[s], y);
	return b;
}

void
test(int x, int y, const char *r)
{
	char b[32];

	cmp(x, y, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(5, 4, "5 is greater than 4");
	test(-4, -7, "-4 is greater than -7");
	test(2, 2, "2 is equal to 2");
	test(1, 2, "1 is smaller than 2");

	return 0;
}
