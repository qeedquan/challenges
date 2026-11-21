/*

Let us now learn to copy a line of characters from input to output with Brainfuck. This is very simple except one issue:

BF language has no official way to determine the end of input (it is implementation dependent).
Since so your goal would be to:

Copy the first line of input and ignore the remaining.

The lines are separated with newline invisible character which has ASCII number of 10. That means you should enter characters with ',' command and print them with '.' until you met one which after reading in leaves value 10 in the current cell.

You may use stack operands # and $ for this problem.

Input will have a pair of sample text lines.
Answer should be a copy of the first line.

Example:

input:
first line
second line

answer:
first line
Note that sample input and answer to it are ignored while checking your solution. Instead it would be run against some random input to verify your logic.

*/

#include <stdio.h>

void
copyline(FILE *in, FILE *out)
{
	int c;

	for (;;) {
		c = fgetc(in);
		if (c == EOF)
			return;

		fputc(c, out);
		if (c == '\n')
			break;
	}

	while ((c = fgetc(in)) != EOF)
		;
}

int
main()
{
	copyline(stdin, stdout);
	return 0;
}
