/*

I'm currently cooking us some cup noodles, but we're really sleepy at the moment. They'll be finished in 50 seconds from now, can you wake me up then?

Problem:
Write a program or function that waits 50 seconds of busy waiting (so that you too doesn't sleep) and then outputs at least 1 visible character to wake me up.

Busy waiting:
You can't use functions like sleep or delay or pause to wait for the 50 seconds, you have to keep checking the elapsed time.

Rules:
Your code must be somewhat consistent in time, between runs and between computers. A small error of +- 1 seconds is acceptable.
You can't output any visible characters between 1 and 50 seconds (let me sleep).
Whitespace characters (newline, space, tab, ...) are not considered visible characters for this challenge.
This is code-golf, so shortest code wins.

*/

#include <stdio.h>
#include <time.h>

void
busywait(int n)
{
	time_t t;

	t = time(NULL) + n;
	while (time(NULL) <= t)
		;
}

int
main()
{
	busywait(50);
	return 0;
}
