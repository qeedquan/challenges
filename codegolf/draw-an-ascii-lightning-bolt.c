/*

Introduction
Partly inspired by this StackOverflow question, let's draw an ASCII Lightning Bolt.

Write a program that takes a positive Integer n via STDIN or command line and outputs the ASCII Lightning Bolt below.

Input

Positive Integer n representing the number of lightning zig-zag tiers to draw.

Example Output

n=1

__
\ \
 \ \
  \ \
   \/
n=2

__
\ \
 \ \
__\ \
\  __\
 \ \
  \ \
   \/
n=3

__
\ \
 \ \
__\ \
\  __\
 \ \
__\ \
\  __\
 \ \
  \ \
   \/
n=4

__
\ \
 \ \
__\ \
\  __\
 \ \
__\ \
\  __\
 \ \
__\ \
\  __\
 \ \
  \ \
   \/
. . . etc

Additional notes

You may write a function that takes n as the only argument and prints or returns the string.
Trailing spaces and new lines are okay.
No leading spaces except where appropriate for the designated pattern.
Shortest code in bytes wins.

*/

#include <stdio.h>

void
bolt(int n)
{
	int i;

	printf("n=%d\n", n);
	if (n < 1)
		return;

	puts("__");
	puts("\\ \\");
	puts(" \\ \\ ");
	for (i = 1; i < n; i++) {
		puts("__\\ \\");
		puts("\\  __\\");
		puts(" \\ \\ ");
	}
	puts("  \\ \\ ");
	puts("   \\/");
	puts("");
}

int
main(void)
{
	int i;

	for (i = 1; i <= 5; i++)
		bolt(i);
	return 0;
}
