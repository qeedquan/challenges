/*

Peter can see a clock in the mirror from the place he sits in the office. When he saw the clock shows 12:22

He knows that the time is 11:38

in the same manner:

05:25 --> 06:35

01:50 --> 10:10

11:58 --> 12:02

12:01 --> 11:59

Please complete the function WhatIsTheTime(timeInMirror), where timeInMirror is the mirrored time (what Peter sees) as string.

Return the real time as a string.

Consider hours to be between 1 <= hour < 13.

So there is no 00:20, instead it is 12:20.

There is no 13:20, instead it is 01:20.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

char *
clockmirror(const char *s, char *b)
{
	int h, m, H, M;

	if (sscanf(s, "%d:%d", &h, &m) != 2)
		return NULL;

	H = 11 - h;
	if (!m)
		H = 12 - h;
	H = mod(H, 12);
	if (H == 0)
		H = 12;
	M = mod(60 - m, 60);

	sprintf(b, "%02d:%02d", H, M);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	clockmirror(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("12:22", "11:38");
	test("05:25", "06:35");
	test("01:50", "10:10");
	test("11:58", "12:02");
	test("12:01", "11:59");
	return 0;
}
