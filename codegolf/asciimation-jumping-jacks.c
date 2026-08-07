/*

This is my first challenge, so I'm keeping it fairly simple.

If you've ever typed telnet towel.blinkenlights.nl on your command line and pressed enter, you will have experienced the joy of asciimation. Asciimation is, quite simply, doing an animation with ascii art. Today we will be doing a very basic asciimation of a person doing jumping jacks.

There will be two ascii pictures that we will put together into one asciimation. Number 1:

_o_
 0
/ \
Number 2:

\o/
_0_
<blank line>

Note that the second one has a blank line at the end.

So your program should do these steps:

Clear the console screen.
Print the correct ascii art image.
Set a flag or something so you know to do the other image next time.
Wait a moment (about a second).
Continue at 1.

Rules
Your program must be a (theoretically) infinite loop.
The programming language you use must have been created before this challange was posted.
This is code-golf, so shortest code in bytes wins.
Standard loopholes apply.

*/

#include <stdio.h>
#include <unistd.h>

void
clear(void)
{
	printf("\033c");
}

void
jumpingjacks(void)
{
	static const char *anim1 =
	    "_o_\n"
	    " 0\n"
	    "/ \\\n";

	static const char *anim2 =
	    "\\o/\n"
	    "_0_\n"
	    "\n";

	int f;

	for (f = 0;; f ^= 1) {
		clear();
		printf("%s\n", (!f) ? anim1 : anim2);
		sleep(1);
	}
}

int
main(void)
{
	jumpingjacks();
	return 0;
}
