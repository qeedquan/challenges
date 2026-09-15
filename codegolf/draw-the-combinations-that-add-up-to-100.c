/*

You have a box with a single digit number in each corner:

1|2
---
3|4
If we concatenate the digits along rows left to right, we get 12 and 34. If we concatenate the digits along columns top to bottom, we get 13 and 24. If we add all of these numbers, we get 12+34+13+24 = 83.

Challenge
Write a program to print all such boxes where the sum calculated as above is equal to 100.

Assuming each corner contains a single digit number between 1 and 9, there are 9 combinations: 1157, 1247, 1337, 1427, 1517, 2138, 2228, 2318, and 3119. (Note that there are 25 combinations if we include 0, but we're not for this challenge.)

Note that the example 1234 doesn't work since 12+34+13+24 does not equal 100.

Input
None

Output
Answer boxes in the following format:

A|B
---
C|D
Output should be printed to STDOUT or closest alternative.

Rules
AB + CD + AC + BD = 100
Each corner will contain the positive integers 1-9 only.
0 is excluded.

Numbers can be used more than once.
You need to draw the boxes, as above. (A|B\n---\nC|D\n)
You need to output all valid answers.
An additional trailing newline is fine.
code-golf, so shortest code in bytes wins.
Standard loopholes and T&C's apply.
This is my first submission so please do let me know if I need to clarify anything.

*/

#include <stdio.h>

void
solve(int n)
{
	int a, b, c, d;
	int x, y, z, w;

	for (a = 1; a <= 9; a++) {
		for (b = 1; b <= 9; b++) {
			for (c = 1; c <= 9; c++) {
				for (d = 1; d <= 9; d++) {
					x = (a * 10) + b;
					y = (c * 10) + d;
					z = (a * 10) + c;
					w = (b * 10) + d;
					if (x + y + z + w != n)
						continue;

					printf("%d|%d\n", a, b);
					printf("---\n");
					printf("%d|%d\n", c, d);
					printf("\n");
				}
			}
		}
	}
}

int
main(void)
{
	solve(100);
	return 0;
}
