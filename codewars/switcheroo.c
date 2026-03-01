/*

Given a string made up of letters a, b, and/or c, switch the position of letters a and b (change a to b and vice versa). Leave any incidence of c untouched.

Example:

'acb' --> 'bca'
'aabacbaa' --> 'bbabcabb'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
switcheroo(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == 'a')
			s[i] = 'b';
		else if (s[i] == 'b')
			s[i] = 'a';
	}
}

void
test(const char *s, const char *r)
{
	char b[128];

	strcpy(b, s);
	switcheroo(b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("acb", "bca");
	test("aabacbaa", "bbabcabb");

	return 0;
}
