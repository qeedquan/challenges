/*

Create a function that will return true if the input is in the following date time format 01-09-2016 01:20 and false if it is not.

This Kata has been inspired by the Regular Expressions chapter from the book Eloquent JavaScript.

*/

#include <assert.h>
#include <ctype.h>

bool
match(const char *pattern, const char *text)
{
	while (*pattern) {
		if (*pattern == 'd') {
			if (!isdigit(*text))
				return false;
		} else if (*pattern != *text)
			return false;

		pattern++;
		text++;
	}
	return *pattern == '\0' && *text == '\0';
}

bool
datecheck(const char *text)
{
	return match("dd-dd-dddd dd:dd", text);
}

int
main()
{
	assert(datecheck("01-09-2016 01:20") == true);
	assert(datecheck("01-09-2016 01:20") == true);
	assert(datecheck("01-09-2016 01;20") == false);
	assert(datecheck("01_09_2016 01:20") == false);
	assert(datecheck("14-10-1066 12:00") == true);
	assert(datecheck("Tenth of January") == false);
	assert(datecheck("20 Sep 1988") == false);
	assert(datecheck("19-12-2050 13:34") == true);
	assert(datecheck("Tue Sep 06 2016 01:46:38 GMT+0100") == false);
	assert(datecheck("01-09-2016 00:00") == true);
	assert(datecheck("01-09-2016 2:00") == false);
	assert(datecheck("001-02-2016 00:00") == false);
	assert(datecheck("21-12-2013 02:224") == false);

	return 0;
}
