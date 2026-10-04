/*

In any programming language, create a program that takes input and animates the text being typed on a keyboard.

The delay between each character should be varying to simulate true typing on a keyboard. The delay shall be 0.1, 0.1, 0.5, 0.1, 0.1, 0.5 ... seconds, until the last character is printed. The final output shall be left on the screen.

You must overwrite the current line of text you can't have the text be printed on new rows.

Example, the input "Hello, PPCG! Goodbye Earth!" should result in the following animation (note that the sampling rate of the gif-maker was low, so the true result is slightly different):

https://i.sstatic.net/o27z4.gif

Since this is code golf, the smallest amount of bytes win.

*/

#include <stdio.h>
#include <time.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
clear()
{
	printf("\033c");
}

void
keystrokes(const char *s)
{
	static const struct timespec delays[] = {
	    {.tv_nsec = 100 * 1'000'000},
	    {.tv_nsec = 100 * 1'000'000},
	    {.tv_nsec = 500 * 1'000'000},
	};
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == '\n')
			clear();
		else
			printf("%c", s[i]);
		thrd_sleep(&delays[i % nelem(delays)], NULL);
		fflush(stdout);
	}
	printf("\n");
}

int
main()
{
	keystrokes("Hello, PPCG! Goodbye Earth!");
	return 0;
}
