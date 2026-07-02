/*

It's been a tough week at work and you are stuggling to get out of bed in the morning.

While waiting at the bus stop you realise that if you could time your arrival to the nearest minute you could get valuable extra minutes in bed.

There is a bus that goes to your office every 15 minute, the first bus is at 06:00, and the last bus is at 00:00.

Given that it takes 5 minutes to walk from your front door to the bus stop, implement a function that when given the curent time will tell you much time is left, before you must leave to catch the next bus.

Examples
"05:00"  =>  55
"10:00"  =>  10
"12:10"  =>  0
"12:11"  =>  14

Notes
Return the number of minutes till the next bus
Input will be formatted as HH:MM (24-hour clock)
The input time might be after the buses have stopped running, i.e. after 00:00

*/

#include <assert.h>
#include <stdio.h>

int
bustimer(const char *s)
{
	int h, m;

	if (sscanf(s, "%d:%d", &h, &m) != 2)
		return -1;
	if (h == 5 && m > 55)
		return 70 - m;
	if (h < 6)
		return 355 - m - (60 * h);
	if (h == 23 && m > 55)
		return 415 - m;
	if (m <= 10)
		return 10 - m;
	if (m <= 25)
		return 25 - m;
	if (m <= 40)
		return 40 - m;
	if (m <= 55)
		return 55 - m;
	return 70 - m;
}

int
main()
{
	assert(bustimer("05:00") == 55);
	assert(bustimer("12:10") == 0);
	assert(bustimer("12:11") == 14);
	assert(bustimer("10:00") == 10);
	assert(bustimer("15:05") == 5);
	assert(bustimer("06:10") == 0);
	return 0;
}
