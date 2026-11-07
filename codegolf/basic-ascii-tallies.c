/*

Given a number n, output tallies grouped into the traditional 5-per-group and 50 per row.

Examples
1

|
|
|
|

4

||||
||||
||||
||||

5

|||/
||/|
|/||
/|||

6

|||/ |
||/| |
|/|| |
/||| |

50

|||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/
||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/|
|/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/||
/||| /||| /||| /||| /||| /||| /||| /||| /||| /|||

51

|||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/
||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/|
|/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/||
/||| /||| /||| /||| /||| /||| /||| /||| /||| /|||

|
|
|
|

256

|||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/
||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/|
|/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/||
/||| /||| /||| /||| /||| /||| /||| /||| /||| /|||

|||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/
||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/|
|/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/||
/||| /||| /||| /||| /||| /||| /||| /||| /||| /|||

|||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/
||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/|
|/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/||
/||| /||| /||| /||| /||| /||| /||| /||| /||| /|||

|||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/
||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/|
|/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/||
/||| /||| /||| /||| /||| /||| /||| /||| /||| /|||

|||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/ |||/
||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/| ||/|
|/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/|| |/||
/||| /||| /||| /||| /||| /||| /||| /||| /||| /|||

|||/ |
||/| |
|/|| |
/||| |

Rules
5 tallies per group, 50 total tallies per row.
The first 4 tallies are vertical, the 5th tally crosses all other tallies.
Each of the first four consist of 4 vertical | characters.
The final 5th tally spans all 4 of the first, with a / character, diagonally.
Each group should be separated by a space, each row a blank newline.
The constraints on n are: 0 <= n <= 1000 (for simplicity).
Trailing spaces and newlines are fine, preceding are not.
This is code-golfascii-art, lowest byte-count wins.
Reviewed by ~4 people in the sandbox.

P.S. fun little tid-bit, the average number of tallies per row in prison was 50, hence the alt. title.

*/

#include <stdio.h>

void
mark(int n)
{
	static const char sym[][6] = {
	    "|||/ ",
	    "||/| ",
	    "|/|| ",
	    "/||| ",
	    "",
	};

	int x, y;

	if (n < 1)
		return;

	for (y = 0; y < 5; y++) {
		for (x = n; x > 4; x -= 5)
			printf("%s", sym[y]);
		for (; x != 0 && y - 4 != 0; x--)
			putchar('|');
		putchar('\n');
	}
}

void
tallies(int n)
{
	printf("n=%d\n", n);
	for (; n > 49; n -= 50)
		mark(50);
	mark(n);
}

int
main(void)
{
	tallies(1);
	tallies(4);
	tallies(5);
	tallies(6);
	tallies(50);
	tallies(51);
	tallies(256);

	return 0;
}
