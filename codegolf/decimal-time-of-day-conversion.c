/*

Introduction
Time is confusing. Sixty seconds to a minute, sixty minutes to an hour, twenty-four hours to a day (and not to mention that pesky am/pm!).

There's no room for such silliness nowadays, so we've decided to adopt the only sensible alternative: decimal days! That is to say, each day is considered 1 whole unit, and anything shorter is written as a decimal fraction of that day. So, for example: "12:00:00" would be written as "0.5", and "01:23:45" might be written as "0.058159".

Because it will take time to get used to the new system, you are tasked with writing a program that can convert between them in both directions.

Challenge
Write a program in the language of your choice, that given a modern time in the ISO-8601 format of "hh:mm:ss", will return the equivalent decimal fraction unit. Likewise, given a decimal fraction, the program should return the time in the modern format initially specified.

You can make the following assumptions:

The modern time input and output can range from "00:00:00" to "24:00:00"
The decimal time input and output can range from "0" to "1", and should be able to accept/output up to at least 5 decimal places (such as "0.12345"). More precision is acceptable
The program should be able to know which conversion direction to perform based on input
You cannot use time related functions/libraries
The winner will be determined by the shortest code that accomplishes the criteria. They will be selected in at least 7 decimal day units, or if/when there have been enough submissions.

Examples
Here's a(n intentionally) poorly written piece of JavaScript code to be used as an example:

function decimalDay(hms) {
    var x, h, m, s;
    if (typeof hms === 'string' && hms.indexOf(':') > -1) {
        x = hms.split(':');
        return (x[0] * 3600 + x[1] * 60 + x[2] * 1) / 86400;
    }
    h = Math.floor(hms * 24) % 24;
    m = Math.floor(hms * 1440) % 60;
    s = Math.floor(hms * 86400) % 60;
    return (h > 9 ? '' : '0') + h + ':' + (m > 9 ? '' : '0') + m + ':' + (s > 9 ? '' : '0') + s;
}
decimalDay('02:57:46'); // 0.12344907407407407
decimalDay('23:42:12'); // 0.9876388888888888
decimalDay(0.5); // 12:00:00
decimalDay(0.05816); // 01:23:45

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double
dec2day(const char *b)
{
	long h, m, s;

	if (sscanf(b, "%ld:%ld:%ld", &h, &m, &s) != 3)
		return -1;
	return ((h * 3600) + (m * 60) + s) / 86400.0;
}

char *
day2dec(double t, char *b)
{
	long h, m, s;

	h = t * 24;
	m = t * 1440;
	s = t * 86400;

	h %= 24;
	m %= 60;
	s %= 60;

	sprintf(b, "%02ld:%02ld:%02ld", h, m, s);
	return b;
}

void
test(int f, const char *s, double v)
{
	char b[128];
	double t;

	switch (f) {
	case 'c':
		t = dec2day(s);
		printf("%f\n", t);
		assert(fabs(t - v) < 1e-8);
		break;

	case 'y':
		day2dec(v, b);
		printf("%s\n", b);
		assert(!strcmp(b, s));
		break;
	}
}

int
main(void)
{
	test('c', "02:57:46", 0.12344907407407407);
	test('c', "23:42:12", 0.9876388888888888);
	test('y', "12:00:00", 0.5);
	test('y', "01:23:45", 0.05816);

	return 0;
}
