/*

A listening party is an event where a bunch of people get together to listen to some music (like a viewing party, but for music).
In the age of the internet you can do Listening Parties online with friends, where you just all hit play together.

The problem is on the internet everyone is in different time-zones so you can't just say "Let's start at 5:35". As a solution we just type xs in the hours position.
So xx:35 means whenever the minute hand is next at 35. If the minute hand is already at that value then the party happens in 1 hour.
If you need to specify more than one hour ahead you can add 1+, 2+ etc. to the beginning. So 1+xx:35 is an hour after the next time the minute hand is at 35.

Your task is to take the current local time, and a string representing when the listening party happens in the above format and output when the listening party will occur in local time.

IO
You can take and output the local time either as a 24 hour string with the minutes and hours separated by a colon (e.g. 19:45), as a tuple of the minutes and hours or as some native time type when available.
If you take a string you may assume a leading zero when the hour hand is a one digit number otherwise. The two should be the same format.
You can take the string representing when the listening party will happen either as a native string type or as a list of chars.
The string will always match the following regex:

([1-9]+\d*\+)?xx:[0-5]\d

Scoring
This is code-golf so answers will be scored in bytes with fewer being better.

Test cases
5:35 xx:45 -> 5:45
19:12 xx:11 -> 20:11
5:15 1+xx:35 -> 6:35
12:30 1+xx:15 -> 14:15
8:29 3+xx:12 -> 12:12
4:30 xx:30 -> 5:30
23:59 xx:01 -> 0:01
15:30 25+xx:12 -> 17:12
12:09 xx:08 -> 13:08

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
listentime(const char *s, char *b)
{
	int h, o, m, xm;

	if (sscanf(s, "%d:%d %d+xx:%d", &h, &m, &o, &xm) != 4) {
		if (sscanf(s, "%d:%d xx:%d", &h, &m, &xm) != 3)
			return NULL;

		o = 0;
	}

	h += o;
	if (m >= xm)
		h += 1;
	h %= 24;

	sprintf(b, "%d:%02d", h, xm);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128], *p;

	p = listentime(s, b);
	if (!p)
		assert(p == r);
	else {
		printf("%s\n", p);
		assert(!strcmp(p, r));
	}
}

int
main(void)
{
	test("5:35 xx:45", "5:45");
	test("19:12 xx:11", "20:11");
	test("5:15 1+xx:35", "6:35");
	test("12:30 1+xx:15", "14:15");
	test("8:29 3+xx:12", "12:12");
	test("4:30 xx:30", "5:30");
	test("23:59 xx:01", "0:01");
	test("15:30 25+xx:12", "17:12");
	test("12:09 xx:08", "13:08");

	return 0;
}
