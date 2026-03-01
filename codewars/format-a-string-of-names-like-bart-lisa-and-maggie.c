/*

Given: an array containing hashes of names

Return: a string formatted as a list of names separated by commas except for the last two names, which should be separated by an ampersand.

Example:

list([ {name: 'Bart'}, {name: 'Lisa'}, {name: 'Maggie'} ])
// returns 'Bart, Lisa & Maggie'

list([ {name: 'Bart'}, {name: 'Lisa'} ])
// returns 'Bart & Lisa'

list([ {name: 'Bart'} ])
// returns 'Bart'

list([])
// returns ''
Note: all the hashes are pre-validated and will only contain A-Z, a-z, '-' and '.'.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
format(const char **s, size_t n, char *b)
{
	size_t i;
	char *p;

	p = b;
	for (i = 0; i < n; i++) {
		p += sprintf(p, "%s", s[i]);
		if (i + 1 < n - 1)
			p += sprintf(p, ", ");
		else if (i + 1 < n)
			p += sprintf(p, " & ");
	}
	*p = '\0';

	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[128];

	format(s, n, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	const char *s[] = {"Bart", "Lisa", "Maggie"};

	test(s, 3, "Bart, Lisa & Maggie");
	test(s, 2, "Bart & Lisa");
	test(s, 1, "Bart");
	test(s, 0, "");

	return 0;
}
