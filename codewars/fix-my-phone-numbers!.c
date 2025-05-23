/*

Fix My Phone Numbers
Oh thank goodness you're here! The last intern has completely ruined everything!

All of our customer's phone numbers have been scrambled, and we need those phone numbers to annoy them with endless sales calls!

The Format
Phone numbers are stored as strings and comprise 11 digits, eg '02078834982' and must always start with a 0.

However, something strange has happened and now all of the phone numbers contain lots of random characters, whitespace and some are not phone numbers at all!

For example, '02078834982' has somehow become 'efRFS:)0207ERGQREG88349F82!' and there are lots more lines that we need to check.

The Task
Given a string, you must decide whether or not it contains a valid phone number. If it does, return the corrected phone number as a string ie. '02078834982' with no whitespace or special characters, else return "Not a phone number".

STRINGSREGULAR EXPRESSIONSFUNDAMENTALS

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
fix(const char *s, char *b)
{
	char *p;
	size_t n;

	for (p = b; *s; s++) {
		if (isdigit(*s))
			*p++ = *s;
	}
	*p = '\0';

	n = p - b;
	if (n != 11 || b[0] != '0')
		strcpy(b, "Not a phone number");
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	fix(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("efRFS:)0207ERGQREG88349F82!", "02078834982");
	test("sjfniebienvr12312312312ehfWh", "Not a phone number");
	test("0192387415456", "Not a phone number");
	test("v   uf  f 0tt2eg qe0b 8rtyq4eyq564()(((((165", "02084564165");
	test("stop calling me no I have never been in an accident", "Not a phone number");

	return 0;
}
