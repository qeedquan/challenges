/*

Introduction
Remember the roaring 80's? I mean, you know, like 30 years ago? No cell phones, no internet, no ATM's, fluorescent clothing (what was that?!) and scrolling marqee's! No, no, no! Not the online ones, but real ones, With LED lights.

https://i.stack.imgur.com/yISwz.gif

Since I'm in a nostalgic mood, I'd like you to create a scrolling marquee.

Challenge
Create a program where you can enter a one line string. You program needs to create a 80 character wide scrolling marquee, repeating the text if necessary.

Rules
The user must be able to enter a string to your program as input. The string can be a command line parameter or a string entered while running the program.
Your program must continuously print a string of exactly 80 (visible) characters.
The string must be updated every 0.1 second (more or less; I won't be timing it), shifting the characters every iteration one position to the left.
The string "rotates". At the end of the user supplied string, another instance of the string must appear.
You program must print it's output on one line, without linefeeds (use a '\r' instead of a '\n')
Your program must run ad infinitum, until an user interrupt.
This is a codegolf, so shortest code in bytes wins.
There is a 10% bonus (rounded up to the next integer) for printing in red on a black background.
Standard loopholes apply.
Reference implementation in Python 2.7
This program isn't golfed, but it provides a reference implementation (and thus an upper limit to the size).

import time,sys
s=raw_input()*99
while 1:
    for i in range(80):
        print s[i:i+80]+'\r',
        sys.stdout.flush()
        time.sleep(0.1)

*/

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void
clear(void)
{
	printf("\033c");
}

void
textscroll(const char *s)
{
	static const struct timespec delay = {
	    .tv_nsec = 100000000L,
	};

	size_t i, n;

	n = 0;
	for (;;) {
		clear();
		for (i = n; s[i]; i++)
			putchar(s[i]);
		putchar(' ');
		for (i = 0; i < n; i++)
			putchar(s[i]);
		putchar('\r');
		fflush(stdout);

		thrd_sleep(&delay, NULL);

		n = (s[n]) ? n + 1 : 0;
	}
}

int
main(void)
{
	textscroll("Welcome to Programming Puzzles & Code Golf");
	return 0;
}
