/*

The program takes a single line of text as input, such as True.
Your task is to output this text once on the first line, twice on the second line, and three times on the third line.
Each repetition on a line should be separated by a space.

Input
A single line of text containing only Latin letters.

Output
The required pattern as described.

Examples

Input #1
True

Answer #1
True
True True
True True True

*/

#include <stdio.h>

void
solve(const char *s)
{
	int x, y;

	for (y = 1; y <= 3; y++) {
		for (x = 0; x < y; x++)
			printf("%s ", s);
		puts("");
	}
}

int
main()
{
	solve("True");
	return 0;
}
