/*

You have the job to implement a countdown function that will be used for the next NASA spatial mission. The function takes a duration in milliseconds and return a string in countdown format.

If it's counting down, the first character should be '-', if it's counting up it should be '+'. Then it should return the number of: hours (min 2 units), minutes (2 units) and seconds (2 units).

countdown(-154800000)  // return  '-43:00:00'
countdown(0)           // return  '+00:00:00'
countdown(61000)       // return  '+00:01:01'
countdown(360000000)   // return '+100:00:00'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
countdown(long ms, char *buf)
{
	long hour, min, sec;
	int sgn;

	sgn = '+';
	if (ms < 0) {
		sgn = '-';
		ms = -ms;
	}

	hour = ms / 3600000;
	min = (ms % 3600000) / 60000;
	sec = (ms % 60000) / 1000;
	sprintf(buf, "%c%02ld:%02ld:%02ld", sgn, hour, min, sec);
	return buf;
}

void
test(long ms, const char *expected)
{
	char buf[128];

	countdown(ms, buf);
	puts(buf);
	assert(!strcmp(buf, expected));
}

int
main()
{
	test(-154800000, "-43:00:00");
	test(0, "+00:00:00");
	test(61000, "+00:01:01");
	test(360000000, "+100:00:00");

	return 0;
}
