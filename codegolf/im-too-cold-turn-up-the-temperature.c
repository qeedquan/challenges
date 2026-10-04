/*

This is my first golf contest.

What you need to do

Build me, in the shortest amount of bytes possible, my AC remote control system. My room is too cold right now, and I'm missing my remote.

Now, I don't want you literally building it or anything, just golf this:

A slow increment of temperature, starting at 40 degrees, and ending at exactly 72. The increment time must always be 500 millis per increment. It can wait another 500ms at the end. I would prefer it to stop however. The increment itself must go up by two each time, like my remote.

You should not clear the screen. You should have newlines.

What should happen

Example output (everything in parentheses shouldn't be outputted).

40
(wait 500 millis)
42
(wait 500 millis)
44
(..repeat until 72..)
72
(stop or wait 500ms)
Keep in mind This is my first golf, so I apologize if this is too hard to golf. :(

Best of luck, golfers!

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <threads.h>

void
adjust(int t0, int t1)
{
	struct timespec tp;
	int s, t;

	tp.tv_sec = 0;
	tp.tv_nsec = 500000000;

	t = t0;
	s = 2;
	if (t0 > t1)
		s = -s;

	while (t != t1) {
		printf("%d\n", t);
		thrd_sleep(&tp, NULL);

		if (abs(t - t1) >= abs(s))
			t += s;
		else
			t = t1;
	}
	printf("%d\n", t);
}

int
main(void)
{
	adjust(40, 72);

	return 0;
}
