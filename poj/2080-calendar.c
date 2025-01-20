/*

Description

A calendar is a system for measuring time, from hours and minutes, to months and days, and finally to years and centuries. The terms of hour, day, month, year and century are all units of time measurements of a calender system.
According to the Gregorian calendar, which is the civil calendar in use today, years evenly divisible by 4 are leap years, with the exception of centurial years that are not evenly divisible by 400. Therefore, the years 1700, 1800, 1900 and 2100 are not leap years, but 1600, 2000, and 2400 are leap years.
Given the number of days that have elapsed since January 1, 2000 A.D, your mission is to find the date and the day of the week.

Input

The input consists of lines each containing a positive integer, which is the number of days that have elapsed since January 1, 2000 A.D. The last line contains an integer −1, which should not be processed.
You may assume that the resulting date won’t be after the year 9999.

Output

For each test case, output one line containing the date and the day of the week in the format of "YYYY-MM-DD DayOfWeek", where "DayOfWeek" must be one of "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" and "Saturday".

Sample Input

1730
1740
1750
1751
-1

Sample Output

2004-09-26 Sunday
2004-10-06 Wednesday
2004-10-16 Saturday
2004-10-17 Sunday

Source

Shanghai 2004 Preliminary

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
leap(int m)
{
	return ((m % 4 == 0 && m % 100 != 0) || (m % 400 == 0));
}

char *
date(int d, char *b)
{
	static const char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	static const int year[2] = {365, 366};
	static const int month[2][12] = {
	    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	int i, j, t, w;

	w = d % 7;
	for (i = 2000; d >= year[leap(i)]; i++)
		d -= year[leap(i)];

	t = leap(i);
	for (j = 0; d >= month[t][j]; j++)
		d -= month[t][j];

	sprintf(b, "%d-%02d-%02d %s", i, j + 1, d + 1, week[w]);
	return b;
}

void
test(int d, const char *r)
{
	char b[128];

	date(d, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1730, "2004-09-26 Sunday");
	test(1740, "2004-10-06 Wednesday");
	test(1750, "2004-10-16 Saturday");
	test(1751, "2004-10-17 Sunday");

	return 0;
}
