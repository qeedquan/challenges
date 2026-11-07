/*

Write a program that takes in an integer N via stdin or the command line.

If N is 0, the single letter O must be printed to stdout.

If N is positive, this horizontal ASCII art double helix, drawn N segments wide, must be printed.

If N is 1, the output is:

 /\
O  O
 \/
If N is 2, the output is:

 /\ /\
O  /  O
 \/ \/
If N is 3, the output is:

 /\ /\ /\
O  /  /  O
 \/ \/ \/
If N is 4, the output is:

 /\ /\ /\ /\
O  /  /  /  O
 \/ \/ \/ \/
The pattern continues in the exact same way for larger N. Note that forward slash (/) must be used in all places the helixes cross, except for the O ends.

If N is negative, this vertical ASCII art double helix, drawn -N segments tall, must be printed.

If N is -1, the output is:

 O
/ \
\ /
 O
If N is -2, the output is:

 O
/ \
\ /
 \
/ \
\ /
 O
If N is -3, the output is:

 O
/ \
\ /
 \
/ \
\ /
 \
/ \
\ /
 O
If N is -4, the output is:

 O
/ \
\ /
 \
/ \
\ /
 \
/ \
\ /
 \
/ \
\ /
 O
The pattern continues in the exact same way for smaller N. Note that backward slashes (\) must be used in all places the helixes cross, except for the O ends.

Details

Instead of a program, you may write a function that takes N as an integer and prints the result normally or returns it as a string.
The output for any N may optionally contain a trailing newline.
Any line of output for any N may optionally contain 4 or fewer trailing spaces.
There should never be any leading space that aren't part of the specified pattern.
The shortest code in bytes wins.

*/

#include <stdio.h>
#include <stdlib.h>

void
horizontal(int n)
{
	static const char art[][4] = {
	    " /\\",
	    "  /",
	    " \\/",
	};

	int x, w;

	w = (3 * n) + 1;
	for (x = 0; x < w; x++)
		putchar(art[0][x % 3]);
	puts("");

	printf("O");
	for (x = 0; x < w - 2; x++)
		putchar(art[1][x % 3]);
	puts("O");

	for (x = 0; x < w; x++)
		putchar(art[2][x % 3]);
	puts("");
}

void
vertical(int n)
{
	static const char art[][4] = {
	    "/ \\",
	    "\\ /",
	    " \\ ",
	};

	int y, h;

	h = (3 * abs(n)) + 1;
	puts(" O ");
	for (y = 0; y < h - 2; y++)
		puts(art[y % 3]);
	puts(" O ");
}

void
helix(int n)
{
	printf("n=%d\n", n);
	if (n == 0)
		puts("O");
	else if (n > 0)
		horizontal(n);
	else
		vertical(n);
	puts("");
}

int
main(void)
{
	int i;

	for (i = -4; i <= 4; i++)
		helix(i);

	return 0;
}
