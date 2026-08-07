/*

The program takes a single line of text as input, such as Word. Your task is to output this text formatted as four list items, each preceded by the marker "-", as demonstrated in the example.

Input
A single line of text containing only Latin letters.

Output
The formatted solution to the problem.

Examples

Input #1
Word

Answer #1
- Word
- Word
- Word
- Word

*/

#include <stdio.h>

void
solve(const char *text)
{
	int index;

	for (index = 0; index < 4; index++)
		printf("- %s\n", text);
}

int
main()
{
	solve("Word");
	return 0;
}
