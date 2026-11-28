/*

Your challenge is to read a "password" from the keyboard / standard input.

Challenge:

Read a string s invisibly.
For each of the characters in s, print a character c.
In realtime.
Rules:

You must print c in realtime. As soon as the user enters a character you must display c.
c must be constant, i.e. it must be the same character.
c can be any visible character (i.e. it cannot be a newline, space, tab, or unprintable).
c can't be based on s, i.e. c must be defined/constant before s is read.
c must be the same every time the program is run.
c can be one of the characters in s if by accident, as long as all other rules are followed.
None of the characters of s may appear on the screen, c excepted (see previous rule).
You may use any reasonable methods of input and output as long as all other rules are followed.
You may assume that the length of s is never longer than the terminal/graphical window width.
If using a terminal, your program should terminate after a newline or EOF is entered.
Example:

If s was password01 and c was *, the output would look something like:

**********

Winner:

The shortest submission in each language wins.

*/

#include <stdio.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>

volatile sig_atomic_t run = 1;

void
sighandle(int)
{
	run = 0;
}

void
readpass(void)
{
	struct termios oldtc, tc;
	int c;

	tcgetattr(1, &tc);
	oldtc = tc;
	tc.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(1, TCSANOW, &tc);

	while (run && ((c = getchar()) != EOF)) {
		if (c == '\n')
			printf("\n");
		else
			printf("*");
	}

	tcsetattr(1, TCSANOW, &oldtc);
}

int
main(void)
{
	signal(SIGINT, sighandle);
	readpass();
	return 0;
}
