/*

My apologies for the wordiness. We had fun with it at work in our internal golfing, but it required a few emails for clarification, so I hope I captured most of that the first time.

PROBLEM
Given a “simulated” snowfall snapshot (as a string, stdin or parameter to your function/method), report on 4 values: minimum depth, maximum depth, average depth, and duration.

Here’s a formatted example to illustrate the input:

* * **
** * ***
** *  *
*
--------
The ‘*’ is a snowflake and the ‘-‘ is the ground. Imagine all of those “snowflakes” falling toward the ground. This is the final “snapshot”:

*
*
** * **
********
--------
You need to report on:

Minimum depth - count the shortest “pile” (1, in example above)
Maximum depth - count the tallest “pile” (4, in example above)
Average depth - average count of all “piles” (1.9, in example above - rounding to tenths)
Duration - (each “fall” = 1 second) - time from the first snapshot to the last snapshot (3 seconds, in example above)
Another example for reference:

     *
   *   *
      *
*
--------
Final snapshot:

*  * ***
--------
INPUT
The starting “snapshot” will have 8 “rows”, 8 “columns”, and be pipe-delimited (the pipes separate the rows). For example (excluding quotes):

“        |        |        |        |     *  |   *   *|      * |*       |--------”
OUTPUT
The 4 values pipe-delimited on a single line: 0|1|.6|3 or 0|5|1|1

*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
snow(const char *s)
{
	int a, b, c, d;
	int f, i, j, x;

	a = 0;
	b = 8;
	c = 0;
	d = 0;
	for (i = 0; i < 8; i++) {
		f = x = 0;
		for (j = 0; j < 8; j++) {
			if (s[i + (9 * j)] == '*') {
				if (x < 1)
					x = 8 - j;
				f += 1;
			}
		}
		d += f;
		a = max(a, f);
		b = min(b, f);
		c = max(c, x - f);
	}

	printf("%d|%d|%.1f|%d\n", b, a, d / 8.0, c);
}

int
main()
{
	snow("        |        |        |        |     *  |   *   *|      * |*       |--------");
	return 0;
}
