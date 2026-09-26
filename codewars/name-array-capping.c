/*

Create a method that accepts an array of names, and returns an array of each name with its first letter capitalized.

example

capMe(['jo', 'nelson', 'jurie'])     // returns ['Jo', 'Nelson', 'Jurie']
capMe(['KARLY', 'DANIEL', 'KELSEY']) // returns ['Karly', 'Daniel', 'Kelsey']

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

enum {
	LINE = 80,
};

void
capme(char s[][LINE], size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; s[i][j]; j++) {
			if (j == 0)
				s[i][j] = toupper(s[i][j]);
			else
				s[i][j] = tolower(s[i][j]);
		}
	}
}

void
test(char s[][LINE], size_t n, const char **r)
{
	size_t i;

	capme(s, n);
	for (i = 0; i < n; i++)
		assert(!strcmp(s[i], r[i]));
}

int
main()
{
	char s1[][LINE] = {
		"jo",
		"nelson",
		"jurie",
	};

	char s2[][LINE] = {
		"KARLY",
		"DANIEL",
		"KELSEY",
	};

	const char *r1[] = {
		"Jo",
		"Nelson",
		"Jurie",
	};

	const char *r2[] = {
		"Karly",
		"Daniel",
		"Kelsey",
	};

	test(s1, nelem(s1), r1);
	test(s2, nelem(s2), r2);

	return 0;
}
