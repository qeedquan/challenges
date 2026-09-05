/*

Your task is to generate boxes using any one ASCII character with respect to the inputs given.

Test Cases
1 1   --> =====
          =   =
          =====

1 2   --> =========
          =   =   =
          =========

2 1   --> =====
          =   =
          =====
          =   =
          =====

2 2   --> =========
          =   =   =
          =========
          =   =   =
          =========

2 5   --> =====================
          =   =   =   =   =   =
          =====================
          =   =   =   =   =   =
          =====================
Input
Input can be taken from one of the following

stdin
Command-line arguments
Function arguments (2 arguments, one for each number)
Input, if taken from stdin or command line arguments, will contain two positive integers, seperated by a space.

The two numbers denote the number of boxes in each column and row

Output
Boxes must be outputted in stdout (or closest equivalent)
Each box should have three horizontal spaces in them

Rules
Both the numbers will be greater than 0, but will not go beyond 1000
Any visible character can be used for outputting the boxes. (as long as they aren't too harsh on the eye!)
You are permitted to write a full program or a function.
There should be no unnecessary characters except an optional trailing newline character.

Scoring
This is code-golf, so the shortest submission (in bytes) wins.

*/

#include <stdio.h>

void
box(int h, int w)
{
	int x, y;

	printf("h=%d w=%d\n", h, w);
	for (y = 0; y <= h * 2; y++) {
		for (x = 0; x <= w * 4; x++) {
			if ((x & 3) && (y & 1))
				putchar(' ');
			else
				putchar('=');
		}
		puts("");
	}
	puts("");
}

int
main(void)
{
	box(1, 1);
	box(1, 2);
	box(2, 1);
	box(2, 2);
	box(2, 5);

	return 0;
}
