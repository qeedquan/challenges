/*

Sys Admins are always on your case to improve the strength of your passwords. You could really use a handy function to make your passwords completely un-hackable.

Use the super secret characters in the superSecretChars variable to replace the matching characters in your totally insecure password and make it un-hackable.

eg. replace all 'a's with '@'s. Make sure you get the upper case characters too just in case the user wants to SHOUT their password at you.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
ssp(const char *s, char *b)
{
	char *p;

	for (p = b; *s; s++) {
		switch (*s) {
		case 'a':
		case 'A':
			*p++ = '@';
			break;
		case 's':
		case 'S':
			*p++ = '$';
			break;
		case 'o':
		case 'O':
			*p++ = '0';
			break;
		case 'h':
		case 'H':
			*p++ = '5';
			break;
		case 'x':
		case 'X':
			*p++ = '*';
			break;
		default:
			*p++ = *s;
			break;
		}
	}
	*p = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	ssp(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("haxorpassword", "5@*0rp@$$w0rd");
	test("HaxorPassword", "5@*0rP@$$w0rd");
	test("MuchSecureVeryPassword", "Muc5$ecureVeryP@$$w0rd");
	test("", "");
	return 0;
}
