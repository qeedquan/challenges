/*

For golfing practice, I have been doing the assignments in my girlfriend's Intro to Python class. I found that for this assignment, there were multiple strategies that came very close in character count, and I'm sure people here can find even better ways. Although I am most interested in ways to do this in Python, I would like to know the most golfed this program can get, therefore this is code golf and shortest answer wins.

The Rules:
The assignment is outlined below. The user should be asked to input twice, although the prompts don't have to say anything, and can be in a different order.

Standard loopholes apply.

Assignment 3: Arrows
Write a program that prompts the user for a number of columns, and them prints the pattern as seen below. You can assume that the user will supply positive numbers. Your program should handle both left and right arrows. Here are a few sample runnings:

How many columns? 3
Direction? (l)eft or (r)ight: r
*
 *
  *
 *
*
How many columns? 5
Direction? (l)eft or (r)ight: l
    *
   *
  *
 *
*
 *
  *
   *
    *

*/

#include <stdio.h>

void
line(int i0, int i1, int di)
{
	int i, j;

	for (i = i0; i != i1; i += di) {
		for (j = 0; j < i; j++)
			putchar(' ');
		puts("*");
	}
}

void
arrows(int n, int d)
{
	printf("(%d, %c)\n", n, d);
	if (n < 1)
		return;

	if (d == 'r') {
		line(0, n, 1);
		line(n - 2, -1, -1);
	} else if (d == 'l') {
		line(n - 1, -1, -1);
		line(1, n, 1);
	}
}

int
main(void)
{
	arrows(3, 'r');
	arrows(5, 'l');
	arrows(15, 'l');
	arrows(20, 'r');

	return 0;
}
