/*

The day of the week and month of the year seem to get a lot of attention but no one seems to care about the week of the year. I believe it's time to change that, so your job is to write a program or function that when given a date outputs an integer between 1 and 53 corresponding to the current week of the year.

For the purposes of this challenge we will say that the first Sunday of the year marks the beginning of the year so the only case when January 1st is considered week 1 is when it falls on a Sunday.

Input can be any date format which does not explicitly include the week number (just specify the format in your answer) for dates between 1JAN1900 and 31DEC2100.
Output is an integer between 1 and 53
You may use any standard methods of providing input/output.
Test Cases
17MAY2017 -> 20

3JAN2013 -> 53

1JAN2017 -> 1

17MAY1901 -> 19

31DEC2100 -> 52

7JUL2015 -> 27

This is code-golf so all standard golfing rules apply, and the shortest code (in bytes) wins.

*/

#define _XOPEN_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int
week(const char *s)
{
	struct tm tm;
	char b[32];
	int w;

	if (!strptime(s, "%d%B%Y", &tm))
		return -1;

	strftime(b, sizeof(b), "%U", &tm);
	w = atoi(b);
	return (w) ? w : 53;
}

int
main()
{
	assert(week("17MAY2017") == 20);
	assert(week("3JAN2013") == 53);
	assert(week("1JAN2017") == 1);
	assert(week("17MAY1901") == 19);
	assert(week("31DEC2100") == 52);
	assert(week("7JUL2015") == 27);

	return 0;
}
