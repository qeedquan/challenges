/*

One suggestion to build a satisfactory password is to start with a memorable phrase or sentence and make a password by extracting the first letter of each word.

Even better is to replace some of those letters with numbers (e.g., the letter O can be replaced with the number 0):

instead of including i or I put the number 1 in the password;
instead of including o or O put the number 0 in the password;
instead of including s or S put the number 5 in the password.
Examples:
"Give me liberty or give me death"  --> "Gml0gmd"
"Keep Calm and Carry On"            --> "KCaC0"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
password(const char *s, char *b)
{
	char *p;

	p = b;
	while (*s) {
		while (isspace(*s))
			s++;

		switch (*s) {
		case 'i':
		case 'I':
			*p++ = '1';
			break;
		case 'o':
		case 'O':
			*p++ = '0';
			break;
		case 's':
		case 'S':
			*p++ = '5';
			break;
		default:
			*p++ = *s;
			break;
		}

		s++;
		while (*s && !isspace(*s))
			s++;
	}
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	password(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Give me liberty or give me death", "Gml0gmd");
	test("Keep Calm and Carry On", "KCaC0");

	return 0;
}
