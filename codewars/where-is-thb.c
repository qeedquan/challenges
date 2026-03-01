/*

Help! THB has gone missing, and we need you to find him! You will be given a string, and must return a string including only the t's, h's, and b's from the original string. Include both uppercase and lowercase.

Remember, you should return an empty string if you are given an empty string or a null string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
thb(char *s)
{
	char *p;

	for (p = s; *s; s++) {
		if (strchr("tThHbB", *s))
			*p++ = *s;
	}
	*p = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	strcpy(b, s);
	thb(b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("For those of you who would like to test your solution before submitting it.", "thhttttbbttt");
	return 0;
}
