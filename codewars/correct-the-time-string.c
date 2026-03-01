/*

A new task for you!

You have to create a method, that corrects a given time string.
There was a problem in addition, so many of the time strings are broken.
Time is formatted using the 24-hour clock, so from 00:00:00 to 23:59:59.
Examples
"09:10:01" -> "09:10:01"
"11:70:10" -> "12:10:10"
"19:99:99" -> "20:40:39"
"24:01:01" -> "00:01:01"
If the input-string is null or empty return exactly this value! (empty string for C++) If the time-string-format is invalid, return null. (empty string for C++)

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have created other katas. Have a look if you like coding and challenges.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
correct(const char *t, char *b)
{
	unsigned h, m, s;

	*b = '\0';
	if (sscanf(t, "%02u:%02u:%02u", &h, &m, &s) != 3)
		return b;

	m += s / 60;
	s %= 60;

	h += m / 60;
	m %= 60;

	h %= 24;

	sprintf(b, "%02u:%02u:%02u", h, m, s);
	return b;
}

void
test(const char *t, const char *r)
{
	char b[128];

	correct(t, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("", "");
	test("001122", "");
	test("00;11;22", "");
	test("0a:1c:22", "");

	test("09:10:01", "09:10:01");
	test("11:70:10", "12:10:10");
	test("19:99:99", "20:40:39");
	test("24:01:01", "00:01:01");
	test("52:01:01", "04:01:01");

	return 0;
}
