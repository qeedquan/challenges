/*

We once made a Hexagony template without actually knowing it.
But after a bit of experience with Hexagony, it becomes apparent that it is not enough;
sometimes the source code is too short for the given hexagon, and you get totally unexpected results.

So I came up with an idea: a template that gives a hint when the code is too short.

For the background: Hexagony detects the smallest hexagonal grid that fits the source code,
and then fills each spot in the grid with each char in row-by-row fashion. E.g. the code

abcdefg@
contains 8 characters, and the smallest grid that can fit this is of size 3 (size 2 grid has only 7 spots)

  . . .
 . . . .
. . . . .
 . . . .
  . . .
so the code above is laid out like this:

  a b c
 d e f g
@ . . . .
 . . . .
  . . .
Now, to ensure that the code being written is actually laid out on the hexagon of size 3, the programmer has to make sure that the code has at least 8 characters; in other words, at least one of the spots marked * must be occupied by a command:

  . . .
 . . . .
* * * * *
 * * * *
  * * *

Math note: the number of spots in the hexagonal grid of size  n≥1 is a(n)=3n(n−1)+1 (A003215).
Since the Hexagony interpreter only has hexagon sizes of 1 and higher, a(0) is undefined for this challenge.

Task
Given a positive integer n, draw a hexagonal grid like the one above so that
the first a(n−1) spots are drawn with one kind of marker (e.g. .) and
the rest are drawn with another (e.g. *).
For n=1, it is allowed to output any of the two possible grids (single . or single *).

For output format:

You can choose the two markers, but the two must be distinct and not a whitespace character.
Extra leading and trailing whitespaces, and whitespaces at the end of each line are allowed,
as long as it doesn't break the hexagonal layout.
Outputting as a list of strings (lines) is OK.
Standard code-golf rules apply. Shortest code in bytes wins.

Test cases
n=1
*
or
.

n=2
 . *
* * *
 * *

n=3
  . . .
 . . . .
* * * * *
 * * * *
  * * *

n=4
   . . . .
  . . . . .
 . . . . . .
. . . . * * *
 * * * * * *
  * * * * *
   * * * *

n=5
    . . . . .
   . . . . . .
  . . . . . . .
 . . . . . . . .
. . . . . . . . .
 . . * * * * * *
  * * * * * * *
   * * * * * *
    * * * * *

*/

#include <stdio.h>
#include <stdlib.h>

void
hexagon(int n)
{
	int a, i, j, m;

	printf("n=%d\n", n);
	if (n < 1) {
		printf("\n");
		return;
	}

	a = 3 * (n - 1) * (n - 2) + 1;
	m = (2 * n) - 1;
	for (; m > 0; m--) {
		j = abs(n - m);
		for (i = 0; i < j; i++)
			printf(" ");
		for (i = 0; i < (2 * n) - (j + 1); i++) {
			if (a > 0) {
				printf(". ");
				a -= 1;
			} else
				printf("* ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 1; i <= 5; i++)
		hexagon(i);
	return 0;
}
