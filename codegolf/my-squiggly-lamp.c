/*

While moving, I broke my lamp. Now, I need a new one. It's your job to make me a lamp! I'm not sure what size I want, though I know I want a squiggly one.

Your program/function must take in a number input, and print out a lamp with that many squiggles/bumps.

Examples:

Input:2

Output:

/--\
 ()
 ()
/__\
Input:3

Output:

/--\
 ()
 ()
 ()
/__\
Input:5

Output:

/--\
 ()
 ()
 ()
 ()
 ()
/__\

Rules:

0 & negative numbers don't matter
To give the lamps (an this challenge) more of a variety, you must change the lamp shade.
They must be 4 characters wide and 1 character high.
They can be in any shape, including non-lamp-shade shapes.
They must not contain whitespace.
The base must stay the same.
You must show an example input & output with your lamp shade.
Shortest code wins!

*/

#include <stdio.h>

void
lamp(int n)
{
	int i;

	printf("/--\\\n");
	for (i = 0; i < n; i++)
		printf(" ()\n");
	printf("/__\\\n");
	printf("\n");
}

int
main(void)
{
	lamp(2);
	lamp(3);
	lamp(5);

	return 0;
}
