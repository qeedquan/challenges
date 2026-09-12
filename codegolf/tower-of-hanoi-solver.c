/*

For reference as to what the tower of Hanoi is, either Google it or look on the Wikipedia page.

Your code should be able to do 2 things, and they are the following:

Accept user input that specifies the number of discs at the starting point of the Hanoi tower
Create output in a fashion of your choosing (so long as it is somehow logical) to show the solution to the tower puzzle.
An example of logical output would be the following (using a 4 disc start):

L1L2C1L1R-2R-1L1L2C1C-1R-2C1L1L2C1

L represents the left peg, C represents the center peg and R represents the right peg and the numbers are how far to move the disk on that peg and in what direction. Positive numbers represent the number of pegs moving towards the rightmost peg (because the disks start on the leftmost peg).

The rules to tower of Hanoi are simple:

Only one disk may be moved at a time.
Each move consists of taking the upper disk from one of the pegs and sliding it onto another peg, on top of the other disks that may already be present on that peg.
No disk may be placed on top of a smaller disk.
The disks start on the leftmost peg, largest on the bottom, smallest on the top, naturally.

*/

#include <stdio.h>

void
recurse(int n, int a, int b)
{
	if (n < 1)
		return;

	recurse(n - 1, a, 6 - a - b);
	printf("move(disk=%d, from=%d, to=%d)\n", n, a, b);
	recurse(n - 1, 6 - a - b, b);
}

void
hanoi(int n)
{
	printf("n=%d\n", n);
	recurse(n, 1, 3);
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 0; i <= 5; i++)
		hanoi(i);
	return 0;
}
