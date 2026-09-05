/*

In as few Unicode characters as possible, print the following (144 characters):

1, 2, 3 o'clock, 4 o'clock rock,
5, 6, 7 o'clock, 8 o'clock rock,
9, 10, 11 o'clock, 12 o'clock rock,
We're gonna rock around the clock tonight.
You must not use any numbers in your code, except the digit 1.

*/

#include <stdio.h>

void
rock(void)
{
	printf("1, 2, 3 o'clock, 4 o'clock rock,\n");
	printf("5, 6, 7 o'clock, 8 o'clock rock,\n");
	printf("9, 10, 11 o'clock, 12 o'clock rock,\n");
	printf("We're gonna rock around the clock tonight.\n");
}

int
main(void)
{
	rock();
	return 0;
}
