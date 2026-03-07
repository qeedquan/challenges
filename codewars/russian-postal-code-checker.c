/*

You should write a simple function that takes string as input and checks if it is a valid Russian postal code, returning true or false.

A valid postcode should be 6 digits with no white spaces, letters or other symbols. Empty string should also return false.

Please also keep in mind that a valid post code cannot start with 0, 5, 7, 8 or 9

Examples

Valid postcodes:

198328
310003
424000

Invalid postcodes:

056879
12A483
1@63
111

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
valid(const char *s)
{
	size_t i;

	for (i = 0; s[i] && i < 7; i++) {
		if (!isdigit(s[i]))
			return false;
	}

	if (i != 6 || strchr("05789", s[0]))
		return false;

	return true;
}

int
main()
{
	assert(valid("198328") == true);
	assert(valid("310003") == true);
	assert(valid("424000") == true);

	assert(valid("056879") == false);
	assert(valid("12A483") == false);
	assert(valid("1@63") == false);
	assert(valid("111") == false);
	assert(valid("1234567") == false);

	return 0;
}
