/*

Description

Bessie asked her friend what day of the week she was born on. She knew that she was born on 2003 May 25, but didn't know what day it was. Write a program to help. Note that no cow was born earlier than the year 1800.

Facts to know:

* January 1, 1900 was on a Monday.

* Lengths of months:
    Jan 31          May 31      Sep 30
    Feb 28 or 29    Jun 30      Oct 31
    Mar 31          Jul 31      Nov 30
    Apr 30          Aug 31      Dec 31

* Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year).

* The rule above does not hold for century years. Century years divisible by 400 are leap years, all other are not. Thus, the century years 1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year.
Input

* Line 1: Three space-separated integers that represent respectively the year, month (range 1..12), and day of a date.
Output

* Line 1: A single word that is the day of the week of the specified date (from the lower-case list: monday, tuesday, wednesday, thursday, friday, saturday, sunday).

Sample Input

2003 5 25

Sample Output

sunday
Hint

INPUT DETAILS:
May 25, 2003

OUTPUT DETAILS:
      May 2003
Su Mo Tu We Th Fr Sa
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31

Source

USACO 2005 October Bronze

*/

#define _XOPEN_SOURCE
#include <assert.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

char *
birthday(const char *s, char *b, size_t n)
{
	struct tm tm;

	if (!strptime(s, "%b %d, %Y", &tm))
		return NULL;

	strftime(b, n, "%A", &tm);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128], *p;

	p = birthday(s, b, sizeof(b));
	assert(p);
	printf("%s\n", p);
	assert(!strcasecmp(p, r));
}

int
main(void)
{
	setlocale(LC_ALL, "C");

	test("May 25, 2003", "sunday");
	test("May 27, 2003", "tuesday");
	test("May 31, 2003", "saturday");
	test("May 1, 2003", "thursday");
	test("May 21, 2003", "wednesday");
	test("May 19, 2003", "monday");
	test("May 9, 2003", "friday");

	return 0;
}
