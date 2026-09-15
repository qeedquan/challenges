/*

Fans of The Wire will appreciate this one. For those that haven't seen the show, the Barksdale Organization has a simple method for encoding telephone numbers exchanged via pagers: "Jump to the other side of the 5 on the keypad, and swap 5's and 0's."

Here's a keypad for visualization.

┌───┬───┬───┐
│ 1 │ 2 │ 3 │
├───┼───┼───┤
│ 4 │ 5 │ 6 │
├───┼───┼───┤
│ 7 │ 8 │ 9 │
└───┼───┼───┘
    │ 0 │
    └───┘

Detective, we're hot on their trail! We have a big pile of encoded messages here to use as evidence, but it would take way too long to decode by hand. Could you write a program to do this for us?

Write a function called decode(). Given an encoded string of exactly 10 digits, return the actual phone number in string form. Don't worry about input validation, parenthesis, or hyphens.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
decode(const char *s, char *b)
{
	char c, *p;

	for (p = b; *s; s++) {
		c = *s;
		switch (*s) {
		case '0':
			c = '5';
			break;
		case '1':
			c = '9';
			break;
		case '2':
			c = '8';
			break;
		case '3':
			c = '7';
			break;
		case '4':
			c = '6';
			break;
		case '5':
			c = '0';
			break;
		case '6':
			c = '4';
			break;
		case '7':
			c = '3';
			break;
		case '8':
			c = '2';
			break;
		case '9':
			c = '1';
			break;
		}
		*p++ = c;
	}
	*p = '\0';
	return b;
}

int
main()
{
	static const struct test {
		char enc[16];
		char dec[16];
	} tests[] = {
		{ "4103432323", "6957678787" },
		{ "4103438970", "6957672135" },
		{ "4104305768", "6956750342" },
		{ "4102204351", "6958856709" },
		{ "4107056043", "6953504567" },
		{ "4105753410", "6950307695" },
	};

	const struct test *t;
	size_t i;
	char b[16];

	for (i = 0; i < nelem(tests); i++) {
		t = tests + i;
		decode(t->enc, b);
		assert(!strcmp(b, t->dec));
	}
	return 0;
}
