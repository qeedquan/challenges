/*

Description

No more hiding from your alarm clock! You've decided you want your computer to keep you updated on the time so you're never late again. A talking clock takes a 24-hour time and translates it into words.

Input Description

An hour (0-23) followed by a colon followed by the minute (0-59).

Output Description

The time in words, using 12-hour format followed by am or pm.

Sample Input data

00:00
01:30
12:05
14:01
20:29
21:00
Sample Output data

It's twelve am
It's one thirty am
It's twelve oh five pm
It's two oh one pm
It's eight twenty nine pm
It's nine pm
Extension challenges (optional)

Use the audio clips found here to give your clock a voice.
http://steve-audio.net/voices/

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
talkingclock(const char *str, char *buf)
{
	static const char *tens[] = {
	    "oh ",
	    "",
	    "twenty ",
	    "thirty ",
	    "fourty ",
	    "fifty ",
	};
	static const char *ones[] = {
	    "twelve",
	    "one",
	    "two",
	    "three",
	    "four",
	    "five",
	    "six",
	    "seven",
	    "eight",
	    "nine",
	    "ten",
	    "eleven",
	    "twelve",
	    "thirteen",
	    "fourteen",
	    "fifteen",
	    "sixteen",
	    "seventeen",
	    "eighteen",
	    "nineteen",
	};

	const char *ampm;
	int hour, minute;

	if (sscanf(str, "%d:%d", &hour, &minute) != 2)
		return NULL;
	if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
		return NULL;

	ampm = (hour < 12) ? "am" : "pm";
	if (minute == 0)
		sprintf(buf, "It's %s %s", ones[hour % 12], ampm);
	else if (!(minute % 10))
		sprintf(buf, "It's %s %s%s", ones[hour % 12], tens[minute / 10], ampm);
	else if (minute < 10 || minute > 20)
		sprintf(buf, "It's %s %s%s %s", ones[hour % 12], tens[minute / 10], ones[minute % 10], ampm);
	else
		sprintf(buf, "It's %s %s %s", ones[hour % 12], ones[minute], ampm);

	return buf;
}

void
test(const char *str, const char *expected)
{
	char buf[128];
	const char *result;

	result = talkingclock(str, buf);
	assert(result);
	printf("%s\n", result);
	assert(!strcmp(result, expected));
}

int
main()
{
	test("00:00", "It's twelve am");
	test("01:30", "It's one thirty am");
	test("12:05", "It's twelve oh five pm");
	test("14:01", "It's two oh one pm");
	test("20:29", "It's eight twenty nine pm");
	test("21:00", "It's nine pm");

	return 0;
}
