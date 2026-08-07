/*

Given a time in a time format class, return it without year, month and day.

It should return a string including milliseconds with 3 decimals.

Example:

new Date(2016, 2, 8, 16, 42, 59)
//Should return:
"16:42:59,000"

*/

#include <stdio.h>
#include <time.h>

struct tm
date(int year, int month, int day, int hour, int minutes, int seconds)
{
	return (struct tm){
		.tm_year = year,
		.tm_mon = month,
		.tm_mday = day,
		.tm_hour = hour,
		.tm_min = minutes,
		.tm_sec = seconds,
	};
}

char *
format(struct tm tm, char *buf)
{
	sprintf(buf, "%d:%d:%d,%03d", tm.tm_hour, tm.tm_min, tm.tm_sec, 0);
	return buf;
}

int
main()
{
	char buf[128];

	printf("%s\n", format(date(2016, 2, 8, 16, 42, 59), buf));
	return 0;
}
