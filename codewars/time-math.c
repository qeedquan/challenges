/*

Given two times in hours, minutes, and seconds (ie '15:04:24'), add or subtract them. This is a 24 hour clock. Output should be two digits for all numbers: hours, minutes, seconds (ie '04:02:09').

timeMath('01:24:31', '+', '02:16:05') === '03:40:36'

timeMath('01:24:31', '-', '02:31:41') === '22:52:50'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

long
mod(long x, long m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

long
asc2tim(const char *s)
{
	long hh, mm, ss;

	if (sscanf(s, "%ld:%ld:%ld", &hh, &mm, &ss) != 3)
		return -1;
	return (hh * 3600) + (mm * 60) + ss;
}

char *
tim2asc(char *b, long t)
{
	long hh, mm, ss;

	t = mod(t, 86400);
	hh = t / 3600;
	mm = (t / 60) % 60;
	ss = t % 60;
	sprintf(b, "%02ld:%02ld:%02ld", hh, mm, ss);
	return b;
}

char *
timemath(const char *s1, int op, const char *s2, char *b)
{
	long t1, t2;

	t1 = asc2tim(s1);
	t2 = asc2tim(s2);
	if (t1 < 0 || t2 < 0)
		return NULL;

	if (op == '+')
		t1 += t2;
	else if (op == '-')
		t1 -= t2;
	else
		return NULL;

	return tim2asc(b, t1);
}

void
test(const char *s1, int op, const char *s2, const char *r)
{
	char b[128];

	timemath(s1, op, s2, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("01:24:31", '+', "02:16:05", "03:40:36");
	test("01:24:31", '+', "22:35:28", "23:59:59");
	test("00:00:01", '+', "23:59:59", "00:00:00");
	test("13:48:52", '+', "13:47:53", "03:36:45");

	test("01:24:31", '-', "02:31:41", "22:52:50");
	test("11:24:31", '-', "11:24:31", "00:00:00");
	test("11:24:31", '-', "03:15:28", "08:09:03");
	test("00:00:01", '-', "00:00:02", "23:59:59");

	return 0;
}
