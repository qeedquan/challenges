/*

Rules
You must check if some ticket numbers are valid. To be valid, a ticket number must :

Contain exactly 6 characters
Contain : one letter then one digit then 4 letters

'letter' means a single character, unaccented, uppercase or lowercase, between a and z.

Input arguments
tickets : an array of string, representing ticket numbers

Return value
An integer representing the number of valid ticket numbers.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
isletter(int c)
{
	c = tolower(c);
	return 'a' <= c && c <= 'z';
}

size_t
valids(const char **s, size_t n)
{
	size_t c, i, j;

	for (c = i = 0; i < n; i++) {
		for (j = 0; s[i][j] && j < 7; j++) {
			if ((j == 0 || j >= 2) && !isletter(s[i][j]))
				break;
			else if (j == 1 && !isdigit(s[i][j]))
				break;
		}
		if (j == 6)
			c++;
	}
	return c;
}

int
main()
{
	const char *ex[] = {"A9JZOD", "E9FIDH", "SI2JIS", "F8JIODJ", "FDSNJA", "A9POF?", "AA9DIJD"};

	assert(valids(ex, nelem(ex)) == 2);

	return 0;
}
