/*

It seems as though the infamous soundcloud rapper "6ix 9ine" has been locked away for good. As sad as this may be, his name will surely live on...

Write a function that takes a string representing a date-of-birth as an argument ("dd.mm.yy") and returns a string containing the generated Rap-Name.

How to figure out one's Rap-Name:

Find the average of the two digits that make up the DAY of birth. ("DD.mm.yy")
Find the average of the two digits that make up the YEAR of birth. ("dd.mm.YY")
Note: only integers are admissible, therefore round up averages that are decimal
Note: if the average of the YEAR of birth is 0 (in the case of "dd.mm.00"), the format is '0ero'
Return a single string containing both numbers represented in the following format - e.g, '3hree 6ix'
format = the respective number replaces the first character for the word of said number. 'three' becomes '3hree'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned
index(unsigned value)
{
	unsigned low, high;

	low = value % 10;
	high = (value / 10) % 10;
	return round((low + high) / 2.0);
}

char *
rapname(const char *dob, char *buf)
{
	static const char *map[] = { "0ero", "1ne", "2wo", "3hree", "4our", "5ive", "6ix", "7even", "8ight", "9ine" };

	unsigned day, month, year;
	unsigned index0, index1;

	if (sscanf(dob, "%u.%u.%u", &day, &month, &year) != 3)
		return NULL;

	index0 = index(day);
	index1 = index(year);

	sprintf(buf, "%s %s", map[index0], map[index1]);
	return buf;
}

void
test(const char *dob, const char *expected)
{
	char buf[128];

	assert(rapname(dob, buf));
	puts(buf);
	assert(!strcmp(buf, expected));
}

int
main()
{
	test("23.11.93", "3hree 6ix");
	test("14.07.84", "3hree 6ix");
	test("03.49.04", "2wo 2wo");
	test("01.01.01", "1ne 1ne");
	test("14.07.84", "3hree 6ix");
	test("24.06.94", "3hree 7even");
	test("24.06.00", "3hree 0ero");

	return 0;
}
