/*

Given a string, print the string itself and its length.

Input
The input contains a single string consisting of at most 100 characters.

Output
On the first line, print the input string. On the second line, print its length.

Examples

Input #1
Programming Principles 1

Answer #1
Programming Principles 1
24

Input #2
This is a cat.

Answer #2
This is a cat.
14

*/

#include <stdio.h>
#include <string.h>

void
solve(const char *s)
{
	printf("%s\n", s);
	printf("%zu\n", strlen(s));
}

int
main()
{
	solve("Programming Principles 1");
	solve("This is a cat.");

	return 0;
}
