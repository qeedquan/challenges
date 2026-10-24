/*

This problem is taken from the British Informatics Olympiad 2013 (31st of December 2012).

Two clocks, which show the time in hours and minutes using the 24 hour clock, are running at different speeds.
Each clock is an exact number of minutes per hour fast.
Both clocks start showing the same time (00:00) and are checked regularly every hour (starting after one hour) according to an accurate timekeeper.
What time will the two clocks show on the first occasion when they are checked and show the same time?

NB: For this question we only care about the clocks matching when they are checked.

For example, suppose the first clock runs 1 minute fast (per hour) and the second clock runs 31 minutes fast (per hour).

• When the clocks are first checked after one hour, the first clock will show 01:01 and the second clock will show 01:31;

• When the clocks are checked after two hours, they will show 02:02 and 03:02;

• After 48 hours the clocks will both show 00:48

Write a function which takes in a two integers as parameters, indicating the number of minutes fast (per hour) of the first and second clock respectively.

You should output the time shown on the clocks when they first match. Both the hour and the minutes should be displayed with two digits (24 hour format).

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

char *
synctime(int first, int second, char *buf)
{
	int d, n, t;

	d = abs(first - second);
	n = 1440 / gcd(1440, d);
	t = (n * (60 + first)) % 1440;
	sprintf(buf, "%02d:%02d", t / 60, t % 60);
	return buf;
}

void
test(int first, int second, const char *res)
{
	char buf[16];

	synctime(first, second, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	test(1, 31, "00:48");

	return 0;
}
