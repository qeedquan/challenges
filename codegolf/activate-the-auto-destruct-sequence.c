/*

This is a code golf. The smallest amount of bytes wins! :)

What you need to do
You're on Deep Space Nine, a Cardassian outpost taken over by the Federation, in the year 2374. The Borg, a superior race, have collapsed your shields and assimilated half of your crew. However, you have important classified information on your hands that you can't let anyone see at all. Activate the auto-destruct sequence.

Program Sisko 197 ;)

What you're actually doing
Take as input an integer value, which will set the exact auto destruct time in seconds. Once the user has passed the value, have a countdown ensue. Countdown backwards by one second each and print each number. At the point it reaches zero, make the program crash.

Rules
You may use STDIN, a parameter, or any other standard input format.
You must put each number on a new line.
You may or may not have an extra delay of one second at the beginning and end.
I was looking at Shortest auto-destructive loop, so if you want to use something from that, feel free, but this isn't really a duplicate of that. You can also wait one sec at the start, but once again, I'd prefer if you don't do this:

Note: Everything in parentheses is ignored.

(input is 10)
(wait 1 sec)
10
(1 sec)
9
(1 sec)
8
(1 sec)
(..etc..)
0
(crash)
And you do this:

(input is 10)
10
(1 sec)
9
(1 sec)
8
(1 sec)
(..etc..)
0
(crash)
Examples
If you don't have stdin but you can have a parameter inputted:

(grab the number from the parameter)
(once the number is loaded in, 10 in this case, print it like so:)
10
(wait one second)
9
(wait one second)
8
(wait one second)
7
(wait one second)
6
(wait one second)
5
(wait one second)
4
(wait one second)
3
(wait one second)
2
(wait one second)
1
(wait one second)
0
(either wait one second then crash, or crash instantly)
If you have a form of stdin:

(allow the user to enter a number, there should be no greeting message)
(once the number is entered, 10 in this case, print it like so:)
10
(wait one second)
9
(wait one second)
8
(wait one second)
7
(wait one second)
6
(wait one second)
5
(wait one second)
4
(wait one second)
3
(wait one second)
2
(wait one second)
1
(wait one second)
0
(either wait one second then crash, or crash instantly)
Have fun!

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
doom(int n)
{
	if (n < 0)
		n = 0;

	for (; n >= 0; n--) {
		printf("%d\n", n);
		sleep(1);
	}
	abort();
}

void
usage(void)
{
	fprintf(stderr, "usage: <seconds>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	int n;

	if (argc < 2)
		usage();

	n = atoi(argv[1]);
	doom(n);

	return 0;
}
