/*

You've got a bunch of textual data with embedded phone numbers. Write a function area_code() that finds and returns just the area code portion of the phone number.

>>> message = "The supplier's phone number is (555) 867-5309"
>>> area_code(message)
'555'

The returned area code should be a string, not a number. Every phone number is formatted like in the example, and the only non-alphanumeric characters in the string are apostrophes ' or the punctuation used in the phone number.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
extract(const char *s)
{
	size_t i;
	int r;

	r = -1;
	for (i = 0; s[i]; i++) {
		if (s[i] != '(')
			continue;
		if (!isdigit(s[i + 1]))
			continue;
		if (!isdigit(s[i + 2]))
			continue;
		if (!isdigit(s[i + 3]))
			continue;
		if (s[i + 4] != ')')
			continue;

		sscanf(s + i + 1, "%d", &r);
		break;
	}
	return r;
}

int
main()
{
	assert(extract("The supplier's phone number is (555) 867-5309") == 555);
	assert(extract("Grae's cell number used to be (123) 456-7890") == 123);
	assert(extract("The 102nd district court's fax line is (124) 816-3264") == 124);
	assert(extract("(1") == -1);
	assert(extract("(123") == -1);

	return 0;
}
