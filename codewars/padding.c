/*

In not more than 24 characters, write a function named p that pads it input to both sides of itself and returns the result.

Example
p("e") //returns "eee"
p("e\n") //returns "e\ne\ne\n"

Instruction
Code should not the more than 24 characters
Character + and function repeat not allowed in the code.
Only a single . character allowed
Code must be on a single line
${ character not allowed

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
pad(const char *s, char *b)
{
	sprintf(b, "%s%s%s", s, s, s);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	pad(s, b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("e", "eee");
	test("e\n", "e\ne\ne\n");
	return 0;
}
