/*

Write a program that takes in (via STDIN/command line) a non-negative integer N.

When N is 0, your program should print O (that's capital Oh, not zero).

When N is 1, your program should print

\|/
-O-
/|\
When N is 2 your program should print

\ | /
 \|/
--O--
 /|\
/ | \
When N is 3 your program should print

\  |  /
 \ | /
  \|/
---O---
  /|\
 / | \
/  |  \

For larger N, this pattern continues on in the same exact fashion. Each of the eight rays of the "sun" should be made of N of the appropriate -, |, /, or \ characters.

Details
Instead of a program, you may write a function that takes an integer. The function should print the sun design normally or return it as a string.

You must either have no trailing spaces at all, or only have enough trailing spaces so the pattern is a perfect (2N+1)*(2N+1) rectangle.
The output for any or all N may optionally have a trailing newline.

Scoring
The shortest code in bytes wins.

*/

#include <stdio.h>

void
sun(int n)
{
	int s, h;
	int x, y;

	s = (2 * n) + 1;
	h = s / 2;
	printf("n=%d\n", n);
	for (y = 0; y < s; y++) {
		for (x = 0; x < s; x++) {
			if (x == y && x == h)
				printf("O");
			else if (x == h)
				printf("|");
			else if (y == h)
				printf("-");
			else if (x == y)
				printf("\\");
			else if (x == s - y - 1)
				printf("/");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 0; i <= 5; i++)
		sun(i);
	return 0;
}
